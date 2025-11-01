////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    class MousePressEvent;
}

using namespace yq;
using namespace yq::tachyon;

class MainWidget : public Widget {
    YQ_TACHYON_DECLARE(MainWidget, Widget)
public:

    MainWidget();
    ~MainWidget();

    void    on_mouse_press_event(const MousePressEvent&);

    static void init_meta();
    
    virtual bool    is_imgui() const override { return false; }
};
