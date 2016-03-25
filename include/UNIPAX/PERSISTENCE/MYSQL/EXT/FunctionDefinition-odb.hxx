// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef FUNCTION_DEFINITION_ODB_HXX
#define FUNCTION_DEFINITION_ODB_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/date-time/mysql/posix-time-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include <UNIPAX/KERNEL/EXT/FunctionDefinition.h>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/BioSource-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/CellVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ControlledVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Entity-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EntityFeature-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Evidence-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EvidenceCodeVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalForm-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalFormVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Interaction-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/InteractionVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Pathway-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/PathwayStep-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Provenance-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Score-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceLocation-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceRegionVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Thing-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/TissueVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/UtilityClass-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Xref-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Constraint-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Delay-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Event-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/EventAssignment-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/ImportSource-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/InitialAssignment-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Math-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Model-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Parameter-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Priority-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Rule-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/SBase-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Trigger-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/UIBase-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/UPBase-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/Unit-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/EXT/UnitDefinition-odb.hxx>

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
  // FunctionDefinition
  //
  template <>
  struct class_traits< ::UniPAX::FunctionDefinition >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::UniPAX::FunctionDefinition >
  {
    public:
    typedef ::UniPAX::FunctionDefinition object_type;
    typedef ::boost::shared_ptr< ::UniPAX::FunctionDefinition > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::UniPAX::FunctionDefinition root_type;
    typedef ::std::string discriminator_type;
    typedef polymorphic_map<object_type> map_type;
    typedef polymorphic_concrete_info<object_type> info_type;

    static const std::size_t depth = 1UL;

    typedef object_traits< ::UniPAX::UPBase >::id_type id_type;

    static const bool auto_id = object_traits< ::UniPAX::UPBase >::auto_id;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    odb::pointer_cache_traits<
      pointer_type,
      odb::session >
    pointer_cache_traits;

    typedef
    odb::reference_cache_traits<
      object_type,
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
  // FunctionDefinition
  //
  template <typename A>
  struct pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >:
    pointer_query_columns< ::UniPAX::SBase, id_mysql, A >
  {
    // SBase
    //
    typedef pointer_query_columns< ::UniPAX::SBase, id_mysql, A > SBase;

    // typeid_
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    id_type_;

    static const id_type_ id;

    // name
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    name_type_;

    static const name_type_ name;

    // math
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    math_type_;

    static const math_type_ math;
  };

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::typeid__type_
  pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  typeid_ (A::table_name, "`typeid`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::id_type_
  pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::name_type_
  pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  name (A::table_name, "`name`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::math_type_
  pointer_query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  math (A::table_name, "`math`", 0);

  template <>
  class access::object_traits_impl< ::UniPAX::FunctionDefinition, id_mysql >:
    public access::object_traits< ::UniPAX::FunctionDefinition >
  {
    public:
    typedef polymorphic_entry<object_type, id_mysql> entry_type;
    typedef object_traits_impl<root_type, id_mysql> root_traits;

    struct discriminator_image_type
    {
      details::buffer discriminator_value;
      unsigned long discriminator_size;
      my_bool discriminator_null;

      std::size_t version;
    };

    typedef object_traits_impl< ::UniPAX::UPBase, id_mysql >::id_image_type id_image_type;

    static map_type* map;
    static const info_type info;

    struct image_type: object_traits_impl< ::UniPAX::SBase, id_mysql >::image_type
    {
      // typeid_
      //
      details::buffer typeid_value;
      unsigned long typeid_size;
      my_bool typeid_null;

      // id
      //
      details::buffer id_value;
      unsigned long id_size;
      my_bool id_null;

      // name
      //
      details::buffer name_value;
      unsigned long name_size;
      my_bool name_null;

      // math
      //
      unsigned long long math_value;
      my_bool math_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct math_tag;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static discriminator_type
    discriminator (const image_type&);

    static bool
    grow (image_type&,
          my_bool*);

    static void
    bind (MYSQL_BIND*,
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
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef
    mysql::polymorphic_root_object_statements<object_type>
    statements_type;

    typedef statements_type root_statements_type;

    typedef mysql::query_base query_base_type;

    static const std::size_t column_count = 10UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 1UL;
    static const std::size_t managed_optimistic_column_count = 0UL;
    static const std::size_t discriminator_column_count = 1UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char find_discriminator_statement[];
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
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);

    static void
    discriminator_ (statements_type&,
                    const id_type&,
                    discriminator_type*);
  };

  template <>
  class access::object_traits_impl< ::UniPAX::FunctionDefinition, id_common >:
    public access::object_traits_impl< ::UniPAX::FunctionDefinition, id_mysql >
  {
  };

  // FunctionDefinition
  //
  template <>
  struct alias_traits<
    ::UniPAX::Math,
    id_mysql,
    access::object_traits_impl< ::UniPAX::FunctionDefinition, id_mysql >::math_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::UniPAX::FunctionDefinition, id_mysql >
  {
    // math
    //
    typedef
    odb::alias_traits<
      ::UniPAX::Math,
      id_mysql,
      access::object_traits_impl< ::UniPAX::FunctionDefinition, id_mysql >::math_tag>
    math_alias_;
  };

  template <typename A>
  struct query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >:
    query_columns_base< ::UniPAX::FunctionDefinition, id_mysql >,
    query_columns< ::UniPAX::SBase, id_mysql, A >
  {
    // SBase
    //
    typedef query_columns< ::UniPAX::SBase, id_mysql, A > SBase;

    // typeid_
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

    // id
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    id_type_;

    static const id_type_ id;

    // name
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    name_type_;

    static const name_type_ name;

    // math
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    math_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::Math,
        id_mysql,
        math_alias_ > >
    math_pointer_type_;

    struct math_type_: math_pointer_type_, math_column_type_
    {
      math_type_ (const char* t, const char* c, const char* conv)
        : math_column_type_ (t, c, conv)
      {
      }
    };

    static const math_type_ math;
  };

  template <typename A>
  const typename query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::typeid__type_
  query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  typeid_ (A::table_name, "`typeid`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::id_type_
  query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  id (A::table_name, "`id`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::name_type_
  query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  name (A::table_name, "`name`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::math_type_
  query_columns< ::UniPAX::FunctionDefinition, id_mysql, A >::
  math (A::table_name, "`math`", 0);
}

#include <UNIPAX/PERSISTENCE/MYSQL/EXT/FunctionDefinition-odb.ixx>

#include <odb/post.hxx>

#endif // FUNCTION_DEFINITION_ODB_HXX
