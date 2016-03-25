// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // Modulation
  //

  inline
  access::object_traits< ::UniPAX::Modulation >::id_type
  access::object_traits< ::UniPAX::Modulation >::
  id (const object_type& o)
  {
    return object_traits< ::UniPAX::UPBase >::id (o);
  }

  inline
  void access::object_traits< ::UniPAX::Modulation >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::UniPAX::Modulation >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

#include <odb/details/unique-ptr.hxx>

namespace odb
{
  // Modulation
  //

  inline
  void access::object_traits_impl< ::UniPAX::Modulation, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::UniPAX::Modulation, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::init (i, id);
  }

  inline
  bool access::object_traits_impl< ::UniPAX::Modulation, id_mysql >::
  check_version (const std::size_t* v, const image_type& i)
  {
    return 
      v[0UL] != i.version ||
      v[1UL] != i.base->version ||
      v[2UL] != i.base->base->version ||
      v[3UL] != i.base->base->base->version;
  }

  inline
  void access::object_traits_impl< ::UniPAX::Modulation, id_mysql >::
  update_version (std::size_t* v, const image_type& i, mysql::binding* b)
  {
    v[0UL] = i.version;
    v[1UL] = i.base->version;
    v[2UL] = i.base->base->version;
    v[3UL] = i.base->base->base->version;
    b[0UL].version++;
    b[1UL].version++;
    b[2UL].version++;
    b[3UL].version++;
  }
}

