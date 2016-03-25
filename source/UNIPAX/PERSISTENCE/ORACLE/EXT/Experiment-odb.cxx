// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/EXT/Experiment-odb.hxx>

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
  // Experiment
  //

  // mapping
  //

  const char access::object_traits< ::UniPAX::Experiment >::mapping_traits::select_all_statement[] =
  "SELECT "
  "\"Experiment_mapping\".\"index\","
  "\"Experiment_mapping\".\"value\""
  " FROM \"Experiment_mapping\" WHERE \"Experiment_mapping\".\"object_id\"=:1"
  " ORDER BY \"Experiment_mapping\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Experiment >::mapping_traits::insert_one_statement[] =
  "INSERT INTO \"Experiment_mapping\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Experiment >::mapping_traits::delete_all_statement[] =
  "DELETE FROM \"Experiment_mapping\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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
      typedef object_traits< ::UniPAX::Mapping > obj_traits;
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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
      typedef object_traits< ::UniPAX::Mapping > obj_traits;
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  bool access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::mapping_traits::
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

  // sample
  //

  const char access::object_traits< ::UniPAX::Experiment >::sample_traits::select_all_statement[] =
  "SELECT "
  "\"Experiment_sample\".\"index\","
  "\"Experiment_sample\".\"value\""
  " FROM \"Experiment_sample\" WHERE \"Experiment_sample\".\"object_id\"=:1"
  " ORDER BY \"Experiment_sample\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Experiment >::sample_traits::insert_one_statement[] =
  "INSERT INTO \"Experiment_sample\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Experiment >::sample_traits::delete_all_statement[] =
  "DELETE FROM \"Experiment_sample\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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
      typedef object_traits< ::UniPAX::Sample > obj_traits;
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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
      typedef object_traits< ::UniPAX::Sample > obj_traits;
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  bool access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::sample_traits::
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

  void access::object_traits< ::UniPAX::Experiment >::
  bind (oracle::bind* b, image_type& i, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);

    // UPBase base
    //
    object_traits< ::UniPAX::UPBase >::bind (b + n, i, sk);
    n += 1UL - (
      sk == statement_select ? 0 : (
        sk == statement_insert ? 0 : 1UL));

    // experimentId
    //
    b[n].type = oracle::bind::integer;
    b[n].buffer = &i.experimentId_value;
    b[n].capacity = 4;
    b[n].size = 0;
    b[n].indicator = &i.experimentId_indicator;
    n++;

    // name
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.name_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.name_value));
    b[n].size = &i.name_size;
    b[n].indicator = &i.name_indicator;
    n++;

    // shortDescription
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.shortDescription_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.shortDescription_value));
    b[n].size = &i.shortDescription_size;
    b[n].indicator = &i.shortDescription_indicator;
    n++;

    // source
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.source_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.source_value));
    b[n].size = &i.source_size;
    b[n].indicator = &i.source_indicator;
    n++;

    // user
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.user_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.user_value));
    b[n].size = &i.user_size;
    b[n].indicator = &i.user_indicator;
    n++;

    // metaInfos
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.metaInfos_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.metaInfos_value));
    b[n].size = &i.metaInfos_size;
    b[n].indicator = &i.metaInfos_indicator;
    n++;

    // valuesPerSample
    //
    b[n].type = oracle::bind::integer;
    b[n].buffer = &i.valuesPerSample_value;
    b[n].capacity = 4;
    b[n].size = 0;
    b[n].indicator = &i.valuesPerSample_indicator;
    n++;

    // defaultMapping
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.defaultMapping_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.defaultMapping_value));
    b[n].size = &i.defaultMapping_size;
    b[n].indicator = &i.defaultMapping_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::Experiment >::
  init (image_type& i, const object_type& o, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    bool grew (false);

    // UPBase base
    //
    if (object_traits< ::UniPAX::UPBase >::init (i, o, sk))
      grew = true;

    // experimentId
    //
    {
      bool is_null;
      oracle::value_traits<
          int,
          oracle::id_int32 >::set_image (
        i.experimentId_value, is_null, o.experimentId);
      i.experimentId_indicator = is_null ? -1 : 0;
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

    // shortDescription
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.shortDescription_value,
        sizeof (i.shortDescription_value),
        size,
        is_null,
        o.shortDescription);
      i.shortDescription_size = static_cast<ub2> (size);
      i.shortDescription_indicator = is_null ? -1 : 0;
    }

    // source
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.source_value,
        sizeof (i.source_value),
        size,
        is_null,
        o.source);
      i.source_size = static_cast<ub2> (size);
      i.source_indicator = is_null ? -1 : 0;
    }

    // user
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.user_value,
        sizeof (i.user_value),
        size,
        is_null,
        o.user);
      i.user_size = static_cast<ub2> (size);
      i.user_indicator = is_null ? -1 : 0;
    }

    // metaInfos
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.metaInfos_value,
        sizeof (i.metaInfos_value),
        size,
        is_null,
        o.metaInfos);
      i.metaInfos_size = static_cast<ub2> (size);
      i.metaInfos_indicator = is_null ? -1 : 0;
    }

    // valuesPerSample
    //
    {
      bool is_null;
      oracle::value_traits<
          int,
          oracle::id_int32 >::set_image (
        i.valuesPerSample_value, is_null, o.valuesPerSample);
      i.valuesPerSample_indicator = is_null ? -1 : 0;
    }

    // defaultMapping
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.defaultMapping_value,
        sizeof (i.defaultMapping_value),
        size,
        is_null,
        o.defaultMapping);
      i.defaultMapping_size = static_cast<ub2> (size);
      i.defaultMapping_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::Experiment >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UPBase base
    //
    object_traits< ::UniPAX::UPBase >::init (o, i, db);

    // experimentId
    //
    oracle::value_traits<
        int,
        oracle::id_int32 >::set_value (
      o.experimentId,
      i.experimentId_value,
      i.experimentId_indicator == -1);

    // name
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.name,
      i.name_value,
      i.name_size,
      i.name_indicator == -1);

    // shortDescription
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.shortDescription,
      i.shortDescription_value,
      i.shortDescription_size,
      i.shortDescription_indicator == -1);

    // source
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.source,
      i.source_value,
      i.source_size,
      i.source_indicator == -1);

    // user
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.user,
      i.user_value,
      i.user_size,
      i.user_indicator == -1);

    // metaInfos
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.metaInfos,
      i.metaInfos_value,
      i.metaInfos_size,
      i.metaInfos_indicator == -1);

    // valuesPerSample
    //
    oracle::value_traits<
        int,
        oracle::id_int32 >::set_value (
      o.valuesPerSample,
      i.valuesPerSample_value,
      i.valuesPerSample_indicator == -1);

    // defaultMapping
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.defaultMapping,
      i.defaultMapping_value,
      i.defaultMapping_size,
      i.defaultMapping_indicator == -1);
  }

  struct access::object_traits< ::UniPAX::Experiment >::container_statement_cache_type
  {
    oracle::container_statements_impl< mapping_traits > mapping;
    oracle::container_statements_impl< sample_traits > sample;

    container_statement_cache_type (oracle::connection& c)
    : mapping (c),
      sample (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::Experiment >::persist_statement[] =
  "INSERT INTO \"Experiment\" ("
  "\"unipaxId\","
  "\"experimentId\","
  "\"name\","
  "\"shortDescription\","
  "\"source\","
  "\"user\","
  "\"metaInfos\","
  "\"valuesPerSample\","
  "\"defaultMapping\")"
  " VALUES (:1,:2,:3,:4,:5,:6,:7,:8,:9)";

  const char access::object_traits< ::UniPAX::Experiment >::find_statement[] =
  "SELECT "
  "\"Experiment\".\"unipaxId\","
  "\"Experiment\".\"experimentId\","
  "\"Experiment\".\"name\","
  "\"Experiment\".\"shortDescription\","
  "\"Experiment\".\"source\","
  "\"Experiment\".\"user\","
  "\"Experiment\".\"metaInfos\","
  "\"Experiment\".\"valuesPerSample\","
  "\"Experiment\".\"defaultMapping\""
  " FROM \"Experiment\""
  " WHERE \"Experiment\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Experiment >::update_statement[] =
  "UPDATE \"Experiment\" SET "
  "\"experimentId\"=:1,"
  "\"name\"=:2,"
  "\"shortDescription\"=:3,"
  "\"source\"=:4,"
  "\"user\"=:5,"
  "\"metaInfos\"=:6,"
  "\"valuesPerSample\"=:7,"
  "\"defaultMapping\"=:8"
  " WHERE \"unipaxId\"=:9";

  const char access::object_traits< ::UniPAX::Experiment >::erase_statement[] =
  "DELETE FROM \"Experiment\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Experiment >::query_statement[] =
  "SELECT "
  "\"Experiment\".\"unipaxId\","
  "\"Experiment\".\"experimentId\","
  "\"Experiment\".\"name\","
  "\"Experiment\".\"shortDescription\","
  "\"Experiment\".\"source\","
  "\"Experiment\".\"user\","
  "\"Experiment\".\"metaInfos\","
  "\"Experiment\".\"valuesPerSample\","
  "\"Experiment\".\"defaultMapping\""
  " FROM \"Experiment\""
  " ";

  const char access::object_traits< ::UniPAX::Experiment >::erase_query_statement[] =
  "DELETE FROM \"Experiment\""
  " ";

  const char access::object_traits< ::UniPAX::Experiment >::table_name[] =
  "\"Experiment\"";

  void access::object_traits< ::UniPAX::Experiment >::
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

    mapping_traits::persist (
      obj.mapping,
      idb,
      sts.container_statment_cache ().mapping);

    sample_traits::persist (
      obj.sample,
      idb,
      sts.container_statment_cache ().sample);
  }

  void access::object_traits< ::UniPAX::Experiment >::
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

    mapping_traits::update (
      obj.mapping,
      idb,
      sts.container_statment_cache ().mapping);

    sample_traits::update (
      obj.sample,
      idb,
      sts.container_statment_cache ().sample);
  }

  void access::object_traits< ::UniPAX::Experiment >::
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

    mapping_traits::erase (
      idb,
      sts.container_statment_cache ().mapping);

    sample_traits::erase (
      idb,
      sts.container_statment_cache ().sample);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::Experiment >::pointer_type
  access::object_traits< ::UniPAX::Experiment >::
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

  bool access::object_traits< ::UniPAX::Experiment >::
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

  bool access::object_traits< ::UniPAX::Experiment >::
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

  bool access::object_traits< ::UniPAX::Experiment >::
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

  void access::object_traits< ::UniPAX::Experiment >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    mapping_traits::load (
      obj.mapping,
      idb,
      sts.container_statment_cache ().mapping);

    sample_traits::load (
      obj.sample,
      idb,
      sts.container_statment_cache ().sample);
  }

  result< access::object_traits< ::UniPAX::Experiment >::object_type >
  access::object_traits< ::UniPAX::Experiment >::
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

  unsigned long long access::object_traits< ::UniPAX::Experiment >::
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
