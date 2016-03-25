// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

// Begin prologue.
//
//
// End prologue.

namespace odb
{
  // DnaRegionReference
  //

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::id_type
  access::object_traits< ::UniPAX::DnaRegionReference >::
  id (const object_type& obj)
  {
    return object_traits< ::UniPAX::UPBase >::id (obj);
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::id_type
  access::object_traits< ::UniPAX::DnaRegionReference >::
  id (const image_type& i)
  {
    return object_traits< ::UniPAX::UPBase >::id (i);
  }

  inline
  void access::object_traits< ::UniPAX::DnaRegionReference >::
  bind (oracle::bind* b, id_image_type& i)
  {
    object_traits< ::UniPAX::UPBase >::bind (b, i);
  }

  inline
  void access::object_traits< ::UniPAX::DnaRegionReference >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits< ::UniPAX::UPBase >::init (i, id);
  }

  inline
  void access::object_traits< ::UniPAX::DnaRegionReference >::
  erase (database& db, const object_type& obj)
  {
    erase (db, id (obj));
  }

  inline
  void access::object_traits< ::UniPAX::DnaRegionReference >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);

    static_cast< ::UniPAX::DnaRegionReference& > (x).init (e, db);
  }

  inline
  void access::object_traits< ::UniPAX::DnaRegionReference >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::query_type::
  query_type ()
  {
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::query_type::
  query_type (bool v)
    : query_base_type (v)
  {
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::query_type::
  query_type (const char* q)
    : query_base_type (q)
  {
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::query_type::
  query_type (const std::string& q)
    : query_base_type (q)
  {
  }

  inline
  access::object_traits< ::UniPAX::DnaRegionReference >::query_type::
  query_type (const query_base_type& q)
    : query_base_type (q)
  {
  }
}

// Begin epilogue.
//
//
// End epilogue.
