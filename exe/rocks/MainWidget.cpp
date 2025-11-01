////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWidget.hpp"

#include <yq/tachyon/event/mouse/MousePressEvent.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>

MainWidget::MainWidget()
{
}

MainWidget::~MainWidget()
{
}


void  MainWidget::on_mouse_press_event(const MousePressEvent&evt)
{
    //cmd_close();
}

void  MainWidget::init_meta()
{
    auto w = writer<MainWidget>();
    w.slot(&MainWidget::on_mouse_press_event);
}

YQ_TACHYON_IMPLEMENT(MainWidget)
