
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __javax_swing_plaf_basic_BasicToolBarUI$DockingListener__
#define __javax_swing_plaf_basic_BasicToolBarUI$DockingListener__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace java
  {
    namespace awt
    {
        class Point;
      namespace event
      {
          class MouseEvent;
      }
    }
  }
  namespace javax
  {
    namespace swing
    {
        class JToolBar;
      namespace plaf
      {
        namespace basic
        {
            class BasicToolBarUI;
            class BasicToolBarUI$DockingListener;
        }
      }
    }
  }
}

class javax::swing::plaf::basic::BasicToolBarUI$DockingListener : public ::java::lang::Object
{

public:
  BasicToolBarUI$DockingListener(::javax::swing::plaf::basic::BasicToolBarUI *, ::javax::swing::JToolBar *);
  virtual void mouseClicked(::java::awt::event::MouseEvent *);
  virtual void mouseDragged(::java::awt::event::MouseEvent *);
  virtual void mouseEntered(::java::awt::event::MouseEvent *);
  virtual void mouseExited(::java::awt::event::MouseEvent *);
  virtual void mouseMoved(::java::awt::event::MouseEvent *);
  virtual void mousePressed(::java::awt::event::MouseEvent *);
  virtual void mouseReleased(::java::awt::event::MouseEvent *);
public: // actually protected
  jboolean __attribute__((aligned(__alignof__( ::java::lang::Object)))) isDragging;
  ::java::awt::Point * origin;
  ::javax::swing::JToolBar * toolBar;
public: // actually package-private
  ::javax::swing::plaf::basic::BasicToolBarUI * this$0;
public:
  static ::java::lang::Class class$;
};

#endif // __javax_swing_plaf_basic_BasicToolBarUI$DockingListener__
