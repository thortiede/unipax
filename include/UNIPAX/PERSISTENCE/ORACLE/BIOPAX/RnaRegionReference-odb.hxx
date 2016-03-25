// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef RNA_REGION_REFERENCE_ODB_HXX
#define RNA_REGION_REFERENCE_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 10800UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 1080000 // 1.8.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
//
// End prologue.

#include <UNIPAX/KERNEL/BIOPAX/RnaRegionReference.h>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/BioSource-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/CellVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/ControlledVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Entity-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/EntityFeature-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/EntityReference-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/EntityReferenceTypeVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Evidence-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/EvidenceCodeVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/ExperimentalForm-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/ExperimentalFormVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Provenance-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Score-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/SequenceLocation-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/SequenceRegionVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Thing-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/TissueVocabulary-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/UtilityClass-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Xref-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/EXT/ImportSource-odb.hxx>

#include <UNIPAX/PERSISTENCE/ORACLE/EXT/UPBase-odb.hxx>

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#ifdef BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <odb/tr1/wrapper-traits.hxx>
#  include <odb/tr1/pointer-traits.hxx>
#endif
#include <odb/container-traits.hxx>
#include <odb/result.hxx>

#include <odb/details/buffer.hxx>
#include <odb/details/unused.hxx>

#include <odb/oracle/version.hxx>
#include <odb/oracle/forward.hxx>
#include <odb/oracle/oracle-types.hxx>
#include <odb/oracle/query.hxx>

namespace odb
{
  // RnaRegionReference
  //
  template <>
  struct class_traits< ::UniPAX::RnaRegionReference >
  {
    static const class_kind kind = class_object;
  };

  template <const char* table>
  struct pointer_query_columns< ::UniPAX::RnaRegionReference, table >: pointer_query_columns< ::UniPAX::EntityReference, table >
  {
    // EntityReference
    //
    typedef pointer_query_columns< ::UniPAX::EntityReference, table > EntityReference;

    // sequence
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::std::string,
        oracle::id_string >::query_type,
      oracle::id_string >
    sequence_type_;

    static const sequence_type_ sequence;

    // id_subRegion
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    id_subRegion_type_;

    static const id_subRegion_type_ id_subRegion;

    // id_absoluteRegion
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    id_absoluteRegion_type_;

    static const id_absoluteRegion_type_ id_absoluteRegion;

    // organism
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    organism_type_;

    static const organism_type_ organism;

    // regionType
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    regionType_type_;

    static const regionType_type_ regionType;
  };

  template <const char* table>
  const typename pointer_query_columns< ::UniPAX::RnaRegionReference, table >::sequence_type_
  pointer_query_columns< ::UniPAX::RnaRegionReference, table >::sequence (table, "\"sequence\"", 512);

  template <const char* table>
  const typename pointer_query_columns< ::UniPAX::RnaRegionReference, table >::id_subRegion_type_
  pointer_query_columns< ::UniPAX::RnaRegionReference, table >::id_subRegion (table, "\"id_subRegion\"", 20);

  template <const char* table>
  const typename pointer_query_columns< ::UniPAX::RnaRegionReference, table >::id_absoluteRegion_type_
  pointer_query_columns< ::UniPAX::RnaRegionReference, table >::id_absoluteRegion (table, "\"id_absoluteRegion\"", 20);

  template <const char* table>
  const typename pointer_query_columns< ::UniPAX::RnaRegionReference, table >::organism_type_
  pointer_query_columns< ::UniPAX::RnaRegionReference, table >::organism (table, "\"organism\"", 20);

  template <const char* table>
  const typename pointer_query_columns< ::UniPAX::RnaRegionReference, table >::regionType_type_
  pointer_query_columns< ::UniPAX::RnaRegionReference, table >::regionType (table, "\"regionType\"", 20);

  template <>
  class access::object_traits< ::UniPAX::RnaRegionReference >
  {
    public:
    typedef ::UniPAX::RnaRegionReference object_type;
    typedef ::boost::shared_ptr< ::UniPAX::RnaRegionReference > pointer_type;
    typedef object_traits< ::UniPAX::UPBase >::id_type id_type;

    static const bool auto_id = object_traits< ::UniPAX::UPBase >::auto_id;

    typedef object_traits< ::UniPAX::UPBase >::id_image_type id_image_type;

    struct image_type: object_traits< ::UniPAX::EntityReference >::image_type
    {
      // sequence
      //
      char sequence_value[512];
      ub2 sequence_size;
      sb2 sequence_indicator;

      // id_subRegion
      //
      char id_subRegion_value[12];
      ub2 id_subRegion_size;
      sb2 id_subRegion_indicator;

      // id_absoluteRegion
      //
      char id_absoluteRegion_value[12];
      ub2 id_absoluteRegion_size;
      sb2 id_absoluteRegion_indicator;

      // organism
      //
      char organism_value[12];
      ub2 organism_size;
      sb2 organism_indicator;

      // regionType
      //
      char regionType_value[12];
      ub2 regionType_size;
      sb2 regionType_indicator;

      std::size_t version;

      oracle::change_callback change_callback_;

      oracle::change_callback*
      change_callback ()
      {
        return &change_callback_;
      }
    };

    // comment
    //
    struct comment_traits: access::object_traits< ::UniPAX::UtilityClass >::comment_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t cond_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const char insert_one_statement[];
      static const char select_all_statement[];
      static const char delete_all_statement[];
    };

