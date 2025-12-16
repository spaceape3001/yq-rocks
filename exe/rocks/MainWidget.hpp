////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/widget/CompositeWidget.hpp>

namespace yq::tachyon {
    class MousePressEvent;
}

using namespace yq;
using namespace yq::tachyon;

class MainWidget : public CompositeWidget {
    YQ_TACHYON_DECLARE(MainWidget, CompositeWidget)
public:

    MainWidget();
    ~MainWidget();

    void    on_mouse_press_event(const MousePressEvent&);

    static void init_meta();
};
