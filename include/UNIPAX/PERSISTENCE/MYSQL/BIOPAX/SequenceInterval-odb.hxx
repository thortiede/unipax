// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef SEQUENCE_INTERVAL_ODB_HXX
#define SEQUENCE_INTERVAL_ODB_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include <UNIPAX/KERNEL/BIOPAX/SequenceInterval.h>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceLocation-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceSite-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Thing-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/UtilityClass-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/ImportSource-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/UIBase-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/UPBase-odb.hxx>

#include <memory>
#include <cstddef>
#include <string>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#ifdef BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <odb/tr1/wrapper-traits.hxx>
#  include <odb/tr1/pointer-traits.hxx>
#endif
#include <odb/container-traits.hxx>
#include <odb/session.hxx>
#include <odb/cache-traits.hxx>
#include <odb/polymorphic-info.hxx>
#include <odb/result.hxx>
#include <odb/polymorphic-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // SequenceInterval
  //
  template <>
  struct class_traits< ::UniPAX::SequenceInterval >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::UniPAX::SequenceInterval >
  {
    public:
    typedef ::UniPAX::SequenceInterval object_type;
    typedef ::boost::shared_ptr< ::UniPAX::SequenceInterval > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::UniPAX::SequenceLocation root_type;
    typedef ::UniPAX::SequenceLocation base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::UniPAX::UPBase >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      object_traits<root_type>::pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      root_type,
      odb::session >
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include <odb/details/buffer.hxx>

#include <odb/mysql/version.hxx>
#include <odb/mysql/forward.hxx>
#include <odb/mysql/binding.hxx>
#include <odb/mysql/mysql-types.hxx>
#include <odb/mysql/query.hxx>

namespace odb
{
  // SequenceInterval
  //
  template <typename A>
  struct pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >:
    pointer_query_columns< ::UniPAX::SequenceLocation, id_mysql, typename A::base_traits >
  {
    // SequenceLocation
    //
    typedef pointer_query_columns< ::UniPAX::SequenceLocation, id_mysql, typename A::base_traits > SequenceLocation;

    // unipaxId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    unipaxId_type_;

    static const unipaxId_type_ unipaxId;

    // sequenceIntervalBegin
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    sequenceIntervalBegin_type_;

    static const sequenceIntervalBegin_type_ sequenceIntervalBegin;

    // sequenceIntervalEnd
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    sequenceIntervalEnd_type_;

    static const sequenceIntervalEnd_type_ sequenceIntervalEnd;
  };

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::unipaxId_type_
  pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::sequenceIntervalBegin_type_
  pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  sequenceIntervalBegin (A::table_name, "`sequenceIntervalBegin`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::sequenceIntervalEnd_type_
  pointer_query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  sequenceIntervalEnd (A::table_name, "`sequenceIntervalEnd`", 0);

  template <>
  class access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >:
    public access::object_traits< ::UniPAX::SequenceInterval >
  {
    public:
    typedef polymorphic_entry<object_type, id_mysql> entry_type;
    typedef object_traits_impl<root_type, id_mysql> root_traits;
    typedef object_traits_impl<base_type, id_mysql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // unipaxId
      //
      unsigned long long unipaxId_value;
      my_bool unipaxId_null;

      // sequenceIntervalBegin
      //
      unsigned long long sequenceIntervalBegin_value;
      my_bool sequenceIntervalBegin_null;

      // sequenceIntervalEnd
      //
      unsigned long long sequenceIntervalEnd_value;
      my_bool sequenceIntervalEnd_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct sequenceIntervalBegin_tag;
    struct sequenceIntervalEnd_tag;

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          my_bool*,
          std::size_t = depth);

    static void
    bind (MYSQL_BIND*,
          const MYSQL_BIND* id,
          std::size_t id_size,
          image_type&,
          mysql::statement_kind);

    static void
    bind (MYSQL_BIND*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          mysql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, mysql::binding*);

    typedef
    mysql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    mysql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 3UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);
  };

  template <>
  class access::object_traits_impl< ::UniPAX::SequenceInterval, id_common >:
    public access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >
  {
  };

  // SequenceInterval
  //
  template <>
  struct alias_traits<
    ::UniPAX::SequenceLocation,
    id_mysql,
    access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalBegin_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::UniPAX::SequenceSite,
    id_mysql,
    access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalBegin_tag>
  {
    typedef alias_traits<
      ::UniPAX::SequenceLocation,
      id_mysql,
      access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalBegin_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::UniPAX::SequenceLocation,
    id_mysql,
    access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalEnd_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::UniPAX::SequenceSite,
    id_mysql,
    access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalEnd_tag>
  {
    typedef alias_traits<
      ::UniPAX::SequenceLocation,
      id_mysql,
      access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalEnd_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::UniPAX::SequenceInterval, id_mysql >
  {
    // sequenceIntervalBegin
    //
    typedef
    odb::alias_traits<
      ::UniPAX::SequenceSite,
      id_mysql,
      access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalBegin_tag>
    sequenceIntervalBegin_alias_;

    // sequenceIntervalEnd
    //
    typedef
    odb::alias_traits<
      ::UniPAX::SequenceSite,
      id_mysql,
      access::object_traits_impl< ::UniPAX::SequenceInterval, id_mysql >::sequenceIntervalEnd_tag>
    sequenceIntervalEnd_alias_;
  };

  template <typename A>
  struct query_columns< ::UniPAX::SequenceInterval, id_mysql, A >:
    query_columns_base< ::UniPAX::SequenceInterval, id_mysql >,
    query_columns< ::UniPAX::SequenceLocation, id_mysql, typename A::base_traits >
  {
    // SequenceLocation
    //
    typedef query_columns< ::UniPAX::SequenceLocation, id_mysql, typename A::base_traits > SequenceLocation;

    // unipaxId
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    unipaxId_type_;

    static const unipaxId_type_ unipaxId;

    // sequenceIntervalBegin
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    sequenceIntervalBegin_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::SequenceSite,
        id_mysql,
        sequenceIntervalBegin_alias_ > >
    sequenceIntervalBegin_pointer_type_;

    struct sequenceIntervalBegin_type_: sequenceIntervalBegin_pointer_type_, sequenceIntervalBegin_column_type_
    {
      sequenceIntervalBegin_type_ (const char* t, const char* c, const char* conv)
        : sequenceIntervalBegin_column_type_ (t, c, conv)
      {
      }
    };

    static const sequenceIntervalBegin_type_ sequenceIntervalBegin;

    // sequenceIntervalEnd
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    sequenceIntervalEnd_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::SequenceSite,
        id_mysql,
        sequenceIntervalEnd_alias_ > >
    sequenceIntervalEnd_pointer_type_;

    struct sequenceIntervalEnd_type_: sequenceIntervalEnd_pointer_type_, sequenceIntervalEnd_column_type_
    {
      sequenceIntervalEnd_type_ (const char* t, const char* c, const char* conv)
        : sequenceIntervalEnd_column_type_ (t, c, conv)
      {
      }
    };

    static const sequenceIntervalEnd_type_ sequenceIntervalEnd;
  };

  template <typename A>
  const typename query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::unipaxId_type_
  query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::sequenceIntervalBegin_type_
  query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  sequenceIntervalBegin (A::table_name, "`sequenceIntervalBegin`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::sequenceIntervalEnd_type_
  query_columns< ::UniPAX::SequenceInterval, id_mysql, A >::
  sequenceIntervalEnd (A::table_name, "`sequenceIntervalEnd`", 0);
}

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceInterval-odb.ixx>

#include <odb/post.hxx>

#endif // SEQUENCE_INTERVAL_ODB_HXX
