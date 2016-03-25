// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Control-odb.hxx>

#include <cassert>
#include <cstring> // std::memcpy

#include <odb/cache-traits.hxx>
#include <odb/details/shared-ptr.hxx>

#include <odb/oracle/binding.hxx>
#include <odb/oracle/traits.hxx>
#include <odb/oracle/database.hxx>
#include <odb/oracle/transaction.hxx>
#include <odb/oracle/connection.hxx>
#include <odb/oracle/statement.hxx>
#include <odb/oracle/statement-cache.hxx>
#include <odb/oracle/object-statements.hxx>
#include <odb/oracle/container-statements.hxx>
#include <odb/oracle/exceptions.hxx>
#include <odb/oracle/result.hxx>

namespace odb
{
  // Control
  //

  // comments
  //

  const char access::object_traits< ::UniPAX::Control >::comments_traits::select_all_statement[] =
  "SELECT "
  "\"Control_comments\".\"index\","
  "\"Control_comments\".\"value\""
  " FROM \"Control_comments\" WHERE \"Control_comments\".\"object_id\"=:1"
  " ORDER BY \"Control_comments\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::comments_traits::insert_one_statement[] =
  "INSERT INTO \"Control_comments\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::comments_traits::delete_all_statement[] =
  "DELETE FROM \"Control_comments\""
  " WHERE \"object_id\"=:1";

  // name
  //

  const char access::object_traits< ::UniPAX::Control >::name_traits::select_all_statement[] =
  "SELECT "
  "\"Control_name\".\"index\","
  "\"Control_name\".\"value\""
  " FROM \"Control_name\" WHERE \"Control_name\".\"object_id\"=:1"
  " ORDER BY \"Control_name\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::name_traits::insert_one_statement[] =
  "INSERT INTO \"Control_name\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::name_traits::delete_all_statement[] =
  "DELETE FROM \"Control_name\""
  " WHERE \"object_id\"=:1";

  // id_xref
  //

  const char access::object_traits< ::UniPAX::Control >::id_xref_traits::select_all_statement[] =
  "SELECT "
  "\"Control_id_xref\".\"index\","
  "\"Control_id_xref\".\"value\""
  " FROM \"Control_id_xref\" WHERE \"Control_id_xref\".\"object_id\"=:1"
  " ORDER BY \"Control_id_xref\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::id_xref_traits::insert_one_statement[] =
  "INSERT INTO \"Control_id_xref\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::id_xref_traits::delete_all_statement[] =
  "DELETE FROM \"Control_id_xref\""
  " WHERE \"object_id\"=:1";

  // id_participant
  //

  const char access::object_traits< ::UniPAX::Control >::id_participant_traits::select_all_statement[] =
  "SELECT "
  "\"Control_id_participant\".\"index\","
  "\"Control_id_participant\".\"value\""
  " FROM \"Control_id_participant\" WHERE \"Control_id_participant\".\"object_id\"=:1"
  " ORDER BY \"Control_id_participant\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::id_participant_traits::insert_one_statement[] =
  "INSERT INTO \"Control_id_participant\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::id_participant_traits::delete_all_statement[] =
  "DELETE FROM \"Control_id_participant\""
  " WHERE \"object_id\"=:1";

  // interactionType
  //

  const char access::object_traits< ::UniPAX::Control >::interactionType_traits::select_all_statement[] =
  "SELECT "
  "\"Control_interactionType\".\"index\","
  "\"Control_interactionType\".\"value\""
  " FROM \"Control_interactionType\" WHERE \"Control_interactionType\".\"object_id\"=:1"
  " ORDER BY \"Control_interactionType\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::interactionType_traits::insert_one_statement[] =
  "INSERT INTO \"Control_interactionType\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::interactionType_traits::delete_all_statement[] =
  "DELETE FROM \"Control_interactionType\""
  " WHERE \"object_id\"=:1";

  // id_controller
  //

