// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PROTEIN_REFERENCE_ODB_HXX
#define PROTEIN_REFERENCE_ODB_HXX

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

#include <UNIPAX/KERNEL/BIOPAX/ProteinReference.h>

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/BioSource-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/CellVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ControlledVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Entity-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EntityFeature-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EntityReference-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EntityReferenceTypeVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Evidence-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/EvidenceCodeVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalForm-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ExperimentalFormVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Provenance-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Score-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceLocation-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/SequenceRegionVocabulary-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/Thing-odb.hxx>
#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/TissueVocabulary-odb.hxx>
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
  // ProteinReference
  //
  template <>
  struct class_traits< ::UniPAX::ProteinReference >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::UniPAX::ProteinReference >
  {
    public:
    typedef ::UniPAX::ProteinReference object_type;
    typedef ::boost::shared_ptr< ::UniPAX::ProteinReference > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::UniPAX::EntityReference root_type;
    typedef ::UniPAX::EntityReference base_type;
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
  // ProteinReference
  //
  template <typename A>
  struct pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >:
    pointer_query_columns< ::UniPAX::EntityReference, id_mysql, typename A::base_traits >
  {
    // EntityReference
    //
    typedef pointer_query_columns< ::UniPAX::EntityReference, id_mysql, typename A::base_traits > EntityReference;

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

    // sequence
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    sequence_type_;

    static const sequence_type_ sequence;

    // organism
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    organism_type_;

    static const organism_type_ organism;
  };

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::unipaxId_type_
  pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::sequence_type_
  pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  sequence (A::table_name, "`sequence`", 0);

  template <typename A>
  const typename pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::organism_type_
  pointer_query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  organism (A::table_name, "`organism`", 0);

  template <>
  class access::object_traits_impl< ::UniPAX::ProteinReference, id_mysql >:
    public access::object_traits< ::UniPAX::ProteinReference >
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

      // sequence
      //
      details::buffer sequence_value;
      unsigned long sequence_size;
      my_bool sequence_null;

      // organism
      //
      unsigned long long organism_value;
      my_bool organism_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    struct organism_tag;

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
  class access::object_traits_impl< ::UniPAX::ProteinReference, id_common >:
    public access::object_traits_impl< ::UniPAX::ProteinReference, id_mysql >
  {
  };

  // ProteinReference
  //
  template <>
  struct alias_traits<
    ::UniPAX::BioSource,
    id_mysql,
    access::object_traits_impl< ::UniPAX::ProteinReference, id_mysql >::organism_tag>
  {
    static const char table_name[];
  };

  template <>
  struct query_columns_base< ::UniPAX::ProteinReference, id_mysql >
  {
    // organism
    //
    typedef
    odb::alias_traits<
      ::UniPAX::BioSource,
      id_mysql,
      access::object_traits_impl< ::UniPAX::ProteinReference, id_mysql >::organism_tag>
    organism_alias_;
  };

  template <typename A>
  struct query_columns< ::UniPAX::ProteinReference, id_mysql, A >:
    query_columns_base< ::UniPAX::ProteinReference, id_mysql >,
    query_columns< ::UniPAX::EntityReference, id_mysql, typename A::base_traits >
  {
    // EntityReference
    //
    typedef query_columns< ::UniPAX::EntityReference, id_mysql, typename A::base_traits > EntityReference;

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

    // sequence
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::std::string,
        mysql::id_string >::query_type,
      mysql::id_string >
    sequence_type_;

    static const sequence_type_ sequence;

    // organism
    //
    typedef
    mysql::query_column<
      mysql::value_traits<
        ::UnipaxId,
        mysql::id_ulonglong >::query_type,
      mysql::id_ulonglong >
    organism_column_type_;

    typedef
    odb::query_pointer<
      odb::pointer_query_columns<
        ::UniPAX::BioSource,
        id_mysql,
        organism_alias_ > >
    organism_pointer_type_;

    struct organism_type_: organism_pointer_type_, organism_column_type_
    {
      organism_type_ (const char* t, const char* c, const char* conv)
        : organism_column_type_ (t, c, conv)
      {
      }
    };

    static const organism_type_ organism;
  };

  template <typename A>
  const typename query_columns< ::UniPAX::ProteinReference, id_mysql, A >::unipaxId_type_
  query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  unipaxId (A::table_name, "`unipaxId`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::ProteinReference, id_mysql, A >::sequence_type_
  query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  sequence (A::table_name, "`sequence`", 0);

  template <typename A>
  const typename query_columns< ::UniPAX::ProteinReference, id_mysql, A >::organism_type_
  query_columns< ::UniPAX::ProteinReference, id_mysql, A >::
  organism (A::table_name, "`organism`", 0);
}

#include <UNIPAX/PERSISTENCE/MYSQL/BIOPAX/ProteinReference-odb.ixx>

#include <odb/post.hxx>

#endif // PROTEIN_REFERENCE_ODB_HXX
