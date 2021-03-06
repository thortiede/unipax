// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ControlledVocabulary-odb.hxx>

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
  // ControlledVocabulary
  //

  struct access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::extra_statement_cache_type
  {
    mysql::container_statements_impl< comment_traits > comment;
    mysql::container_statements_impl< xref_traits > xref;

    extra_statement_cache_type (
      mysql::connection& c,
      image_type&,
      id_image_type&,
      mysql::binding& id,
      mysql::binding&)
    : comment (c, id),
      xref (c, id)
    {
    }
  };

  // comment
  //

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::comment_traits::
  select_statement[] =
  "SELECT "
  "`ControlledVocabulary_comment`.`index`, "
  "`ControlledVocabulary_comment`.`value` "
  "FROM `ControlledVocabulary_comment` "
  "WHERE `ControlledVocabulary_comment`.`object_id`=? ORDER BY `ControlledVocabulary_comment`.`index`";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::comment_traits::
  insert_statement[] =
  "INSERT INTO `ControlledVocabulary_comment` "
  "(`object_id`, "
  "`index`, "
  "`value`) "
  "VALUES "
  "(?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::comment_traits::
  delete_statement[] =
  "DELETE FROM `ControlledVocabulary_comment` "
  "WHERE `object_id`=?";

  // xref
  //

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  select_statement[] =
  "SELECT "
  "`ControlledVocabulary_xref`.`index`, "
  "`ControlledVocabulary_xref`.`value` "
  "FROM `ControlledVocabulary_xref` "
  "WHERE `ControlledVocabulary_xref`.`object_id`=? ORDER BY `ControlledVocabulary_xref`.`index`";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  insert_statement[] =
  "INSERT INTO `ControlledVocabulary_xref` "
  "(`object_id`, "
  "`index`, "
  "`value`) "
  "VALUES "
  "(?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  delete_statement[] =
  "DELETE FROM `ControlledVocabulary_xref` "
  "WHERE `object_id`=?";

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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
      typedef object_traits< ::UniPAX::Xref > obj_traits;
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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
      typedef object_traits< ::UniPAX::Xref > obj_traits;
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  delete_ (void* d)
  {
    using namespace mysql;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_statement ().execute ();
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  persist (const container_type& c,
           statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::persist (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  update (const container_type& c,
          statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::update (c, fs);
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::xref_traits::
  erase (statements_type& sts)
  {
    using namespace mysql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::erase (fs);
  }

  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::discriminator_type
  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  grow (image_type& i,
        my_bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // UtilityClass base
    //
    if (object_traits_impl< ::UniPAX::UtilityClass, id_mysql >::grow (
          i, t + 0UL))
      grew = true;

    // typeid_
    //
    if (t[2UL])
    {
      i.typeid_value.capacity (i.typeid_size);
      grew = true;
    }

    // term
    //
    if (t[3UL])
    {
      i.term_value.capacity (i.term_size);
      grew = true;
    }

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  bind (MYSQL_BIND* b,
        image_type& i,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    std::size_t n (0);

    // UtilityClass base
    //
    object_traits_impl< ::UniPAX::UtilityClass, id_mysql >::bind (b + n, i, sk);
    n += sk == statement_update ? 1UL : 2UL;

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

    // term
    //
    b[n].buffer_type = MYSQL_TYPE_STRING;
    b[n].buffer = i.term_value.data ();
    b[n].buffer_length = static_cast<unsigned long> (
      i.term_value.capacity ());
    b[n].length = &i.term_size;
    b[n].is_null = &i.term_null;
    n++;
  }

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  init (image_type& i,
        const object_type& o,
        mysql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mysql;

    bool grew (false);

    // UtilityClass base
    //
    if (object_traits_impl< ::UniPAX::UtilityClass, id_mysql >::init (i, o, sk))
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

    // term
    //
    {
      ::std::string const& v =
        o.term;

      bool is_null (false);
      std::size_t size (0);
      std::size_t cap (i.term_value.capacity ());
      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_image (
        i.term_value,
        size,
        is_null,
        v);
      i.term_null = is_null;
      i.term_size = static_cast<unsigned long> (size);
      grew = grew || (cap != i.term_value.capacity ());
    }

    return grew;
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // UtilityClass base
    //
    object_traits_impl< ::UniPAX::UtilityClass, id_mysql >::init (o, i, db);

    // term
    //
    {
      ::std::string& v =
        o.term;

      mysql::value_traits<
          ::std::string,
          mysql::id_string >::set_value (
        v,
        i.term_value,
        i.term_size,
        i.term_null);
    }
  }

  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::map_type*
  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::map;

  const access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::info_type
  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::info (
    typeid (::UniPAX::ControlledVocabulary),
    0,
    0,
    "UniPAX::ControlledVocabulary",
    &odb::create_impl< ::UniPAX::ControlledVocabulary >,
    &odb::dispatch_impl< ::UniPAX::ControlledVocabulary, id_mysql >,
    0);

  static const access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::entry_type
  polymorphic_entry_for_UniPAX_ControlledVocabulary;

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::persist_statement[] =
  "INSERT INTO `ControlledVocabulary` "
  "(`unipaxId`, "
  "`unipaxSource`, "
  "`typeid`, "
  "`term`) "
  "VALUES "
  "(?, ?, ?, ?)";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::find_statement[] =
  "SELECT "
  "`ControlledVocabulary`.`unipaxId`, "
  "`ControlledVocabulary`.`unipaxSource`, "
  "`ControlledVocabulary`.`typeid`, "
  "`ControlledVocabulary`.`term` "
  "FROM `ControlledVocabulary` "
  "WHERE `ControlledVocabulary`.`unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  find_discriminator_statement[] =
  "SELECT "
  "`ControlledVocabulary`.`typeid` "
  "FROM `ControlledVocabulary` "
  "WHERE `ControlledVocabulary`.`unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::update_statement[] =
  "UPDATE `ControlledVocabulary` "
  "SET "
  "`unipaxSource`=?, "
  "`term`=? "
  "WHERE `unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::erase_statement[] =
  "DELETE FROM `ControlledVocabulary` "
  "WHERE `unipaxId`=?";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::query_statement[] =
  "SELECT\n"
  "`ControlledVocabulary`.`unipaxId`,\n"
  "`ControlledVocabulary`.`unipaxSource`,\n"
  "`ControlledVocabulary`.`typeid`,\n"
  "`ControlledVocabulary`.`term`\n"
  "FROM `ControlledVocabulary`\n"
  "LEFT JOIN `ImportSource` AS `unipaxSource_ImportSource` ON `unipaxSource_ImportSource`.`unipaxId`=`ControlledVocabulary`.`unipaxSource`";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::erase_query_statement[] =
  "DELETE FROM `ControlledVocabulary`";

  const char access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::table_name[] =
  "`ControlledVocabulary`";

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

    // comment
    //
    {
      ::std::vector< ::std::basic_string< char > > const& v =
        obj.comment;

      comment_traits::persist (
        v,
        esc.comment);
    }

    // xref
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::Xref > > const& v =
        obj.xref;

      xref_traits::persist (
        v,
        esc.xref);
    }

    if (top)
      callback (db,
                obj,
                callback_event::post_persist);
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

    // comment
    //
    {
      ::std::vector< ::std::basic_string< char > > const& v =
        obj.comment;

      comment_traits::update (
        v,
        esc.comment);
    }

    // xref
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::Xref > > const& v =
        obj.xref;

      xref_traits::update (
        v,
        esc.xref);
    }

    if (top)
    {
      callback (db, obj, callback_event::post_update);
      pointer_cache_traits::update (db, obj);
    }
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

    // comment
    //
    comment_traits::erase (
      esc.comment);

    // xref
    //
    xref_traits::erase (
      esc.xref);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    if (top)
      pointer_cache_traits::erase (db, id);
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::pointer_type
  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  bool access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // comment
    //
    {
      ::std::vector< ::std::basic_string< char > >& v =
        obj.comment;

      comment_traits::load (
        v,
        esc.comment);
    }

    // xref
    //
    {
      ::std::vector< ::boost::shared_ptr< ::UniPAX::Xref > >& v =
        obj.xref;

      xref_traits::load (
        v,
        esc.xref);
    }
  }

  void access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  result< access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::object_type >
  access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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

  unsigned long long access::object_traits_impl< ::UniPAX::ControlledVocabulary, id_mysql >::
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
