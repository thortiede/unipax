// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SmallMolecule-odb.hxx>

#include <cassert>
#include <cstring>  // std::memcpy
#include <typeinfo>

#include <odb/polymorphic-map.hxx>

#include <odb/mysql/traits.hxx>
#include <odb/mysql/database.hxx>
#include <odb/mysql/transaction.hxx>
#include <odb/mysql/connection.hxx>
#include <odb/mysql/statement.hxx>
#include <odb/mysql/statement-cache.hxx>
#include <odb/mysql/polymorphic-object-statements.hxx>
#include <odb/mysql/container-statements.hxx>
#include <odb/mysql/exceptions.hxx>
#include <odb/mysql/polymorphic-object-result.hxx>
#include <odb/mysql/enum.hxx>

namespace odb
{
  // SmallMolecule
  //

  struct access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::extra_statement_cache_type
  {
    mysql::container_statements_impl< entityReference_traits > entityReference;

    extra_statement_cache_type (
      mysql::connection& c,
      image_type&,
      id_image_type&,
      mysql::binding& id,
      mysql::binding&)
    : entityReference (c, id)
    {
    }
  };

  // entityReference
  //

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  select_statement[] =
  "SELECT "
  "`SmallMolecule_entityReference`.`index`, "
  "`SmallMolecule_entityReference`.`value` "
  "FROM `SmallMolecule_entityReference` "
  "WHERE `SmallMolecule_entityReference`.`object_id`=? ORDER BY `SmallMolecule_entityReference`.`index`";

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  insert_statement[] =
  "INSERT INTO `SmallMolecule_entityReference` "
  "(`object_id`, "
  "`index`, "
  "`value`) "
  "VALUES "
  "(?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  delete_statement[] =
  "DELETE FROM `SmallMolecule_entityReference` "
  "WHERE `object_id`=?";

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  bind (MYSQL_BIND* b,
        const MYSQL_BIND* id,
        std::size_t id_size,
        data_image_type& d)
  {
    using namespace mysql;

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
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &d.index_value;
    b[n].is_null = &d.index_null;
    n++;

    // value
    //
    b[n].buffer_type = MYSQL_TYPE_LONGLONG;
    b[n].is_unsigned = 1;
    b[n].buffer = &d.value_value;
    b[n].is_null = &d.value_null;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  grow (data_image_type& i,
        my_bool* t)
  {
    bool grew (false);

    // index
    //
    t[0UL] = 0;

    // value
    //
    t[1UL] = 0;

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  init (data_image_type& i,
        index_type* j,
        const value_type& v)
  {
    using namespace mysql;

    statement_kind sk (statement_insert);
    ODB_POTENTIALLY_UNUSED (sk);

    bool grew (false);

    // index
    //
    if (j != 0)
    {
      bool is_null (false);
      mysql::value_traits<
          index_type,
          mysql::id_ulonglong >::set_image (
        i.index_value, is_null, *j);
      i.index_null = is_null;
    }

    // value
    //
    {
      typedef object_traits< ::UniPAX::EntityReference > obj_traits;
      typedef odb::pointer_traits< value_type > ptr_traits;

      bool is_null (ptr_traits::null_ptr (v));
      if (!is_null)
      {
        const obj_traits::id_type& id (
          obj_traits::id (ptr_traits::get_ref (v)));

        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_image (
          i.value_value, is_null, id);
        i.value_null = is_null;
      }
      else
        i.value_null = 1;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  init (index_type& j,
        value_type& v,
        const data_image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (db);

    // index
    //
    {
      mysql::value_traits<
          index_type,
          mysql::id_ulonglong >::set_value (
        j,
        i.index_value,
        i.index_null);
    }

    // value
    //
    {
      typedef object_traits< ::UniPAX::EntityReference > obj_traits;
      typedef odb::pointer_traits< value_type > ptr_traits;

      if (i.value_null)
        v = ptr_traits::pointer_type ();
      else
      {
        obj_traits::id_type id;
        mysql::value_traits<
            obj_traits::id_type,
            mysql::id_ulonglong >::set_value (
          id,
          i.value_value,
          i.value_null);

        // If a compiler error points to the line below, then
        // it most likely means that a pointer used in a member
        // cannot be initialized from an object pointer.
        //
        v = ptr_traits::pointer_type (
          static_cast<mysql::database*> (db)->load<
            obj_traits::object_type > (id));
      }
    }
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  insert (index_type i, const value_type& v, void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (di, &i, v);

    if (sts.data_binding_test_version ())
    {
      const binding& id (sts.id_binding ());
      bind (sts.data_bind (), id.bind, id.count, di);
      sts.data_binding_update_version ();
    }

    if (!sts.insert_statement ().execute ())
      throw object_already_persistent ();
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  select (index_type& i, value_type& v, void* d)
  {
    using namespace mysql;
    using mysql::select_statement;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (i, v, di, &sts.connection ().database ());

    if (sts.data_binding_test_version ())
    {
      const binding& id (sts.id_binding ());
      bind (sts.data_bind (), id.bind, id.count, di);
      sts.data_binding_update_version ();
    }

    select_statement& st (sts.select_statement ());
    select_statement::result r (st.fetch ());
    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  delete_ (void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_statement ().execute ();
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  persist (const container_type& c,
           statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::persist (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  load (container_type& c,
        statements_type& sts)
  {
    using namespace mysql;
    using mysql::select_statement;

    const binding& id (sts.id_binding ());

    if (sts.data_binding_test_version ())
    {
      bind (sts.data_bind (), id.bind, id.count, sts.data_image ());
      sts.data_binding_update_version ();
    }

    select_statement& st (sts.select_statement ());
    st.execute ();
    auto_result ar (st);
    st.cache ();
    select_statement::result r (st.fetch ());
    bool more (r != select_statement::no_data);

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::load (c, more, fs);
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  update (const container_type& c,
          statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::update (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entityReference_traits::
  erase (statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::erase (fs);
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  grow (image_type& i,
        my_bool* t,
        std::size_t d)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // PhysicalEntity base
    //
    if (--d != 0)
    {
      if (base_traits::grow (*i.base, t + 0UL, d))
        i.base->version++;
    }

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  bind (MYSQL_BIND* b,
        const MYSQL_BIND* id,
        std::size_t id_size,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // unipaxId
    //
    if (sk == statement_insert)
    {
      if (id != 0)
        std::memcpy (&b[n], id, id_size * sizeof (id[0]));
      n += id_size;
    }

    // unipaxId
    //
    if (sk == statement_update)
    {
      if (id != 0)
        std::memcpy (&b[n], id, id_size * sizeof (id[0]));
      n += id_size;
    }

    // PhysicalEntity base
    //
    if (sk == statement_select)
      base_traits::bind (b + n, id, id_size, *i.base, sk);
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db,
        std::size_t d)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // PhysicalEntity base
    //
    if (--d != 0)
      base_traits::init (o, *i.base, db, d);
  }

  const access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::info_type
  access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::info (
    typeid (::UniPAX::SmallMolecule),
    &object_traits_impl< ::UniPAX::PhysicalEntity, id_mysql >::info,
    0,
    "UniPAX::SmallMolecule",
    &odb::create_impl< ::UniPAX::SmallMolecule >,
    &odb::dispatch_impl< ::UniPAX::SmallMolecule, id_mysql >,
    &statements_type::delayed_loader);

  static const access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::entry_type
  polymorphic_entry_for_UniPAX_SmallMolecule;

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::persist_statement[] =
  "INSERT INTO `SmallMolecule` "
  "(`unipaxId`) "
  "VALUES "
  "(?)";

  const char* const access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::find_statements[] =
  {
    "SELECT "
    "`PhysicalEntity`.`cellularLocation`, "
    "`Entity`.`unipaxId`, "
    "`Entity`.`unipaxSource`, "
    "`Entity`.`typeid`, "
    "`Entity`.`availability`, "
    "`Entity`.`standardName`, "
    "`Entity`.`displayName`, "
    "`Entity`.`evidence`, "
    "`Entity`.`dataSource` "
    "FROM `SmallMolecule` "
    "LEFT JOIN `PhysicalEntity` ON `PhysicalEntity`.`unipaxId`=`SmallMolecule`.`unipaxId` "
    "LEFT JOIN `Entity` ON `Entity`.`unipaxId`=`SmallMolecule`.`unipaxId` "
    "WHERE `SmallMolecule`.`unipaxId`=?",

    "SELECT "
    "`PhysicalEntity`.`cellularLocation` "
    "FROM `SmallMolecule` "
    "LEFT JOIN `PhysicalEntity` ON `PhysicalEntity`.`unipaxId`=`SmallMolecule`.`unipaxId` "
    "WHERE `SmallMolecule`.`unipaxId`=?",

    ""
  };

  const std::size_t access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::find_column_counts[] =
  {
    9UL,
    1UL,
    0UL
  };

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::erase_statement[] =
  "DELETE FROM `SmallMolecule` "
  "WHERE `unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::query_statement[] =
  "SELECT\n"
  "`PhysicalEntity`.`cellularLocation`,\n"
  "`Entity`.`unipaxId`,\n"
  "`Entity`.`unipaxSource`,\n"
  "`Entity`.`typeid`,\n"
  "`Entity`.`availability`,\n"
  "`Entity`.`standardName`,\n"
  "`Entity`.`displayName`,\n"
  "`Entity`.`evidence`,\n"
  "`Entity`.`dataSource`\n"
  "FROM `SmallMolecule`\n"
  "LEFT JOIN `PhysicalEntity` ON `PhysicalEntity`.`unipaxId`=`SmallMolecule`.`unipaxId`\n"
  "LEFT JOIN `Entity` ON `Entity`.`unipaxId`=`SmallMolecule`.`unipaxId`\n"
  "LEFT JOIN `CellularLocationVocabulary` AS `cellularLocation_CellularLocationVocabulary` ON `cellularLocation_CellularLocationVocabulary`.`unipaxId`=`PhysicalEntity`.`cellularLocation`\n"
  "LEFT JOIN `ControlledVocabulary` AS `cellularLocation_ControlledVocabulary` ON `cellularLocation_ControlledVocabulary`.`unipaxId`=`cellularLocation_CellularLocationVocabulary`.`unipaxId`\n"
  "LEFT JOIN `ImportSource` AS `unipaxSource_ImportSource` ON `unipaxSource_ImportSource`.`unipaxId`=`Entity`.`unipaxSource`\n"
  "LEFT JOIN `Evidence` AS `evidence_Evidence` ON `evidence_Evidence`.`unipaxId`=`Entity`.`evidence`\n"
  "LEFT JOIN `Provenance` AS `dataSource_Provenance` ON `dataSource_Provenance`.`unipaxId`=`Entity`.`dataSource`";

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::erase_query_statement[] =
  "DELETE FROM `SmallMolecule`";

  const char access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::table_name[] =
  "`SmallMolecule`";

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  persist (database& db, const object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    using namespace mysql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_persist, db, &obj, 0);
        return;
      }
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    if (top)
      callback (db,
                obj,
                callback_event::pre_persist);

    base_traits::persist (db, obj, false, false);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());
    const binding& idb (sts.id_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (idb.version != sts.insert_id_binding_version () ||
        im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, idb.bind, idb.count, im, statement_insert);
      sts.insert_id_binding_version (idb.version);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // entityReference
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::EntityReference > > const& v =
        obj.entityReference;

      entityReference_traits::persist (
        v,
        esc.entityReference);
    }

    if (top)
      callback (db,
                obj,
                callback_event::post_persist);
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  update (database& db, const object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    using namespace mysql;
    using mysql::update_statement;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_update, db, &obj, 0);
        return;
      }
    }

    if (top)
      callback (db, obj, callback_event::pre_update);

    mysql::transaction& tr (mysql::transaction::current ());
    mysql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    base_traits::update (db, obj, false, false);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // entityReference
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::EntityReference > > const& v =
        obj.entityReference;

      entityReference_traits::update (
        v,
        esc.entityReference);
    }

    if (top)
    {
      callback (db, obj, callback_event::post_update);
      pointer_cache_traits::update (db, obj);
    }
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  erase (database& db, const id_type& id, bool top, bool dyn)
  {
    using namespace mysql;

    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    if (dyn)
    {
      discriminator_type d;
      root_traits::discriminator_ (sts.root_statements (), id, &d);

      if (d != info.discriminator)
      {
        const info_type& pi (root_traits::map->find (d));

        if (!pi.derived (info))
          throw object_not_persistent ();

        pi.dispatch (info_type::call_erase, db, 0, &id);
        return;
      }
    }

    if (top)
    {
      id_image_type& i (sts.id_image ());
      init (i, id);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
      }
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // entityReference
    //
    entityReference_traits::erase (
      esc.entityReference);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    base_traits::erase (db, id, false, false);

    if (top)
      pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  erase (database& db, const object_type& obj, bool top, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (top);

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        pi.dispatch (info_type::call_erase, db, &obj, 0);
        return;
      }
    }

    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj), true, false);
    callback (db, obj, callback_event::post_erase);
  }

  access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::pointer_type
  access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      root_traits::pointer_type rp (pointer_cache_traits::find (db, id));

      if (!root_traits::pointer_traits::null_ptr (rp))
        return
          root_traits::pointer_traits::dynamic_pointer_cast<object_type> (rp);
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);
    root_traits::discriminator_type d;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
      d = root_traits::discriminator (rsts.image ());
    }
    else
      root_traits::discriminator_ (rsts, id, &d);

    const info_type& pi (
      d == info.discriminator ? info : root_traits::map->find (d));

    root_traits::pointer_type rp (pi.create ());
    pointer_type p (
      root_traits::pointer_traits::static_pointer_cast<object_type> (rp));
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, rp));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement (depth));
      ODB_POTENTIALLY_UNUSED (st);

