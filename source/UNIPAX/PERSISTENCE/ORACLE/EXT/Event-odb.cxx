// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/EXT/Event-odb.hxx>

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
  // Event
  //

  const char query_columns_base< ::UniPAX::Event >::priority_alias_[] = "\"priority\"";

  const char query_columns_base< ::UniPAX::Event >::delay_alias_[] = "\"delay\"";

  const char query_columns_base< ::UniPAX::Event >::trigger_alias_[] = "\"trigger\"";

  // eventAssignment
  //

  const char access::object_traits< ::UniPAX::Event >::eventAssignment_traits::select_all_statement[] =
  "SELECT "
  "\"Event_eventAssignment\".\"index\","
  "\"Event_eventAssignment\".\"value\""
  " FROM \"Event_eventAssignment\" WHERE \"Event_eventAssignment\".\"object_id\"=:1"
  " ORDER BY \"Event_eventAssignment\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Event >::eventAssignment_traits::insert_one_statement[] =
  "INSERT INTO \"Event_eventAssignment\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Event >::eventAssignment_traits::delete_all_statement[] =
  "DELETE FROM \"Event_eventAssignment\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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
      typedef object_traits< ::UniPAX::EventAssignment > obj_traits;
      typedef pointer_traits< value_type > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        std::size_t size (0);
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_image (
          i.value_value,
          size,
          is_null,
          id);
        i.value_size = static_cast<ub2> (size);
      }

      i.value_indicator = is_null ? -1 : 0;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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
    {
      typedef object_traits< ::UniPAX::EventAssignment > obj_traits;
      typedef pointer_traits< value_type > ptr_traits;

      if (i.value_indicator == -1)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_value (
          id,
          i.value_value,
          i.value_size,
          i.value_indicator == -1);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          db.load< obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  bool access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
  load_all (index_type& i, value_type& v, void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());
    init (i, v, di, sts.connection ().database ());

    sts.select_all_statement ().stream_result ();

    const binding& idb (sts.id_binding ());

    if (di.version != sts.data_image_version () ||
        idb.version != sts.data_id_binding_version ())
    {
      binding& b (sts.data_image_binding ());
      bind (b.bind, idb.bind, idb.count, di);
      sts.data_image_version (di.version);
      sts.data_id_binding_version (idb.version);
      b.version++;
      sts.select_image_binding ().version++;
    }

    select_statement& st (sts.select_all_statement ());
    select_statement::result r (st.fetch ());
    if (r == select_statement::no_data)
    {
      st.free_result ();
      return false;
    }

    return true;
  }

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::eventAssignment_traits::
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

  void access::object_traits< ::UniPAX::Event >::
  bind (oracle::bind* b, image_type& i, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);

    // SBase base
    //
    object_traits< ::UniPAX::SBase >::bind (b + n, i, sk);
    n += 6UL - (
      sk == statement_select ? 0 : (
        sk == statement_insert ? 0 : 1UL));

    // useValuesFromTriggerTime
    //
    b[n].type = oracle::bind::uinteger;
    b[n].buffer = &i.useValuesFromTriggerTime_value;
    b[n].capacity = 4;
    b[n].size = 0;
    b[n].indicator = &i.useValuesFromTriggerTime_indicator;
    n++;

    // id
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.id_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.id_value));
    b[n].size = &i.id_size;
    b[n].indicator = &i.id_indicator;
    n++;

    // name
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.name_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.name_value));
    b[n].size = &i.name_size;
    b[n].indicator = &i.name_indicator;
    n++;

    // priority
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.priority_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.priority_value));
    b[n].size = &i.priority_size;
    b[n].indicator = &i.priority_indicator;
    n++;

    // delay
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.delay_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.delay_value));
    b[n].size = &i.delay_size;
    b[n].indicator = &i.delay_indicator;
    n++;

    // trigger
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.trigger_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.trigger_value));
    b[n].size = &i.trigger_size;
    b[n].indicator = &i.trigger_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::Event >::
  init (image_type& i, const object_type& o, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    bool grew (false);

    // SBase base
    //
    if (object_traits< ::UniPAX::SBase >::init (i, o, sk))
      grew = true;

    // useValuesFromTriggerTime
    //
    {
      bool is_null;
      oracle::value_traits<
          bool,
          oracle::id_int32 >::set_image (
        i.useValuesFromTriggerTime_value, is_null, o.useValuesFromTriggerTime);
      i.useValuesFromTriggerTime_indicator = is_null ? -1 : 0;
    }

    // id
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.id_value,
        sizeof (i.id_value),
        size,
        is_null,
        o.id);
      i.id_size = static_cast<ub2> (size);
      i.id_indicator = is_null ? -1 : 0;
    }

    // name
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.name_value,
        sizeof (i.name_value),
        size,
        is_null,
        o.name);
      i.name_size = static_cast<ub2> (size);
      i.name_indicator = is_null ? -1 : 0;
    }

    // priority
    //
    {
      typedef object_traits< ::UniPAX::Priority > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Priority > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (o.priority));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (o.priority)));

        std::size_t size (0);
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_image (
          i.priority_value,
          size,
          is_null,
          id);
        i.priority_size = static_cast<ub2> (size);
      }

      i.priority_indicator = is_null ? -1 : 0;
    }

    // delay
    //
    {
      typedef object_traits< ::UniPAX::Delay > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Delay > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (o.delay));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (o.delay)));

        std::size_t size (0);
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_image (
          i.delay_value,
          size,
          is_null,
          id);
        i.delay_size = static_cast<ub2> (size);
      }

      i.delay_indicator = is_null ? -1 : 0;
    }

    // trigger
    //
    {
      typedef object_traits< ::UniPAX::Trigger > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Trigger > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (o.trigger));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (o.trigger)));

        std::size_t size (0);
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_image (
          i.trigger_value,
          size,
          is_null,
          id);
        i.trigger_size = static_cast<ub2> (size);
      }

      i.trigger_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::Event >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // SBase base
    //
    object_traits< ::UniPAX::SBase >::init (o, i, db);

    // useValuesFromTriggerTime
    //
    oracle::value_traits<
        bool,
        oracle::id_int32 >::set_value (
      o.useValuesFromTriggerTime,
      i.useValuesFromTriggerTime_value,
      i.useValuesFromTriggerTime_indicator == -1);

    // id
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.id,
      i.id_value,
      i.id_size,
      i.id_indicator == -1);

    // name
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.name,
      i.name_value,
      i.name_size,
      i.name_indicator == -1);

    // priority
    //
    {
      typedef object_traits< ::UniPAX::Priority > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Priority > > ptr_traits;

      if (i.priority_indicator == -1)
        o.priority = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_value (
          id,
          i.priority_value,
          i.priority_size,
          i.priority_indicator == -1);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        o.priority = ptr_traits::pointer_type (
          db.load< obj_traits::object_type > (id));
      }
    }

    // delay
    //
    {
      typedef object_traits< ::UniPAX::Delay > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Delay > > ptr_traits;

      if (i.delay_indicator == -1)
        o.delay = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_value (
          id,
          i.delay_value,
          i.delay_size,
          i.delay_indicator == -1);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        o.delay = ptr_traits::pointer_type (
          db.load< obj_traits::object_type > (id));
      }
    }

    // trigger
    //
    {
      typedef object_traits< ::UniPAX::Trigger > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Trigger > > ptr_traits;

      if (i.trigger_indicator == -1)
        o.trigger = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_value (
          id,
          i.trigger_value,
          i.trigger_size,
          i.trigger_indicator == -1);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        o.trigger = ptr_traits::pointer_type (
          db.load< obj_traits::object_type > (id));
      }
    }
  }

  struct access::object_traits< ::UniPAX::Event >::container_statement_cache_type
  {
    oracle::container_statements_impl< eventAssignment_traits > eventAssignment;

    container_statement_cache_type (oracle::connection& c)
    : eventAssignment (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::Event >::persist_statement[] =
  "INSERT INTO \"Event\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"metaId\","
  "\"sboTerm\","
  "\"notes\","
  "\"annotation\","
  "\"useValuesFromTriggerTime\","
  "\"id\","
  "\"name\","
  "\"priority\","
  "\"delay\","
  "\"trigger\")"
  " VALUES (:1,:2,:3,:4,:5,:6,:7,:8,:9,:10,:11,:12)";

  const char access::object_traits< ::UniPAX::Event >::find_statement[] =
  "SELECT "
  "\"Event\".\"unipaxId\","
  "\"Event\".\"unipaxSource\","
  "\"Event\".\"metaId\","
  "\"Event\".\"sboTerm\","
  "\"Event\".\"notes\","
  "\"Event\".\"annotation\","
  "\"Event\".\"useValuesFromTriggerTime\","
  "\"Event\".\"id\","
  "\"Event\".\"name\","
  "\"Event\".\"priority\","
  "\"Event\".\"delay\","
  "\"Event\".\"trigger\""
  " FROM \"Event\""
  " WHERE \"Event\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Event >::update_statement[] =
  "UPDATE \"Event\" SET "
  "\"unipaxSource\"=:1,"
  "\"metaId\"=:2,"
  "\"sboTerm\"=:3,"
  "\"notes\"=:4,"
  "\"annotation\"=:5,"
  "\"useValuesFromTriggerTime\"=:6,"
  "\"id\"=:7,"
  "\"name\"=:8,"
  "\"priority\"=:9,"
  "\"delay\"=:10,"
  "\"trigger\"=:11"
  " WHERE \"unipaxId\"=:12";

  const char access::object_traits< ::UniPAX::Event >::erase_statement[] =
  "DELETE FROM \"Event\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Event >::query_statement[] =
  "SELECT "
  "\"Event\".\"unipaxId\","
  "\"Event\".\"unipaxSource\","
  "\"Event\".\"metaId\","
  "\"Event\".\"sboTerm\","
  "\"Event\".\"notes\","
  "\"Event\".\"annotation\","
  "\"Event\".\"useValuesFromTriggerTime\","
  "\"Event\".\"id\","
  "\"Event\".\"name\","
  "\"Event\".\"priority\","
  "\"Event\".\"delay\","
  "\"Event\".\"trigger\""
  " FROM \"Event\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"Event\".\"unipaxSource\""
  " LEFT JOIN \"Priority\" \"priority\" ON \"priority\".\"unipaxId\" = \"Event\".\"priority\""
  " LEFT JOIN \"Delay\" \"delay\" ON \"delay\".\"unipaxId\" = \"Event\".\"delay\""
  " LEFT JOIN \"Trigger\" \"trigger\" ON \"trigger\".\"unipaxId\" = \"Event\".\"trigger\""
  " ";

  const char access::object_traits< ::UniPAX::Event >::erase_query_statement[] =
  "DELETE FROM \"Event\""
  " ";

  const char access::object_traits< ::UniPAX::Event >::table_name[] =
  "\"Event\"";

  void access::object_traits< ::UniPAX::Event >::
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

    eventAssignment_traits::persist (
      obj.eventAssignment,
      idb,
      sts.container_statment_cache ().eventAssignment);
  }

  void access::object_traits< ::UniPAX::Event >::
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

    eventAssignment_traits::update (
      obj.eventAssignment,
      idb,
      sts.container_statment_cache ().eventAssignment);
  }

  void access::object_traits< ::UniPAX::Event >::
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

    eventAssignment_traits::erase (
      idb,
      sts.container_statment_cache ().eventAssignment);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::Event >::pointer_type
  access::object_traits< ::UniPAX::Event >::
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

  bool access::object_traits< ::UniPAX::Event >::
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

  bool access::object_traits< ::UniPAX::Event >::
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

  bool access::object_traits< ::UniPAX::Event >::
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

  void access::object_traits< ::UniPAX::Event >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    eventAssignment_traits::load (
      obj.eventAssignment,
      idb,
      sts.container_statment_cache ().eventAssignment);
  }

  result< access::object_traits< ::UniPAX::Event >::object_type >
  access::object_traits< ::UniPAX::Event >::
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

  unsigned long long access::object_traits< ::UniPAX::Event >::
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
