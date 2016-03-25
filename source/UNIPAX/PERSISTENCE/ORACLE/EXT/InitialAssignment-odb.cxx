// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/EXT/InitialAssignment-odb.hxx>

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
  // InitialAssignment
  //

  const char query_columns_base< ::UniPAX::InitialAssignment >::math_alias_[] = "\"math\"";

  void access::object_traits< ::UniPAX::InitialAssignment >::
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

    // symbol
    //
    b[n].type = oracle::bind::string;
    b[n].buffer = i.symbol_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.symbol_value));
    b[n].size = &i.symbol_size;
    b[n].indicator = &i.symbol_indicator;
    n++;

    // math
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.math_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.math_value));
    b[n].size = &i.math_size;
    b[n].indicator = &i.math_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::InitialAssignment >::
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

    // symbol
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          ::std::string,
          oracle::id_string >::set_image (
        i.symbol_value,
        sizeof (i.symbol_value),
        size,
        is_null,
        o.symbol);
      i.symbol_size = static_cast<ub2> (size);
      i.symbol_indicator = is_null ? -1 : 0;
    }

    // math
    //
    {
      typedef object_traits< ::UniPAX::Math > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Math > > ptr_traits;

      bool is_null (ptr_traits::null_ptr (o.math));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (o.math)));

        std::size_t size (0);
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_image (
          i.math_value,
          size,
          is_null,
          id);
        i.math_size = static_cast<ub2> (size);
      }

      i.math_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::InitialAssignment >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // SBase base
    //
    object_traits< ::UniPAX::SBase >::init (o, i, db);

    // symbol
    //
    oracle::value_traits<
        ::std::string,
        oracle::id_string >::set_value (
      o.symbol,
      i.symbol_value,
      i.symbol_size,
      i.symbol_indicator == -1);

    // math
    //
    {
      typedef object_traits< ::UniPAX::Math > obj_traits;
      typedef pointer_traits< ::boost::shared_ptr< ::UniPAX::Math > > ptr_traits;

      if (i.math_indicator == -1)
        o.math = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        oracle::value_traits<
            obj_traits::id_type,
            oracle::id_big_int >::set_value (
          id,
          i.math_value,
          i.math_size,
          i.math_indicator == -1);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        o.math = ptr_traits::pointer_type (
          db.load< obj_traits::object_type > (id));
      }
    }
  }

  struct access::object_traits< ::UniPAX::InitialAssignment >::container_statement_cache_type
  {
    container_statement_cache_type (oracle::connection&)
    {
    }
  };

  const char access::object_traits< ::UniPAX::InitialAssignment >::persist_statement[] =
  "INSERT INTO \"InitialAssignment\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"metaId\","
  "\"sboTerm\","
  "\"notes\","
  "\"annotation\","
  "\"symbol\","
  "\"math\")"
  " VALUES (:1,:2,:3,:4,:5,:6,:7,:8)";

  const char access::object_traits< ::UniPAX::InitialAssignment >::find_statement[] =
  "SELECT "
  "\"InitialAssignment\".\"unipaxId\","
  "\"InitialAssignment\".\"unipaxSource\","
  "\"InitialAssignment\".\"metaId\","
  "\"InitialAssignment\".\"sboTerm\","
  "\"InitialAssignment\".\"notes\","
  "\"InitialAssignment\".\"annotation\","
  "\"InitialAssignment\".\"symbol\","
  "\"InitialAssignment\".\"math\""
  " FROM \"InitialAssignment\""
  " WHERE \"InitialAssignment\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::InitialAssignment >::update_statement[] =
  "UPDATE \"InitialAssignment\" SET "
  "\"unipaxSource\"=:1,"
  "\"metaId\"=:2,"
  "\"sboTerm\"=:3,"
  "\"notes\"=:4,"
  "\"annotation\"=:5,"
  "\"symbol\"=:6,"
  "\"math\"=:7"
  " WHERE \"unipaxId\"=:8";

  const char access::object_traits< ::UniPAX::InitialAssignment >::erase_statement[] =
  "DELETE FROM \"InitialAssignment\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::InitialAssignment >::query_statement[] =
  "SELECT "
  "\"InitialAssignment\".\"unipaxId\","
  "\"InitialAssignment\".\"unipaxSource\","
  "\"InitialAssignment\".\"metaId\","
  "\"InitialAssignment\".\"sboTerm\","
  "\"InitialAssignment\".\"notes\","
  "\"InitialAssignment\".\"annotation\","
  "\"InitialAssignment\".\"symbol\","
  "\"InitialAssignment\".\"math\""
  " FROM \"InitialAssignment\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"InitialAssignment\".\"unipaxSource\""
  " LEFT JOIN \"Math\" \"math\" ON \"math\".\"unipaxId\" = \"InitialAssignment\".\"math\""
  " ";

  const char access::object_traits< ::UniPAX::InitialAssignment >::erase_query_statement[] =
  "DELETE FROM \"InitialAssignment\""
  " ";

  const char access::object_traits< ::UniPAX::InitialAssignment >::table_name[] =
  "\"InitialAssignment\"";

  void access::object_traits< ::UniPAX::InitialAssignment >::
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
  }

  void access::object_traits< ::UniPAX::InitialAssignment >::
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
  }

  void access::object_traits< ::UniPAX::InitialAssignment >::
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

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::InitialAssignment >::pointer_type
  access::object_traits< ::UniPAX::InitialAssignment >::
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

  bool access::object_traits< ::UniPAX::InitialAssignment >::
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

  bool access::object_traits< ::UniPAX::InitialAssignment >::
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

  bool access::object_traits< ::UniPAX::InitialAssignment >::
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

  result< access::object_traits< ::UniPAX::InitialAssignment >::object_type >
  access::object_traits< ::UniPAX::InitialAssignment >::
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

  unsigned long long access::object_traits< ::UniPAX::InitialAssignment >::
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
