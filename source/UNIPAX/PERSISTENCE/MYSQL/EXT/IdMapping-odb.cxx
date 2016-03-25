// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include <UNIPAX/PERSISTENCE/MYSQL/EXT/IdMapping-odb.hxx>

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
  // IdMapping
  //

  struct access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::extra_statement_cache_type
  {
    mysql::container_statements_impl< id_list_traits > id_list;

    extra_statement_cache_type (
      mysql::connection& c,
      image_type&,
      id_image_type&,
      mysql::binding& id,
      mysql::binding&)
    : id_list (c, id)
    {
    }
  };

  // id_list
  //

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  select_statement[] =
  "SELECT "
  "`IdMapping_id_list`.`key`, "
  "`IdMapping_id_list`.`value` "
  "FROM `IdMapping_id_list` "
  "WHERE `IdMapping_id_list`.`object_id`=?";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  insert_statement[] =
  "INSERT INTO `IdMapping_id_list` "
  "(`object_id`, "
  "`key`, "
  "`value`) "
  "VALUES "
  "(?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  delete_statement[] =
  "DELETE FROM `IdMapping_id_list` "
  "WHERE `object_id`=?";

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
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

    // key
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &d.key_value;
    b[n].is_null = &d.key_null;
    n++;

    // value
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = d.value_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      d.value_value.capacity ());
    b[n].length = &d.value_size;
    b[n].is_null = &d.value_null;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  grow (data_image_type& i,
        my_bool* t)
  {
    bool grew (false);

    // key
    //
    t[0UL] = 0;

    // value
    //
    if (t[1UL])
    {
      i.value_value.capacity (i.value_size);
      grew = true;
    }

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  init (data_image_type& i,
        const key_type* k,
        const value_type& v)
  {
    using namespace mysql;

    statement_kind sk (statement_insert);
    ODB_POTENTIALLY_UNUSED (sk);

    bool grew (false);

    // key
    //
    if (k != 0)
    {
      bool is_null (false);
      mysql::value_traits<
          key_type,
          mysql::id_long >::set_image (
        i.key_value, is_null, *k);
      i.key_null = is_null;
    }

    // value
    //
    {
      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.value_value.capacity ());
      mysql::value_traits<
          value_type,
          mysql::id_string >::set_image (
        i.value_value,
        size,
        is_null,
        v);
      i.value_null = is_null;
      i.value_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.value_value.capacity ());
    }

    if (grew)
      i.version++;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  init (key_type& k,
        value_type& v,
        const data_image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (db);

    // key
    //
    {
      mysql::value_traits<
          key_type,
          mysql::id_long >::set_value (
        k,
        i.key_value,
        i.key_null);
    }

    // value
    //
    {
      mysql::value_traits<
          value_type,
          mysql::id_string >::set_value (
        v,
        i.value_value,
        i.value_size,
        i.value_null);
    }
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  insert (const key_type& k, const value_type& v, void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (di, &k, v);

    if (sts.data_binding_test_version ())
    {
      const binding& id (sts.id_binding ());
      bind (sts.data_bind (), id.bind, id.count, di);
      sts.data_binding_update_version ();
    }

    if (!sts.insert_statement ().execute ())
      throw object_already_persistent ();
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  select (key_type& k, value_type& v, void* d)
  {
    using namespace mysql;
    using mysql::select_statement;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (k, v, di, &sts.connection ().database ());

    select_statement& st (sts.select_statement ());
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      grow (di, sts.select_image_truncated ());

      if (sts.data_binding_test_version ())
      {
        bind (sts.data_bind (), 0, sts.id_binding ().count, di);
        sts.data_binding_update_version ();
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  delete_ (void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_statement ().execute ();
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  persist (const container_type& c,
           statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::persist (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
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
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      data_image_type& di (sts.data_image ());
      grow (di, sts.select_image_truncated ());

      if (sts.data_binding_test_version ())
      {
        bind (sts.data_bind (), 0, id.count, di);
        sts.data_binding_update_version ();
        st.refetch ();
      }
    }

    bool more (r != select_statement::no_data);

    functions_type& fs (sts.functions ());
    container_traits_type::load (c, more, fs);
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  update (const container_type& c,
          statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::update (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::id_list_traits::
  erase (statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    container_traits_type::erase (fs);
  }

  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::discriminator_type
  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  discriminator (const image_type& i)
  {
    mysql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    discriminator_type d;
    {
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        d,
        i.typeid_value,
        i.typeid_size,
        i.typeid_null);
    }

    return d;
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // UPBase base
    //
    if (object_traits_impl< ::UniPAX::UPBase, id_mysql >::grow (
          i, t + 0UL))
      grew = true;

    // typeid_
    //
    if (t[1UL])
    {
      i.typeid_value.capacity (i.typeid_size);
      grew = true;
    }

    // sample_index
    //
    t[2UL] = 0;

    // db_name
    //
    if (t[3UL])
    {
      i.db_name_value.capacity (i.db_name_size);
      grew = true;
    }

    // db_version
    //
    if (t[4UL])
    {
      i.db_version_value.capacity (i.db_version_size);
      grew = true;
    }

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // UPBase base
    //
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::bind (b + n, i, sk);
    n += sk == statement_update ? 0UL : 1UL;

    // typeid_
    //
    if (sk != statement_update)
    {
      b[n].buffer_type = MYSQL_TYPE_STRING;
      b[n].buffer = i.typeid_value.data ();
      b[n].buffer_length = static_cast<unsigned long> (
        i.typeid_value.capacity ());
      b[n].length = &i.typeid_size;
      b[n].is_null = &i.typeid_null;
      n++;
    }

    // sample_index
    //
    b[n].buffer_type = MYSQL_TYPE_LONG;
    b[n].is_unsigned = 0;
    b[n].buffer = &i.sample_index_value;
    b[n].is_null = &i.sample_index_null;
    n++;

    // db_name
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.db_name_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.db_name_value.capacity ());
    b[n].length = &i.db_name_size;
    b[n].is_null = &i.db_name_null;
    n++;

    // db_version
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.db_version_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.db_version_value.capacity ());
    b[n].length = &i.db_version_size;
    b[n].is_null = &i.db_version_null;
    n++;
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // UPBase base
    //
    if (object_traits_impl< ::UniPAX::UPBase, id_mysql >::init (i, o, sk))
      grew = true;

    // typeid_
    //
    if (sk == statement_insert)
    {
      const info_type& di (map->find (typeid (o)));

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.typeid_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.typeid_value,
        size,
        is_null,
        di.discriminator);
      i.typeid_null = is_null;
      i.typeid_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.typeid_value.capacity ());
    }

    // sample_index
    //
    {
      int const& v =
        o.sample_index;

      bool is_null (false);
      mysql::value_traits<
          int,
          mysql::id_long >::set_image (
        i.sample_index_value, is_null, v);
      i.sample_index_null = is_null;
    }

    // db_name
    //
    {
      ::std::string const& v =
        o.db_name;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.db_name_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.db_name_value,
        size,
        is_null,
        v);
      i.db_name_null = is_null;
      i.db_name_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.db_name_value.capacity ());
    }

    // db_version
    //
    {
      ::std::string const& v =
        o.db_version;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.db_version_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.db_version_value,
        size,
        is_null,
        v);
      i.db_version_null = is_null;
      i.db_version_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.db_version_value.capacity ());
    }

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UPBase base
    //
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::init (o, i, db);

    // sample_index
    //
    {
      int& v =
        o.sample_index;

      mysql::value_traits<
          int,
          mysql::id_long >::set_value (
        v,
        i.sample_index_value,
        i.sample_index_null);
    }

    // db_name
    //
    {
      ::std::string& v =
        o.db_name;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.db_name_value,
        i.db_name_size,
        i.db_name_null);
    }

    // db_version
    //
    {
      ::std::string& v =
        o.db_version;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.db_version_value,
        i.db_version_size,
        i.db_version_null);
    }
  }

  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::map_type*
  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::map;

  const access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::info_type
  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::info (
    typeid (::UniPAX::IdMapping),
    0,
    0,
    "UniPAX::IdMapping",
    &odb::create_impl< ::UniPAX::IdMapping >,
    &odb::dispatch_impl< ::UniPAX::IdMapping, id_mysql >,
    0);

  static const access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::entry_type
  polymorphic_entry_for_UniPAX_IdMapping;

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::persist_statement[] =
  "INSERT INTO `IdMapping` "
  "(`unipaxId`, "
  "`typeid`, "
  "`sample_index`, "
  "`db_name`, "
  "`db_version`) "
  "VALUES "
  "(?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::find_statement[] =
  "SELECT "
  "`IdMapping`.`unipaxId`, "
  "`IdMapping`.`typeid`, "
  "`IdMapping`.`sample_index`, "
  "`IdMapping`.`db_name`, "
  "`IdMapping`.`db_version` "
  "FROM `IdMapping` "
  "WHERE `IdMapping`.`unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  find_discriminator_statement[] =
  "SELECT "
  "`IdMapping`.`typeid` "
  "FROM `IdMapping` "
  "WHERE `IdMapping`.`unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::update_statement[] =
  "UPDATE `IdMapping` "
  "SET "
  "`sample_index`=?, "
  "`db_name`=?, "
  "`db_version`=? "
  "WHERE `unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::erase_statement[] =
  "DELETE FROM `IdMapping` "
  "WHERE `unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::query_statement[] =
  "SELECT "
  "`IdMapping`.`unipaxId`, "
  "`IdMapping`.`typeid`, "
  "`IdMapping`.`sample_index`, "
  "`IdMapping`.`db_name`, "
  "`IdMapping`.`db_version` "
  "FROM `IdMapping`";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::erase_query_statement[] =
  "DELETE FROM `IdMapping`";

  const char access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::table_name[] =
  "`IdMapping`";

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
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

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // id_list
    //
    {
      ::std::multimap< int, ::std::basic_string< char > > const& v =
        obj.id_list;

      id_list_traits::persist (
        v,
        esc.id_list);
    }

    if (top)
      callback (db,
                obj,
                callback_event::post_persist);
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

    const id_type& id (
      obj.unipaxId);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // id_list
    //
    {
      ::std::multimap< int, ::std::basic_string< char > > const& v =
        obj.id_list;

      id_list_traits::update (
        v,
        esc.id_list);
    }

    if (top)
    {
      callback (db, obj, callback_event::post_update);
      pointer_cache_traits::update (db, obj);
    }
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

    // id_list
    //
    id_list_traits::erase (
      esc.id_list);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    if (top)
      pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::pointer_type
  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  find (database& db, const id_type& id)
  {
    using namespace mysql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mysql::connection& conn (
      mysql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    root_traits::discriminator_type d;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
      d = root_traits::discriminator (sts.image ());
    }
    else
      root_traits::discriminator_ (sts, id, &d);

    const info_type& pi (
      d == info.discriminator ? info : root_traits::map->find (d));

    pointer_type p (pi.create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
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

      sts.load_delayed (0);
      l.unlock ();
      ce = callback_event::post_load;
      pi.dispatch (info_type::call_callback, db, &obj, &ce);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position (), pi.delayed_loader);

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.unipaxId);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mysql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // id_list
    //
    {
      ::std::multimap< int, ::std::basic_string< char > >& v =
        obj.id_list;

      id_list_traits::load (
        v,
        esc.id_list);
    }
  }

  void access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
  discriminator_ (statements_type& sts,
                  const id_type& id,
                  discriminator_type* pd)
  {
    using namespace mysql;

    id_image_type& idi (sts.discriminator_id_image ());
    init (idi, id);

    binding& idb (sts.discriminator_id_image_binding ());
    if (idi.version != sts.discriminator_id_image_version () ||
        idb.version == 0)
    {
      bind (idb.bind, idi);
      sts.discriminator_id_image_version (idi.version);
      idb.version++;
    }

    discriminator_image_type& i (sts.discriminator_image ());
    binding& imb (sts.discriminator_image_binding ());

    if (i.version != sts.discriminator_image_version () ||
        imb.version == 0)
    {
      MYSQL_BIND* b (imb.bind);
      std::size_t n (0);
      {
        b[n].buffer_type = MYSQL_TYPE_STRING;
        b[n].buffer = i.discriminator_value.data ();
        b[n].buffer_length = static_cast<unsigned long> (
          i.discriminator_value.capacity ());
        b[n].length = &i.discriminator_size;
        b[n].is_null = &i.discriminator_null;
      }

      sts.discriminator_image_version (i.version);
      imb.version++;
    }

    {
      select_statement& st (sts.find_discriminator_statement ());
      st.execute ();
      auto_result ar (st);
      select_statement::result r (st.fetch ());

      if (r == select_statement::no_data)
      {
        throw object_not_persistent ();
      }
      else if (r == select_statement::truncated)
      {
        bool grew (false);
        my_bool* t (sts.discriminator_image_truncated ());

        if (t[0UL])
        {
          i.discriminator_value.capacity (i.discriminator_size);
          grew = true;
        }

        if (grew)
          i.version++;

        if (i.version != sts.discriminator_image_version ())
        {
          MYSQL_BIND* b (imb.bind);
          std::size_t n (0);
          {
            b[n].buffer_type = MYSQL_TYPE_STRING;
            b[n].buffer = i.discriminator_value.data ();
            b[n].buffer_length = static_cast<unsigned long> (
              i.discriminator_value.capacity ());
            b[n].length = &i.discriminator_size;
            b[n].is_null = &i.discriminator_null;
          }

          sts.discriminator_image_version (i.version);
          imb.version++;
          st.refetch ();
        }
      }
    }

    if (pd != 0)
    {
      discriminator_type& d (*pd);
      {
        mysql::value_traits<
            ::std::string,
            mysql::id_string >::set_value (
          d,
          i.discriminator_value,
          i.discriminator_size,
          i.discriminator_null);
      }
    }
  }

  result< access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::object_type >
  access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::polymorphic_object_result_impl<object_type> > r (
      new (shared) mysql::polymorphic_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::UniPAX::IdMapping, id_mysql >::
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
