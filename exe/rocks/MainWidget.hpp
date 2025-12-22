////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/widget/CompositeWidget.hpp>
#include <yq/assetvk/widget/SceneWidget.hpp>

namespace yq::tachyon {
    class MousePressEvent;
}

using namespace yq;
using namespace yq::tachyon;

class MainWidget : public SceneWidget {
    YQ_TACHYON_DECLARE(MainWidget, SceneWidget)
public:

    MainWidget(SceneID, CameraID);
    ~MainWidget();

    void    on_mouse_press_event(const MousePressEvent&);

    static void init_meta();
};