    // id_memberEntityReferences
    //
    struct id_memberEntityReferences_traits: access::object_traits< ::UniPAX::EntityReference >::id_memberEntityReferences_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t cond_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const char insert_one_statement[];
      static const char select_all_statement[];
      static const char delete_all_statement[];
    };

    // evidence
    //
    struct evidence_traits: access::object_traits< ::UniPAX::EntityReference >::evidence_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t cond_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const char insert_one_statement[];
      static const char select_all_statement[];
      static const char delete_all_statement[];
    };

    // id_xref
    //
    struct id_xref_traits: access::object_traits< ::UniPAX::EntityReference >::id_xref_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t cond_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const char insert_one_statement[];
      static const char select_all_statement[];
      static const char delete_all_statement[];
    };

    // name
    //
    struct name_traits: access::object_traits< ::UniPAX::EntityReference >::name_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t cond_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const char insert_one_statement[];
      static const char select_all_statement[];
      static const char delete_all_statement[];
    };

    static id_type
    id (const object_type&);

    static id_type
    id (const image_type&);

    static void
    bind (oracle::bind*, image_type&, oracle::statement_kind);

    static void
    bind (oracle::bind*, id_image_type&);

    static bool
    init (image_type&, const object_type&, oracle::statement_kind);

    static void
    init (object_type&, const image_type&, database&);

    static void
    init (id_image_type&, const id_type&);

    typedef oracle::query query_base_type;

    struct query_type;
    struct container_statement_cache_type;

    static const std::size_t column_count = 11UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (oracle::object_statements< object_type >&, const id_type&);

    static void
    load_ (oracle::object_statements< object_type >&, object_type&);
  };

  // RnaRegionReference
  //
  template <>
  struct query_columns_base< ::UniPAX::RnaRegionReference >
  {
    // organism
    //
    static const char organism_alias_[];

    // regionType
    //
    static const char regionType_alias_[];
  };

  template <const char* table>
  struct query_columns< ::UniPAX::RnaRegionReference, table >:
    query_columns_base< ::UniPAX::RnaRegionReference >,
    query_columns< ::UniPAX::EntityReference, table >
  {
    // EntityReference
    //
    typedef query_columns< ::UniPAX::EntityReference, table > EntityReference;

    // sequence
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        ::std::string,
        oracle::id_string >::query_type,
      oracle::id_string >
    sequence_type_;

    static const sequence_type_ sequence;

    // id_subRegion
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    id_subRegion_type_;

    static const id_subRegion_type_ id_subRegion;

    // id_absoluteRegion
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    id_absoluteRegion_type_;

    static const id_absoluteRegion_type_ id_absoluteRegion;

    // organism
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    organism_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::BioSource,
        organism_alias_ > >
    organism_pointer_type_;

    struct organism_type_: organism_pointer_type_, organism_column_type_
    {
      organism_type_ (const char* t,
                      const char* c,
                      unsigned short p = 0xFFF,
                      short s = 0xFFF)
        : organism_column_type_ (t, c, p, s)
      {
      }
    };

    static const organism_type_ organism;

    // regionType
    //
    typedef
    oracle::query_column<
      oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::query_type,
      oracle::id_big_int >
    regionType_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::SequenceRegionVocabulary,
        regionType_alias_ > >
    regionType_pointer_type_;

    struct regionType_type_: regionType_pointer_type_, regionType_column_type_
    {
      regionType_type_ (const char* t,
                        const char* c,
                        unsigned short p = 0xFFF,
                        short s = 0xFFF)
        : regionType_column_type_ (t, c, p, s)
      {
      }
    };

    static const regionType_type_ regionType;
  };

  template <const char* table>
  const typename query_columns< ::UniPAX::RnaRegionReference, table >::sequence_type_
  query_columns< ::UniPAX::RnaRegionReference, table >::sequence (table, "\"sequence\"", 512);

  template <const char* table>
  const typename query_columns< ::UniPAX::RnaRegionReference, table >::id_subRegion_type_
  query_columns< ::UniPAX::RnaRegionReference, table >::id_subRegion (table, "\"id_subRegion\"", 20);

  template <const char* table>
  const typename query_columns< ::UniPAX::RnaRegionReference, table >::id_absoluteRegion_type_
  query_columns< ::UniPAX::RnaRegionReference, table >::id_absoluteRegion (table, "\"id_absoluteRegion\"", 20);

  template <const char* table>
  const typename query_columns< ::UniPAX::RnaRegionReference, table >::organism_type_
  query_columns< ::UniPAX::RnaRegionReference, table >::organism (table, "\"organism\"", 20);

  template <const char* table>
  const typename query_columns< ::UniPAX::RnaRegionReference, table >::regionType_type_
  query_columns< ::UniPAX::RnaRegionReference, table >::regionType (table, "\"regionType\"", 20);

  struct access::object_traits< ::UniPAX::RnaRegionReference >::query_type:
    query_base_type,
    query_columns< ::UniPAX::RnaRegionReference, table_name >
  {
    query_type ();
    query_type (bool);
    query_type (const char*);
    query_type (const std::string&);
    query_type (const query_base_type&);
  };
}

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/RnaRegionReference-odb.ixx>

// Begin epilogue.
//
//
// End epilogue.

#include <odb/post.hxx>

#endif // RNA_REGION_REFERENCE_ODB_HXX
