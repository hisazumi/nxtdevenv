
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_ListModel__
#define __javax_swing_ListModel__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace javax
  {
    namespace swing
    {
        class ListModel;
      namespace event
      {
          class ListDataListener;
      }
    }
  }
}

class javax::swing::ListModel : public ::java::lang::Object
{

public:
  virtual jint getSize() = 0;
  virtual ::java::lang::Object * getElementAt(jint) = 0;
  virtual void addListDataListener(::javax::swing::event::ListDataListener *) = 0;
  virtual void removeListDataListener(::javax::swing::event::ListDataListener *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __javax_swing_ListModel__
