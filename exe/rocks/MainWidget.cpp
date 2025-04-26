////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWidget.hpp"

#include <tachyon/event/mouse/MousePressEvent.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>

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

void  MainWidget::init_info()
{
    auto w = writer<MainWidget>();
    w.slot(&MainWidget::on_mouse_press_event);
}

YQ_TACHYON_IMPLEMENT(MainWidget)