  const char access::object_traits< ::UniPAX::Control >::id_controller_traits::select_all_statement[] =
  "SELECT "
  "\"Control_id_controller\".\"index\","
  "\"Control_id_controller\".\"value\""
  " FROM \"Control_id_controller\" WHERE \"Control_id_controller\".\"object_id\"=:1"
  " ORDER BY \"Control_id_controller\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Control >::id_controller_traits::insert_one_statement[] =
  "INSERT INTO \"Control_id_controller\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Control >::id_controller_traits::delete_all_statement[] =
  "DELETE FROM \"Control_id_controller\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  bind (oracle::bind* b,
        const oracle::bind* id,
        std::size_t id_size,
        cond_image_type& c)
  {
    ODB_POTENTIALLY_UNUSED (c);

    std::size_t n (0);

    // object_id
    //
    if (id != 0)
      std::memcpy (&b[n], id, id_size * sizeof (id[0]));
    n += id_size;
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  bind (oracle::bind* b,
        const oracle::bind* id,
        std::size_t id_size,
        data_image_type& d)
  {
    using namespace oracle;

    statement_kind sk (statement_select);
    ODB_POTENTIALLY_UNUSED (sk);

    size_t n (0);

    // object_id
    //
    if (id != 0)
      std::memcpy (&b[n], id, id_size * sizeof (id[0]));
    n += id_size;

    // index
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = d.index_value;
    b[n].capacity = static_cast<ub4> (sizeof (d.index_value));
    b[n].size = &d.index_size;
    b[n].indicator = &d.index_indicator;
    n++;

    // value
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = d.value_value;
    b[n].capacity = static_cast<ub4> (sizeof (d.value_value));
    b[n].size = &d.value_size;
    b[n].indicator = &d.value_indicator;
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  init (data_image_type& i, index_type j, const value_type& v)
  {
    using namespace oracle;

    statement_kind sk (statement_insert);
    ODB_POTENTIALLY_UNUSED (sk);

    bool grew (false);

    // index
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          index_type,
          oracle::id_big_int >::set_image (
        i.index_value,
        size,
        is_null,
        j);
      i.index_size = static_cast<ub2> (size);
      i.index_indicator = is_null ? -1 : 0;
    }

    // value
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          value_type,
          oracle::id_big_int >::set_image (
        i.value_value,
        size,
        is_null,
        v);
      i.value_size = static_cast<ub2> (size);
      i.value_indicator = is_null ? -1 : 0;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  init (index_type& j, value_type& v, const data_image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (db);

    // index
    //
    oracle::value_traits<
        index_type,
        oracle::id_big_int >::set_value (
      j,
      i.index_value,
      i.index_size,
      i.index_indicator == -1);

    // value
    //
    oracle::value_traits<
        value_type,
        oracle::id_big_int >::set_value (
      v,
      i.value_value,
      i.value_size,
      i.value_indicator == -1);
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  insert_one (index_type i, const value_type& v, void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    binding& b (sts.data_image_binding ());
    data_image_type& di (sts.data_image ());

    init (di, i, v);

    if (di.version != sts.data_image_version ())
    {
      bind (b.bind, 0, sts.id_binding ().count, di);
      sts.data_image_version (di.version);
      b.version++;
      sts.select_image_binding ().version++;
    }

    if (!sts.insert_one_statement ().execute ())
      throw object_already_persistent ();
  }

  bool access::object_traits< ::UniPAX::Control >::id_controller_traits::
  load_all (index_type& i, value_type& v, void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());
    init (i, v, di, sts.connection ().database ());

    sts.select_all_statement ().stream_result ();

    select_statement& st (sts.select_all_statement ());
    select_statement::result r (st.fetch ());
    if (r == select_statement::no_data)
    {
      st.free_result ();
      return false;
    }

    return true;
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  persist (const container_type& c,
           const oracle::binding& id,
           statements_type& sts)
  {
    using namespace oracle;

    binding& b (sts.data_image_binding ());
    if (id.version != sts.data_id_binding_version () || b.version == 0)
    {
      bind (b.bind, id.bind, id.count, sts.data_image ());
      sts.data_id_binding_version (id.version);
      b.version++;
      sts.select_image_binding ().version++;
    }

    sts.id_binding (id);
    functions_type& fs (sts.functions ());
    fs.ordered (true);
    container_traits_type::persist (c, fs);
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  load (container_type& c,
        const oracle::binding& id,
        statements_type& sts)
  {
    using namespace oracle;

    binding& db (sts.data_image_binding ());
    if (id.version != sts.data_id_binding_version () || db.version == 0)
    {
      bind (db.bind, id.bind, id.count, sts.data_image ());
      sts.data_id_binding_version (id.version);
      db.version++;
      sts.select_image_binding ().version++;
    }

    binding& cb (sts.cond_image_binding ());
    if (id.version != sts.cond_id_binding_version () || cb.version == 0)
    {
      bind (cb.bind, id.bind, id.count, sts.cond_image ());
      sts.cond_id_binding_version (id.version);
      cb.version++;
    }

    select_statement& st (sts.select_all_statement ());
    st.execute ();
    select_statement::result r (st.fetch ());
    bool more (r != select_statement::no_data);

    if (!more)
      st.free_result ();

    sts.id_binding (id);
    functions_type& fs (sts.functions ());
    fs.ordered (true);
    container_traits_type::load (c, more, fs);
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  update (const container_type& c,
          const oracle::binding& id,
          statements_type& sts)
  {
    using namespace oracle;

    binding& db (sts.data_image_binding ());
    if (id.version != sts.data_id_binding_version () || db.version == 0)
    {
      bind (db.bind, id.bind, id.count, sts.data_image ());
      sts.data_id_binding_version (id.version);
      db.version++;
      sts.select_image_binding ().version++;
    }

    binding& cb (sts.cond_image_binding ());
    if (id.version != sts.cond_id_binding_version () || cb.version == 0)
    {
      bind (cb.bind, id.bind, id.count, sts.cond_image ());
      sts.cond_id_binding_version (id.version);
      cb.version++;
    }

    sts.id_binding (id);
    functions_type& fs (sts.functions ());
    fs.ordered (true);
    container_traits_type::update (c, fs);
  }

  void access::object_traits< ::UniPAX::Control >::id_controller_traits::
  erase (const oracle::binding& id, statements_type& sts)
  {
    using namespace oracle;

    binding& b (sts.cond_image_binding ());
    if (id.version != sts.cond_id_binding_version () || b.version == 0)
    {
      bind (b.bind, id.bind, id.count, sts.cond_image ());
      sts.cond_id_binding_version (id.version);
      b.version++;
    }

    sts.id_binding (id);
    functions_type& fs (sts.functions ());
    fs.ordered (true);
    container_traits_type::erase (fs);
  }

  void access::object_traits< ::UniPAX::Control >::
  bind (oracle::bind* b, image_type& i, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);

    // Interaction base
    //
    object_traits< ::UniPAX::Interaction >::bind (b + n, i, sk);
    n += 7UL - (
      sk == statement_select ? 0 : (
        sk == statement_insert ? 0 : 1UL));

    // controlType
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.controlType_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.controlType_value));
    b[n].size = &i.controlType_size;
    b[n].indicator = &i.controlType_indicator;
    n++;

    // id_controlled
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.id_controlled_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.id_controlled_value));
    b[n].size = &i.id_controlled_size;
    b[n].indicator = &i.id_controlled_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::Control >::
  init (image_type& i, const object_type& o, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    bool grew (false);

    // Interaction base
    //
    if (object_traits< ::UniPAX::Interaction >::init (i, o, sk))
      grew = true;

    // controlType
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.controlType_value,
        sizeof (i.controlType_value),
        size,
        is_null,
        o.controlType);
      i.controlType_size = static_cast<ub2> (size);
      i.controlType_indicator = is_null ? -1 : 0;
    }

    // id_controlled
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          long long unsigned int,
          oracle::id_big_int >::set_image (
        i.id_controlled_value,
        size,
        is_null,
        o.id_controlled);
      i.id_controlled_size = static_cast<ub2> (size);
      i.id_controlled_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::Control >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // Interaction base
    //
    object_traits< ::UniPAX::Interaction >::init (o, i, db);

    // controlType
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.controlType,
      i.controlType_value,
      i.controlType_size,
      i.controlType_indicator == -1);

    // id_controlled
    //
    oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::set_value (
      o.id_controlled,
      i.id_controlled_value,
      i.id_controlled_size,
      i.id_controlled_indicator == -1);
  }

  struct access::object_traits< ::UniPAX::Control >::container_statement_cache_type
  {
    oracle::container_statements_impl< comments_traits > comments;
    oracle::container_statements_impl< name_traits > name;
    oracle::container_statements_impl< id_xref_traits > id_xref;
    oracle::container_statements_impl< id_participant_traits > id_participant;
    oracle::container_statements_impl< interactionType_traits > interactionType;
    oracle::container_statements_impl< id_controller_traits > id_controller;

    container_statement_cache_type (oracle::connection& c)
    : comments (c),
      name (c),
      id_xref (c),
      id_participant (c),
      interactionType (c),
      id_controller (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::Control >::persist_statement[] =
  "INSERT INTO \"Control\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"availability\","
  "\"standardName\","
  "\"displayName\","
  "\"evidence\","
  "\"dataSource\","
  "\"controlType\","
  "\"id_controlled\")"
  " VALUES (:1,:2,:3,:4,:5,:6,:7,:8,:9)";

  const char access::object_traits< ::UniPAX::Control >::find_statement[] =
  "SELECT "
  "\"Control\".\"unipaxId\","
  "\"Control\".\"unipaxSource\","
  "\"Control\".\"availability\","
  "\"Control\".\"standardName\","
  "\"Control\".\"displayName\","
  "\"Control\".\"evidence\","
  "\"Control\".\"dataSource\","
  "\"Control\".\"controlType\","
  "\"Control\".\"id_controlled\""
  " FROM \"Control\""
  " WHERE \"Control\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Control >::update_statement[] =
  "UPDATE \"Control\" SET "
  "\"unipaxSource\"=:1,"
  "\"availability\"=:2,"
  "\"standardName\"=:3,"
  "\"displayName\"=:4,"
  "\"evidence\"=:5,"
  "\"dataSource\"=:6,"
  "\"controlType\"=:7,"
  "\"id_controlled\"=:8"
  " WHERE \"unipaxId\"=:9";

  const char access::object_traits< ::UniPAX::Control >::erase_statement[] =
  "DELETE FROM \"Control\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Control >::query_statement[] =
  "SELECT "
  "\"Control\".\"unipaxId\","
  "\"Control\".\"unipaxSource\","
  "\"Control\".\"availability\","
  "\"Control\".\"standardName\","
  "\"Control\".\"displayName\","
  "\"Control\".\"evidence\","
  "\"Control\".\"dataSource\","
  "\"Control\".\"controlType\","
  "\"Control\".\"id_controlled\""
  " FROM \"Control\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"Control\".\"unipaxSource\""
  " LEFT JOIN \"Evidence\" \"evidence\" ON \"evidence\".\"unipaxId\" = \"Control\".\"evidence\""
  " LEFT JOIN \"Provenance\" \"dataSource\" ON \"dataSource\".\"unipaxId\" = \"Control\".\"dataSource\""
  " ";

  const char access::object_traits< ::UniPAX::Control >::erase_query_statement[] =
  "DELETE FROM \"Control\""
  " ";

  const char access::object_traits< ::UniPAX::Control >::table_name[] =
  "\"Control\"";

  void access::object_traits< ::UniPAX::Control >::
  persist (database&, const object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());
    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () || imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    id_image_type& i (sts.id_image ());
    init (i, obj.unipaxId);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    comments_traits::persist (
      obj.comments,
      idb,
      sts.container_statment_cache ().comments);

    name_traits::persist (
      obj.name,
      idb,
      sts.container_statment_cache ().name);

    id_xref_traits::persist (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    id_participant_traits::persist (
      obj.id_participant,
      idb,
      sts.container_statment_cache ().id_participant);

    interactionType_traits::persist (
      obj.interactionType,
      idb,
      sts.container_statment_cache ().interactionType);

    id_controller_traits::persist (
      obj.id_controller,
      idb,
      sts.container_statment_cache ().id_controller);
  }

  void access::object_traits< ::UniPAX::Control >::
  update (database&, const object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, obj.unipaxId);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () || imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.update_id_image_version () || idb.version == 0)
    {
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
      }

      sts.update_id_image_version (i.version);

      if (!u)
        imb.version++;
    }

    if (sts.update_statement ().execute () == 0)
      throw object_not_persistent ();

    comments_traits::update (
      obj.comments,
      idb,
      sts.container_statment_cache ().comments);

    name_traits::update (
      obj.name,
      idb,
      sts.container_statment_cache ().name);

    id_xref_traits::update (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    id_participant_traits::update (
      obj.id_participant,
      idb,
      sts.container_statment_cache ().id_participant);

    interactionType_traits::update (
      obj.interactionType,
      idb,
      sts.container_statment_cache ().interactionType);

    id_controller_traits::update (
      obj.id_controller,
      idb,
      sts.container_statment_cache ().id_controller);
  }

  void access::object_traits< ::UniPAX::Control >::
  erase (database&, const id_type& id)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    comments_traits::erase (
      idb,
      sts.container_statment_cache ().comments);

    name_traits::erase (
      idb,
      sts.container_statment_cache ().name);

    id_xref_traits::erase (
      idb,
      sts.container_statment_cache ().id_xref);

    id_participant_traits::erase (
      idb,
      sts.container_statment_cache ().id_participant);

    interactionType_traits::erase (
      idb,
      sts.container_statment_cache ().interactionType);

    id_controller_traits::erase (
      idb,
      sts.container_statment_cache ().id_controller);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::Control >::pointer_type
  access::object_traits< ::UniPAX::Control >::
  find (database& db, const id_type& id)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());
    object_statements< object_type >::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory< object_type, pointer_type  >::create ());
    pointer_traits< pointer_type >::guard pg (p);
    pointer_cache_traits< pointer_type >::insert_guard ig (
      pointer_cache_traits< pointer_type >::insert (db, id, p));
    object_type& obj (pointer_traits< pointer_type >::get_ref (p));

    if (l.locked ())
    {
      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), db);
      sts.find_statement ().stream_result ();
      load_ (sts, obj);
      sts.load_delayed ();
      l.unlock ();
      callback (db, obj, callback_event::post_load);
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits< ::UniPAX::Control >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());

    object_statements< object_type >::auto_lock l (sts);

    if (!find_ (sts, id))
      return false;

    reference_cache_traits< object_type >::insert_guard ig (
      reference_cache_traits< object_type >::insert (db, id, obj));

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), db);
    sts.find_statement ().stream_result ();
    load_ (sts, obj);
    sts.load_delayed ();
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    ig.release ();
    return true;
  }

  bool access::object_traits< ::UniPAX::Control >::
  reload (database& db, object_type& obj)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());
    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());

    object_statements< object_type >::auto_lock l (sts);

    if (!find_ (sts, obj.unipaxId))
      return false;

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), db);
    sts.find_statement ().stream_result ();
    load_ (sts, obj);
    sts.load_delayed ();
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits< ::UniPAX::Control >::
  find_ (oracle::object_statements< object_type >& sts, const id_type& id)
  {
    using namespace oracle;

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () || imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());
    st.execute ();
    select_statement::result r (st.fetch ());
    st.free_result ();
    return r != select_statement::no_data;
  }

  void access::object_traits< ::UniPAX::Control >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    comments_traits::load (
      obj.comments,
      idb,
      sts.container_statment_cache ().comments);

    name_traits::load (
      obj.name,
      idb,
      sts.container_statment_cache ().name);

    id_xref_traits::load (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    id_participant_traits::load (
      obj.id_participant,
      idb,
      sts.container_statment_cache ().id_participant);

    interactionType_traits::load (
      obj.interactionType,
      idb,
      sts.container_statment_cache ().interactionType);

    id_controller_traits::load (
      obj.id_controller,
      idb,
      sts.container_statment_cache ().id_controller);
  }

  result< access::object_traits< ::UniPAX::Control >::object_type >
  access::object_traits< ::UniPAX::Control >::
  query (database&, const query_base_type& q)
  {
    using namespace oracle;
    using odb::details::shared;
    using odb::details::shared_ptr;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());

    object_statements< object_type >& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () || imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    shared_ptr<select_statement> st (
      new (shared) select_statement (
        sts.connection (),
        query_statement + q.clause (),
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) oracle::object_result_impl<object_type> (
        q, st, sts));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits< ::UniPAX::Control >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace oracle;

    oracle::connection& conn (
      oracle::transaction::current ().connection ());

    delete_statement st (
      conn,
      erase_query_statement + q.clause (),
      q.parameters_binding ());

    return st.execute ();
  }
}

// Begin epilogue.
//
//
// End epilogue.

#include <odb/post.hxx>
