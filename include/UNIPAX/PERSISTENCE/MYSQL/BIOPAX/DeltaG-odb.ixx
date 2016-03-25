// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // DeltaG
  //

  inline
  access::object_traits< ::UniPAX::DeltaG >::id_type
  access::object_traits< ::UniPAX::DeltaG >::
  id (const object_type& o)
  {
    return object_traits< ::UniPAX::UPBase >::id (o);
  }

  inline
  void access::object_traits< ::UniPAX::DeltaG >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::UniPAX::DeltaG >::
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
  // DeltaG
  //

  inline
  access::object_traits_impl< ::UniPAX::DeltaG, id_mysql >::id_type
  access::object_traits_impl< ::UniPAX::DeltaG, id_mysql >::
  id (const image_type& i)
  {
    return object_traits_impl< ::UniPAX::UPBase, id_mysql >::id (i);
  }

  inline
  void access::object_traits_impl< ::UniPAX::DeltaG, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::UniPAX::DeltaG, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::UniPAX::UPBase, id_mysql >::init (i, id);
  }
}

