////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/app/Application.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/units.hpp>
#include <tachyon/typedef/monitor.hpp>
#include <tachyon/typedef/viewer.hpp>
#include <tachyon/typedef/widget.hpp>

using namespace yq;
using namespace yq::tachyon;

class MainWidget;

class RockApp : public Application {
public:
    
    static RockApp*     app() { return s_app; }

    RockApp(int, char**, const AppCreateInfo&);
    ~RockApp();

    bool start() override;
    virtual void            configure_vulqan() override;
    
private:

    struct XWin {
        MonitorID       monitor;
        ViewerID        viewer;
        WidgetID        widget;
        Size2D          pixels;
        Size2MM         dimensions;
        Vector2D        position;
        Vector2F        scale;
    };
    
    std::vector<XWin>   m_windows;
    bool                m_startStarted  = false;

    static RockApp* s_app;
};
