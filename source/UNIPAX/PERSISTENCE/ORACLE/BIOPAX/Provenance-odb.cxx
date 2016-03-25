// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Provenance-odb.hxx>

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
  // Provenance
  //

  // comment
  //

  const char access::object_traits< ::UniPAX::Provenance >::comment_traits::select_all_statement[] =
  "SELECT "
  "\"Provenance_comment\".\"index\","
  "\"Provenance_comment\".\"value\""
  " FROM \"Provenance_comment\" WHERE \"Provenance_comment\".\"object_id\"=:1"
  " ORDER BY \"Provenance_comment\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Provenance >::comment_traits::insert_one_statement[] =
  "INSERT INTO \"Provenance_comment\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Provenance >::comment_traits::delete_all_statement[] =
  "DELETE FROM \"Provenance_comment\""
  " WHERE \"object_id\"=:1";

  // id_xref
  //

  const char access::object_traits< ::UniPAX::Provenance >::id_xref_traits::select_all_statement[] =
  "SELECT "
  "\"Provenance_id_xref\".\"index\","
  "\"Provenance_id_xref\".\"value\""
  " FROM \"Provenance_id_xref\" WHERE \"Provenance_id_xref\".\"object_id\"=:1"
  " ORDER BY \"Provenance_id_xref\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Provenance >::id_xref_traits::insert_one_statement[] =
  "INSERT INTO \"Provenance_id_xref\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Provenance >::id_xref_traits::delete_all_statement[] =
  "DELETE FROM \"Provenance_id_xref\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  bool access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::id_xref_traits::
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

  // name
  //

  const char access::object_traits< ::UniPAX::Provenance >::name_traits::select_all_statement[] =
  "SELECT "
  "\"Provenance_name\".\"index\","
  "\"Provenance_name\".\"value\""
  " FROM \"Provenance_name\" WHERE \"Provenance_name\".\"object_id\"=:1"
  " ORDER BY \"Provenance_name\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Provenance >::name_traits::insert_one_statement[] =
  "INSERT INTO \"Provenance_name\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Provenance >::name_traits::delete_all_statement[] =
  "DELETE FROM \"Provenance_name\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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
    b[n].type = oracle::bind::string;
    b[n].buffer = d.value_value;
    b[n].capacity = static_cast<ub4> (sizeof (d.value_value));
    b[n].size = &d.value_size;
    b[n].indicator = &d.value_indicator;
  }

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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
          oracle::id_string >::set_image (
        i.value_value,
        sizeof (i.value_value),
        size,
        is_null,
        v);
      i.value_size = static_cast<ub2> (size);
      i.value_indicator = is_null ? -1 : 0;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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
        oracle::id_string >::set_value (
      v,
      i.value_value,
      i.value_size,
      i.value_indicator == -1);
  }

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  bool access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
  delete_all (void* d)
  {
    using namespace oracle;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_all_statement ().execute ();
  }

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::name_traits::
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

  void access::object_traits< ::UniPAX::Provenance >::
  bind (oracle::bind* b, image_type& i, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    std::size_t n (0);

    // UtilityClass base
    //
    object_traits< ::UniPAX::UtilityClass >::bind (b + n, i, sk);
    n += 2UL - (
      sk == statement_select ? 0 : (
        sk == statement_insert ? 0 : 1UL));

    // standardName
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.standardName_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.standardName_value));
    b[n].size = &i.standardName_size;
    b[n].indicator = &i.standardName_indicator;
    n++;

    // displayName
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.displayName_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.displayName_value));
    b[n].size = &i.displayName_size;
    b[n].indicator = &i.displayName_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::Provenance >::
  init (image_type& i, const object_type& o, oracle::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace oracle;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    bool grew (false);

    // UtilityClass base
    //
    if (object_traits< ::UniPAX::UtilityClass >::init (i, o, sk))
      grew = true;

    // standardName
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.standardName_value,
        sizeof (i.standardName_value),
        size,
        is_null,
        o.standardName);
      i.standardName_size = static_cast<ub2> (size);
      i.standardName_indicator = is_null ? -1 : 0;
    }

    // displayName
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.displayName_value,
        sizeof (i.displayName_value),
        size,
        is_null,
        o.displayName);
      i.displayName_size = static_cast<ub2> (size);
      i.displayName_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::Provenance >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UtilityClass base
    //
    object_traits< ::UniPAX::UtilityClass >::init (o, i, db);

    // standardName
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.standardName,
      i.standardName_value,
      i.standardName_size,
      i.standardName_indicator == -1);

    // displayName
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.displayName,
      i.displayName_value,
      i.displayName_size,
      i.displayName_indicator == -1);
  }

  struct access::object_traits< ::UniPAX::Provenance >::container_statement_cache_type
  {
    oracle::container_statements_impl< comment_traits > comment;
    oracle::container_statements_impl< id_xref_traits > id_xref;
    oracle::container_statements_impl< name_traits > name;

    container_statement_cache_type (oracle::connection& c)
    : comment (c),
      id_xref (c),
      name (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::Provenance >::persist_statement[] =
  "INSERT INTO \"Provenance\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"standardName\","
  "\"displayName\")"
  " VALUES (:1,:2,:3,:4)";

  const char access::object_traits< ::UniPAX::Provenance >::find_statement[] =
  "SELECT "
  "\"Provenance\".\"unipaxId\","
  "\"Provenance\".\"unipaxSource\","
  "\"Provenance\".\"standardName\","
  "\"Provenance\".\"displayName\""
  " FROM \"Provenance\""
  " WHERE \"Provenance\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Provenance >::update_statement[] =
  "UPDATE \"Provenance\" SET "
  "\"unipaxSource\"=:1,"
  "\"standardName\"=:2,"
  "\"displayName\"=:3"
  " WHERE \"unipaxId\"=:4";

  const char access::object_traits< ::UniPAX::Provenance >::erase_statement[] =
  "DELETE FROM \"Provenance\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Provenance >::query_statement[] =
  "SELECT "
  "\"Provenance\".\"unipaxId\","
  "\"Provenance\".\"unipaxSource\","
  "\"Provenance\".\"standardName\","
  "\"Provenance\".\"displayName\""
  " FROM \"Provenance\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"Provenance\".\"unipaxSource\""
  " ";

  const char access::object_traits< ::UniPAX::Provenance >::erase_query_statement[] =
  "DELETE FROM \"Provenance\""
  " ";

  const char access::object_traits< ::UniPAX::Provenance >::table_name[] =
  "\"Provenance\"";

  void access::object_traits< ::UniPAX::Provenance >::
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

    comment_traits::persist (
      obj.comment,
      idb,
      sts.container_statment_cache ().comment);

    id_xref_traits::persist (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    name_traits::persist (
      obj.name,
      idb,
      sts.container_statment_cache ().name);
  }

  void access::object_traits< ::UniPAX::Provenance >::
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

    comment_traits::update (
      obj.comment,
      idb,
      sts.container_statment_cache ().comment);

    id_xref_traits::update (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    name_traits::update (
      obj.name,
      idb,
      sts.container_statment_cache ().name);
  }

  void access::object_traits< ::UniPAX::Provenance >::
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

    comment_traits::erase (
      idb,
      sts.container_statment_cache ().comment);

    id_xref_traits::erase (
      idb,
      sts.container_statment_cache ().id_xref);

    name_traits::erase (
      idb,
      sts.container_statment_cache ().name);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::Provenance >::pointer_type
  access::object_traits< ::UniPAX::Provenance >::
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

  bool access::object_traits< ::UniPAX::Provenance >::
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

  bool access::object_traits< ::UniPAX::Provenance >::
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

  bool access::object_traits< ::UniPAX::Provenance >::
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

  void access::object_traits< ::UniPAX::Provenance >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    comment_traits::load (
      obj.comment,
      idb,
      sts.container_statment_cache ().comment);

    id_xref_traits::load (
      obj.id_xref,
      idb,
      sts.container_statment_cache ().id_xref);

    name_traits::load (
      obj.name,
      idb,
      sts.container_statment_cache ().name);
  }

  result< access::object_traits< ::UniPAX::Provenance >::object_type >
  access::object_traits< ::UniPAX::Provenance >::
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

  unsigned long long access::object_traits< ::UniPAX::Provenance >::
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
