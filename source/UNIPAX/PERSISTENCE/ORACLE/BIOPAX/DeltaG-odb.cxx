// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/DeltaG-odb.hxx>

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
  // DeltaG
  //

  // comment
  //

  const char access::object_traits< ::UniPAX::DeltaG >::comment_traits::select_all_statement[] =
  "SELECT "
  "\"DeltaG_comment\".\"index\","
  "\"DeltaG_comment\".\"value\""
  " FROM \"DeltaG_comment\" WHERE \"DeltaG_comment\".\"object_id\"=:1"
  " ORDER BY \"DeltaG_comment\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::DeltaG >::comment_traits::insert_one_statement[] =
  "INSERT INTO \"DeltaG_comment\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::DeltaG >::comment_traits::delete_all_statement[] =
  "DELETE FROM \"DeltaG_comment\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::DeltaG >::
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

    // deltaGPrime0
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.deltaGPrime0_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.deltaGPrime0_indicator;
    n++;

    // ionicStrength
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.ionicStrength_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.ionicStrength_indicator;
    n++;

    // ph
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.ph_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.ph_indicator;
    n++;

    // pMg
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.pMg_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.pMg_indicator;
    n++;

    // temperature
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.temperature_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.temperature_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::DeltaG >::
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

    // deltaGPrime0
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.deltaGPrime0_value, is_null, o.deltaGPrime0);
      i.deltaGPrime0_indicator = is_null ? -1 : 0;
    }

    // ionicStrength
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.ionicStrength_value, is_null, o.ionicStrength);
      i.ionicStrength_indicator = is_null ? -1 : 0;
    }

    // ph
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.ph_value, is_null, o.ph);
      i.ph_indicator = is_null ? -1 : 0;
    }

    // pMg
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.pMg_value, is_null, o.pMg);
      i.pMg_indicator = is_null ? -1 : 0;
    }

    // temperature
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.temperature_value, is_null, o.temperature);
      i.temperature_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::DeltaG >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UtilityClass base
    //
    object_traits< ::UniPAX::UtilityClass >::init (o, i, db);

    // deltaGPrime0
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.deltaGPrime0,
      i.deltaGPrime0_value,
      i.deltaGPrime0_indicator == -1);

    // ionicStrength
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.ionicStrength,
      i.ionicStrength_value,
      i.ionicStrength_indicator == -1);

    // ph
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.ph,
      i.ph_value,
      i.ph_indicator == -1);

    // pMg
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.pMg,
      i.pMg_value,
      i.pMg_indicator == -1);

    // temperature
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.temperature,
      i.temperature_value,
      i.temperature_indicator == -1);
  }

  struct access::object_traits< ::UniPAX::DeltaG >::container_statement_cache_type
  {
    oracle::container_statements_impl< comment_traits > comment;

    container_statement_cache_type (oracle::connection& c)
    : comment (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::DeltaG >::persist_statement[] =
  "INSERT INTO \"DeltaG\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"deltaGPrime0\","
  "\"ionicStrength\","
  "\"ph\","
  "\"pMg\","
  "\"temperature\")"
  " VALUES (:1,:2,:3,:4,:5,:6,:7)";

  const char access::object_traits< ::UniPAX::DeltaG >::find_statement[] =
  "SELECT "
  "\"DeltaG\".\"unipaxId\","
  "\"DeltaG\".\"unipaxSource\","
  "\"DeltaG\".\"deltaGPrime0\","
  "\"DeltaG\".\"ionicStrength\","
  "\"DeltaG\".\"ph\","
  "\"DeltaG\".\"pMg\","
  "\"DeltaG\".\"temperature\""
  " FROM \"DeltaG\""
  " WHERE \"DeltaG\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::DeltaG >::update_statement[] =
  "UPDATE \"DeltaG\" SET "
  "\"unipaxSource\"=:1,"
  "\"deltaGPrime0\"=:2,"
  "\"ionicStrength\"=:3,"
  "\"ph\"=:4,"
  "\"pMg\"=:5,"
  "\"temperature\"=:6"
  " WHERE \"unipaxId\"=:7";

  const char access::object_traits< ::UniPAX::DeltaG >::erase_statement[] =
  "DELETE FROM \"DeltaG\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::DeltaG >::query_statement[] =
  "SELECT "
  "\"DeltaG\".\"unipaxId\","
  "\"DeltaG\".\"unipaxSource\","
  "\"DeltaG\".\"deltaGPrime0\","
  "\"DeltaG\".\"ionicStrength\","
  "\"DeltaG\".\"ph\","
  "\"DeltaG\".\"pMg\","
  "\"DeltaG\".\"temperature\""
  " FROM \"DeltaG\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"DeltaG\".\"unipaxSource\""
  " ";

  const char access::object_traits< ::UniPAX::DeltaG >::erase_query_statement[] =
  "DELETE FROM \"DeltaG\""
  " ";

  const char access::object_traits< ::UniPAX::DeltaG >::table_name[] =
  "\"DeltaG\"";

  void access::object_traits< ::UniPAX::DeltaG >::
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
  }

  void access::object_traits< ::UniPAX::DeltaG >::
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
  }

  void access::object_traits< ::UniPAX::DeltaG >::
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

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();
  }

  access::object_traits< ::UniPAX::DeltaG >::pointer_type
  access::object_traits< ::UniPAX::DeltaG >::
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

  bool access::object_traits< ::UniPAX::DeltaG >::
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

  bool access::object_traits< ::UniPAX::DeltaG >::
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

  bool access::object_traits< ::UniPAX::DeltaG >::
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

  void access::object_traits< ::UniPAX::DeltaG >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    comment_traits::load (
      obj.comment,
      idb,
      sts.container_statment_cache ().comment);
  }

  result< access::object_traits< ::UniPAX::DeltaG >::object_type >
  access::object_traits< ::UniPAX::DeltaG >::
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

  unsigned long long access::object_traits< ::UniPAX::DeltaG >::
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
