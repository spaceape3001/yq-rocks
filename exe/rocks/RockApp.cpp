////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "RockApp.hpp"
#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/logging.hpp>
#include "MainWidget.hpp"
#include "MainScene.hpp"
#include <yq/assetvk/camera/SpaceCamera.hpp>
#include <yq/assetvk/controller/Space3Controller.hpp>
#include <yq/assetvk/spatial/SimpleSpatial3.hpp>

#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/tachyon/api/N.hxx>
#include <yq/vector/Quaternion3.hxx>

RockApp* RockApp::s_app = nullptr;

RockApp::RockApp(int argc, char**argv, const AppCreateInfo& aci) : Application(argc, argv, aci)
{
    s_app   = this;
}

RockApp::~RockApp()
{
    s_app   = nullptr;
}

void    RockApp::configure_vulqan() 
{
    for(const Monitor* m : desktop()->monitors()){
        XWin    xw;
        xw.monitor      = m->id();
        xw.pixels       = m->size();
        xw.position     = m->position();
        xw.scale        = m->scale();
        xw.dimensions   = m->dimensions();
        
        m_windows.push_back(xw);
    }
    std::stable_sort(m_windows.begin(), m_windows.end(), [](const XWin& a, const XWin& b) -> bool {
        return a.position.x < b.position.x;
    });
yInfo() << "RockApp configuring vulkan (detected " << m_windows.size() << " monitors)";
    m_cInfo.vulkan.graphics     = (unsigned int) m_windows.size();
}


bool RockApp::start()
{
    if(m_startStarted)
        return true;
    m_startStarted  = true;
    
    if(!Application::start())
        return false;
    
    static const RGBA4F kColors[] = {
        { 0.02f, 0.00f, 0.00f, 1.f },
        { 0.01f, 0.01f, 0.00f, 1.f },
        { 0.00f, 0.02f, 0.00f, 1.f },
        { 0.00f, 0.01f, 0.01f, 1.f },
        { 0.00f, 0.00f, 0.02f, 1.f },
        { 0.01f, 0.00f, 0.01f, 1.f }
    };
    static constexpr size_t nColors = sizeof(kColors)/sizeof(kColors[0]);
    
    //  Eventually sort the windows
    
    ViewerCreateInfo        vci;
    vci.title           = "Rocks";
    vci.resizable       = false;
    vci.imgui           = true;
    vci.imgui_enabled   = false;
    vci.descriptors     = 32768;
    //vci.floating        = true;
    //vci.decorated       = false;
    size_t                  counter = 0;
    
    std::vector<WidgetPtr>  widgets;

    yInfo() << "RockApp should have " << m_windows.size() << " windows";
    
    vci.size        = { 1920, 1080 };
    //vci.clear       = { 0.001f, 0.001f, 0.001f, 1.f};
    
    RocksScene*      sc  = Tachyon::create_on<RocksScene>(SIM);

    size_t      cnt     = 0;
    double      hc      = (double) m_windows.size();
    Space³Controller* co  = Tachyon::create<Space³Controller>();
    tick(); tick();
    
    for(XWin& xw : m_windows){
yInfo() << "Monitor> " << xw.pixels.x << "*" << xw.pixels.y << " " << xw.position.x << "," << xw.position.y;

        SimpleSpatial³::Param sp;
        sp.orientation  = Quaternion3D(HPR, Degree( ((double) cnt - hc) * 70. ), 0._deg, 0._deg);
        
        SpaceCamera*ca  = Tachyon::create<SpaceCamera>();
        ca->create_spatial<SimpleSpatial³>(sp);
        co->cmd_control(ca);
        ca->owner(PUSH, SIM);

        vci.monitor     = xw.monitor;
        vci.position        = iround(xw.position);
        vci.wmode           = WindowMode::Windowed;
        //vci.size            = iround(xw.pixels*0.75);
        vci.clear           = kColors[(counter++) % nColors];
        
        WidgetPtr   w   = Tachyon::create<MainWidget>(sc->id(), ca->id());
        widgets.push_back(w);
        xw.widget   = w->id();
        xw.viewer   = create(VIEWER, vci, w);
        tick(); tick();
        co->cmd_listen(*w);
        ++cnt;
    }
    
    
    return true;
}
