// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef TEMPLATE_REACTION_ODB_HXX
#define TEMPLATE_REACTION_ODB_HXX

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

#include <UNIPAX/KERNEL/BIOPAX/TemplateReaction.h>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/CellularLocationVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ControlledVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Entity-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EntityFeature-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Evidence-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EvidenceCodeVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalForm-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalFormVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Interaction-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/InteractionVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/PhysicalEntity-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Provenance-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Score-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceLocation-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceRegionVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Thing-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/UtilityClass-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Xref-odb.hxx>
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
  // TemplateReaction
  //
  template <>
  struct class_traits< ::UniPAX::TemplateReaction >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::UniPAX::TemplateReaction >
  {
    public:
    typedef ::UniPAX::TemplateReaction object_type;
    typedef ::boost::shared_ptr< ::UniPAX::TemplateReaction > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::UniPAX::Entity root_type;
    typedef ::UniPAX::Interaction base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 3UL;

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
  // TemplateReaction
  //
  template <typename A>
  struct pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >:
    pointer_query_columns< ::UniPAX::Interaction, id_mysql, typename A::base_traits >
  {
    // Interaction
    //
    typedef pointer_query_columns< ::UniPAX::Interaction, id_mysql, typename A::base_traits > Interaction;

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

    // templateDirection
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    templateDirection_type_;

    static const templateDirection_type_ templateDirection;

    // templateEntity
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    templateEntity_type_;

    static const templateEntity_type_ templateEntity;
  };

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::unipaxId_type_
  pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::templateDirection_type_
  pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  templateDirection (A::table_name, "`templateDirection`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::templateEntity_type_
  pointer_query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  templateEntity (A::table_name, "`templateEntity`", 0);

  template <>
  class access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >:
    public access::object_traits< ::UniPAX::TemplateReaction >
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

      // templateDirection
      //
      details::buffer templateDirection_value;
      unsigned long templateDirection_size;
      my_bool templateDirection_null;

      // templateEntity
      //
      unsigned long long templateEntity_value;
      my_bool templateEntity_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    // product
    //
    struct product_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t data_column_count = 3UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char delete_statement[];

      typedef ::std::vector< ::boost::shared_ptr< ::UniPAX::PhysicalEntity > > container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef ordered_functions<index_type, value_type> functions_type;
      typedef mysql::container_statements< product_traits > statements_type;

      struct data_image_type
      {
        // index
        //
        unsigned long long index_value;
        my_bool index_null;

        // value
        //
        unsigned long long value_value;
        my_bool value_null;

        std::size_t version;
      };

      static void
      bind (MYSQL_BIND*,
            const MYSQL_BIND* id,
            std::size_t id_size,
            data_image_type&);

      static void
      grow (data_image_type&,
            my_bool*);

      static void
      init (data_image_type&,
            index_type*,
            const value_type&);

      static void
      init (index_type&,
            value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      delete_ (void*);

      static void
      persist (const container_type&,
               statements_type&);

      static void
      load (container_type&,
            statements_type&);

      static void
      update (const container_type&,
              statements_type&);

      static void
      erase (statements_type&);
    };

    struct templateEntity_tag;

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
  class access::object_traits_impl< ::UniPAX::TemplateReaction, id_common >:
    public access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >
  {
  };

  // TemplateReaction
  //
  template <>
  struct alias_traits<
    ::UniPAX::Entity,
    id_mysql,
    access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >::templateEntity_tag>
  {
    static const char table_name[];
  };

  template <>
  struct alias_traits<
    ::UniPAX::PhysicalEntity,
    id_mysql,
    access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >::templateEntity_tag>
  {
    typedef alias_traits<
      ::UniPAX::Entity,
      id_mysql,
      access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >::templateEntity_tag>
    base_traits;

    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::UniPAX::TemplateReaction, id_mysql >
  {
    // templateEntity
    //
    typedef
    odb::alias_traits<
      ::UniPAX::PhysicalEntity,
      id_mysql,
      access::object_traits_impl< ::UniPAX::TemplateReaction, id_mysql >::templateEntity_tag>
    templateEntity_alias_;
  };

  template <typename A>
  struct query_columns< ::UniPAX::TemplateReaction, id_mysql, A >:
    query_columns_base< ::UniPAX::TemplateReaction, id_mysql >,
    query_columns< ::UniPAX::Interaction, id_mysql, typename A::base_traits >
  {
    // Interaction
    //
    typedef query_columns< ::UniPAX::Interaction, id_mysql, typename A::base_traits > Interaction;

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

    // templateDirection
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    templateDirection_type_;

    static const templateDirection_type_ templateDirection;

    // templateEntity
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    templateEntity_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::PhysicalEntity,
        id_mysql,
        templateEntity_alias_ > >
    templateEntity_pointer_type_;

    struct templateEntity_type_: templateEntity_pointer_type_, templateEntity_column_type_
    {
      templateEntity_type_ (const char* t, const char* c, const char* conv)
        : templateEntity_column_type_ (t, c, conv)
      {
      }
    };

    static const templateEntity_type_ templateEntity;
  };

  template <typename A>
  const typename query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::unipaxId_type_
  query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::templateDirection_type_
  query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  templateDirection (A::table_name, "`templateDirection`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::templateEntity_type_
  query_columns< ::UniPAX::TemplateReaction, id_mysql, A >::
  templateEntity (A::table_name, "`templateEntity`", 0);
}

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/TemplateReaction-odb.ixx>

#include <odb/post.hxx>

#endif // TEMPLATE_REACTION_ODB_HXX
