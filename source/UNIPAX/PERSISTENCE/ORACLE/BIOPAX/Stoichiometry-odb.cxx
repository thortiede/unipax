// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <UNIPAX/PERSISTENCE/ORACLE/BIOPAX/Stoichiometry-odb.hxx>

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
  // Stoichiometry
  //

  // comment
  //

  const char access::object_traits< ::UniPAX::Stoichiometry >::comment_traits::select_all_statement[] =
  "SELECT "
  "\"Stoichiometry_comment\".\"index\","
  "\"Stoichiometry_comment\".\"value\""
  " FROM \"Stoichiometry_comment\" WHERE \"Stoichiometry_comment\".\"object_id\"=:1"
  " ORDER BY \"Stoichiometry_comment\".\"index\""
  ;

  const char access::object_traits< ::UniPAX::Stoichiometry >::comment_traits::insert_one_statement[] =
  "INSERT INTO \"Stoichiometry_comment\" ("
  "\"object_id\","
  "\"index\","
  "\"value\")"
  " VALUES (:1,:2,:3)";

  const char access::object_traits< ::UniPAX::Stoichiometry >::comment_traits::delete_all_statement[] =
  "DELETE FROM \"Stoichiometry_comment\""
  " WHERE \"object_id\"=:1";

  void access::object_traits< ::UniPAX::Stoichiometry >::
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

    // stoichiometricCoefficient
    //
    b[n].type = oracle::bind::binary_double;
    b[n].buffer= &i.stoichiometricCoefficient_value;
    b[n].capacity = 8;
    b[n].size = 0;
    b[n].indicator = &i.stoichiometricCoefficient_indicator;
    n++;

    // id_physicalEntity
    //
    b[n].type = oracle::bind::number;
    b[n].buffer = i.id_physicalEntity_value;
    b[n].capacity = static_cast<ub4> (sizeof (i.id_physicalEntity_value));
    b[n].size = &i.id_physicalEntity_size;
    b[n].indicator = &i.id_physicalEntity_indicator;
    n++;
  }

  bool access::object_traits< ::UniPAX::Stoichiometry >::
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

    // stoichiometricCoefficient
    //
    {
      bool is_null;
      oracle::value_traits<
          double,
          oracle::id_double >::set_image (
        i.stoichiometricCoefficient_value, is_null, o.stoichiometricCoefficient);
      i.stoichiometricCoefficient_indicator = is_null ? -1 : 0;
    }

    // id_physicalEntity
    //
    {
      bool is_null;
      std::size_t size (0);
      oracle::value_traits<
          long long unsigned int,
          oracle::id_big_int >::set_image (
        i.id_physicalEntity_value,
        size,
        is_null,
        o.id_physicalEntity);
      i.id_physicalEntity_size = static_cast<ub2> (size);
      i.id_physicalEntity_indicator = is_null ? -1 : 0;
    }

    return grew;
  }

  void access::object_traits< ::UniPAX::Stoichiometry >::
  init (object_type& o, const image_type& i, database& db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UtilityClass base
    //
    object_traits< ::UniPAX::UtilityClass >::init (o, i, db);

    // stoichiometricCoefficient
    //
    oracle::value_traits<
        double,
        oracle::id_double >::set_value (
      o.stoichiometricCoefficient,
      i.stoichiometricCoefficient_value,
      i.stoichiometricCoefficient_indicator == -1);

    // id_physicalEntity
    //
    oracle::value_traits<
        long long unsigned int,
        oracle::id_big_int >::set_value (
      o.id_physicalEntity,
      i.id_physicalEntity_value,
      i.id_physicalEntity_size,
      i.id_physicalEntity_indicator == -1);
  }

  struct access::object_traits< ::UniPAX::Stoichiometry >::container_statement_cache_type
  {
    oracle::container_statements_impl< comment_traits > comment;

    container_statement_cache_type (oracle::connection& c)
    : comment (c)
    {
    }
  };

  const char access::object_traits< ::UniPAX::Stoichiometry >::persist_statement[] =
  "INSERT INTO \"Stoichiometry\" ("
  "\"unipaxId\","
  "\"unipaxSource\","
  "\"stoichiometricCoefficient\","
  "\"id_physicalEntity\")"
  " VALUES (:1,:2,:3,:4)";

  const char access::object_traits< ::UniPAX::Stoichiometry >::find_statement[] =
  "SELECT "
  "\"Stoichiometry\".\"unipaxId\","
  "\"Stoichiometry\".\"unipaxSource\","
  "\"Stoichiometry\".\"stoichiometricCoefficient\","
  "\"Stoichiometry\".\"id_physicalEntity\""
  " FROM \"Stoichiometry\""
  " WHERE \"Stoichiometry\".\"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Stoichiometry >::update_statement[] =
  "UPDATE \"Stoichiometry\" SET "
  "\"unipaxSource\"=:1,"
  "\"stoichiometricCoefficient\"=:2,"
  "\"id_physicalEntity\"=:3"
  " WHERE \"unipaxId\"=:4";

  const char access::object_traits< ::UniPAX::Stoichiometry >::erase_statement[] =
  "DELETE FROM \"Stoichiometry\""
  " WHERE \"unipaxId\"=:1";

  const char access::object_traits< ::UniPAX::Stoichiometry >::query_statement[] =
  "SELECT "
  "\"Stoichiometry\".\"unipaxId\","
  "\"Stoichiometry\".\"unipaxSource\","
  "\"Stoichiometry\".\"stoichiometricCoefficient\","
  "\"Stoichiometry\".\"id_physicalEntity\""
  " FROM \"Stoichiometry\""
  " LEFT JOIN \"ImportSource\" \"unipaxSource\" ON \"unipaxSource\".\"unipaxId\" = \"Stoichiometry\".\"unipaxSource\""
  " ";

  const char access::object_traits< ::UniPAX::Stoichiometry >::erase_query_statement[] =
  "DELETE FROM \"Stoichiometry\""
  " ";

  const char access::object_traits< ::UniPAX::Stoichiometry >::table_name[] =
  "\"Stoichiometry\"";

  void access::object_traits< ::UniPAX::Stoichiometry >::
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

  void access::object_traits< ::UniPAX::Stoichiometry >::
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

  void access::object_traits< ::UniPAX::Stoichiometry >::
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

  access::object_traits< ::UniPAX::Stoichiometry >::pointer_type
  access::object_traits< ::UniPAX::Stoichiometry >::
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

  bool access::object_traits< ::UniPAX::Stoichiometry >::
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

  bool access::object_traits< ::UniPAX::Stoichiometry >::
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

  bool access::object_traits< ::UniPAX::Stoichiometry >::
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

  void access::object_traits< ::UniPAX::Stoichiometry >::
  load_ (oracle::object_statements< object_type >& sts, object_type& obj)
  {
    oracle::binding& idb (sts.id_image_binding ());

    comment_traits::load (
      obj.comment,
      idb,
      sts.container_statment_cache ().comment);
  }

  result< access::object_traits< ::UniPAX::Stoichiometry >::object_type >
  access::object_traits< ::UniPAX::Stoichiometry >::
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

  unsigned long long access::object_traits< ::UniPAX::Stoichiometry >::
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
