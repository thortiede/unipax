#include <UNIPAX/IMPORT/BIOPAX/BIOPAXReader.h>
#include <UNIPAX/IMPORT/BIOPAX/BIOPAXWriter.h>

#include<UNIPAX/KERNEL/EXT/ImportSource.h>

#ifdef ODB_MYSQL
#include <UNIPAX/PERSISTENCE/MYSQL/MySQLManager.h>
#elif defined ODB_ORACLE
#include <UNIPAX/PERSISTENCE/ORACLE/OracleManager.h>
#endif


#include <boost/program_options.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <iostream>

int main(int argC, char** argV)
{
	boost::program_options::options_description desc("Allowed options");
	bool debug = false;
	std::string input_file, data_source, data_version;
	std::string db_host, db_name, db_user, db_passw, output_file, id, service_name;
	int db_port;
	desc.add_options()
		("help,h", "produce help message")
		("debug,d", "use debug modus. Prints out debug information during parse.")
		("strict,s", "use strict modus. Will exit on data inconsistency.")
		("input-file,i", boost::program_options::value< std::string >(&input_file), "BioPAX input file to parse")
//		("output-file,o", boost::program_options::value< std::string >(&output_file), "output file to write to") // for output
//		("id,i", boost::program_options::value< std::string >(&id), "object id for data retrieval") // for output
		("data-source,D", boost::program_options::value< std::string >(&data_source)->default_value(input_file), "name of the data source")
		("data-version,V", boost::program_options::value< std::string >(&data_version)->default_value(boost::posix_time::to_iso_extended_string(boost::posix_time::microsec_clock::universal_time())), "version of the data source")
		("db-host,H", boost::program_options::value< std::string >(&db_host)->default_value("localhost"), "host of the database server")
		("db-user,U", boost::program_options::value< std::string >(&db_user)->default_value("unipax"), "user name for the connection to the UniPAX database")
		("db-passw,p", boost::program_options::value< std::string >(&db_passw)->default_value("unipax"), "password of the UniPAX database")

#ifdef ODB_MYSQL
		("db-name,N", boost::program_options::value< std::string >(&db_name)->default_value("unipax"), "name of the UniPAX database")
		("db-port,P", boost::program_options::value< int >(&db_port)->default_value(3306), "port of the database server")
#elif defined ODB_ORACLE
		("db-sid,S", boost::program_options::value< std::string >(&db_name)->default_value(""), "SID of the UniPAX database")
		("db-service-name,s", boost::program_options::value< std::string >(&service_name)->default_value(""), "Service name of the UniPAX database, if different from SID")
		("db-port,P", boost::program_options::value< int >(&db_port)->default_value(1521), "port of the database server")
#endif

	;
	boost::program_options::positional_options_description pod;
	pod.add("input-file", -1);
//	pod.add("output-file", -1); // for output
	boost::program_options::variables_map vm;
	boost::program_options::store(boost::program_options::command_line_parser(argC, argV).options(desc).positional(pod).run(), vm);
	boost::program_options::notify(vm);
	if (argC == 1 || vm.count("help"))
	{
		std::cout << desc << std::endl;
		return 0;
	}
	if (vm.count("debug"))
	{
		debug = true;
		std::cout << "Debug output activated." << std::endl;
	}
	/*for (std::vector<std::string>::const_iterator it = input_files.begin(); it != input_files.end(); it++)
	{
		std::cout << "BioPAX files to parse: " << *it << "\n";
	}*/
	if (db_passw.empty())
	{
		std::cout << "Enter password for database: ";
		std::cin >> db_passw;
	}
	UniPAX::BIOPAXReader reader;
	reader.setDebug(debug);
	reader.setErrorOnInconsistentData(vm.count("strict"));
	{
		reader.createObjectsOnly(true);
		reader.setFilename(input_file);
		reader.parse();

		std::cout << "Number of parsed objects (first round): " << reader.getData().size() << std::endl;

		reader.createObjectsOnly(false);
		reader.parse();

		std::cout << "Number of parsed objects: " << reader.getData().size() << std::endl;

		// now create ImportSource object from input
		UniPAX::ImportSourcePtr is(new UniPAX::ImportSource);
		is->setName(data_source);
		is->setVersion(data_version);
		if (!reader.getPersistenceManager().assignImportSource(is))
		{
			std::cerr << "Could not assign ImportSource info to parsed data. Aborting ..." << std::endl;
			return 1;
		}
	
//	std::cout << std::endl << std::endl;
//	std::map<std::string, void*>::iterator m;
//	std::map<std::string, std::string>::iterator type_search;
//	std::map<std::string, void*> data = reader.getPersistenceManager().getData();
//	std::map<std::string, std::string> types = reader.getPersistenceManager().getIdToType();
//
//	for (m = data.begin(); m != data.end(); m++)
//	{
//		type_search = types.find(m->first);
//		if (type_search != types.end())
//		{
//			std::cout << type_search->second << " - " << type_search->first << " : " << m->second << std::endl;
//		}
//		else
//		{
//			std::cout << "type unknown - " << m->first << " : " << m->second << std::endl;
//
//		}
//	}
//	std::cout << std::endl;

#ifdef ODB_MYSQL
		std::cout << "start mysql persistence" << std::endl;
		UniPAX::mysql::MySQLManager db;
#elif defined ODB_ORACLE
		std::cout << "start oracle persistence" << std::endl;
		UniPAX::oracle::OracleManager db;
		// in the case of different service name and SID
		if (!service_name.empty())
		{
			db.setServiceName(service_name);
		}
#endif
		db.setDBCredentials(db_user, db_passw, db_host, db_port, db_name);
		db.persist(reader.getPersistenceManager());
		std::cout << "finished !" << std::endl;
	}

/*	UniPAX::BIOPAXWriter writer; // for output
	writer.setDebug(true);
	writer.setExportType(UniPAX::BIOPAXWriter::INTEGRATIVE_EXPORT);
//	writer.setExportType(UniPAX::BIOPAXWriter::SERIAL_EXPORT);
//	writer.setPersistenceManager(reader.getPersistenceManager());
	UniPAX::MySQLManager db;
	db.setDBCredentials(db_user, db_passw, db_host, db_port, db_name);
	UniPAX::KernelCollector manager;
	manager.collect(db.getObjectByID("Pathway", boost::lexical_cast<int>(id)));
	writer.setPersistenceManager(manager);
	writer.write(output_file);*/

	return 0;
}