      callback_event ce (callback_event::pre_load);
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);

      if (&pi != &info)
      {
        std::size_t d (depth);
        pi.dispatch (info_type::call_load, db, &obj, &d);
      }

      rsts.load_delayed (0);
      l.unlock ();
      ce = callback_event::post_load;
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      pointer_cache_traits::load (ig.position ());
    }
    else
      rsts.delay_load (id, obj, ig.position (), pi.delayed_loader);

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  find (database& db, const id_type& id, object_type& obj, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (dyn);

    using namespace mysql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        return pi.dispatch (info_type::call_find, db, &obj, &id);
      }
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement (depth));
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    rsts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  reload (database& db, object_type& obj, bool dyn)
  {
    ODB_POTENTIALLY_UNUSED (dyn);

    using namespace mysql;

    if (dyn)
    {
      const std::type_info& t (typeid (obj));

      if (t != info.type)
      {
        const info_type& pi (root_traits::map->find (t));
        return pi.dispatch (info_type::call_reload, db, &obj, 0);
      }
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());
    root_statements_type& rsts (sts.root_statements ());

    statements_type::auto_lock l (rsts);

    const id_type& id  (
      obj.unipaxId);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement (depth));
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    rsts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id,
         std::size_t d)
  {
    using namespace mysql;

    if (d == depth)
    {
      id_image_type& i (sts.id_image ());
      init (i, *id);

      binding& idb (sts.id_image_binding ());
      if (i.version != sts.id_image_version () || idb.version == 0)
      {
        bind (idb.bind, i);
        sts.id_image_version (i.version);
        idb.version++;
      }
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding (d));

    if (imb.version == 0 ||
        check_version (sts.select_image_versions (), im))
    {
      bind (imb.bind, 0, 0, im, statement_select);
      update_version (sts.select_image_versions (),
                      im,
                      sts.select_image_bindings ());
    }

    select_statement& st (sts.find_statement (d));

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated (), d))
        im.version++;

      if (check_version (sts.select_image_versions (), im))
      {
        bind (imb.bind, 0, 0, im, statement_select);
        update_version (sts.select_image_versions (),
                        im,
                        sts.select_image_bindings ());
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload,
         std::size_t d)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    if (--d != 0)
      base_traits::load_ (sts.base_statements (), obj, reload, d);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // entityReference
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::EntityReference > >& v =
        obj.entityReference;

      entityReference_traits::load (
        v,
        esc.entityReference);
    }
  }

  void access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  load_ (database& db, root_type& r, std::size_t d)
  {
    using namespace mysql;

    object_type& obj (static_cast<object_type&> (r));
    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    d = depth - d;

    if (d > 1UL)
    {
      if (!find_ (sts, 0, d))
        throw object_not_persistent ();

      select_statement& st (sts.find_statement (d));
      ODB_POTENTIALLY_UNUSED (st);

      init (obj, sts.image (), &db, d);
    }

    load_ (sts, obj, false, d);
  }

  result< access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::object_type >
  access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  query (database&, const query_base_type& q)
  {
    using namespace mysql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding (depth));

    if (imb.version == 0 ||
        check_version (sts.select_image_versions (), im))
    {
      bind (imb.bind, 0, 0, im, statement_select);
      update_version (sts.select_image_versions (),
                      im,
                      sts.select_image_bindings ());
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += "\n";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        true,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::polymorphic_object_result_impl<object_type> > r (
      new (shared) mysql::polymorphic_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::UniPAX::SmallMolecule, id_mysql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mysql;

    mysql::connection& conn (
      mysql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>
