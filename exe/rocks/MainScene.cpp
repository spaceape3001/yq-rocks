////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "MainScene.hpp"
#include <yq/math/Random.hpp>
#include <yq/assetvk/rendered/Diamond3.hpp>
#include <yq/assetvk/spatial/CircularSpatial3.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/SceneMetaWriter.hpp>

#include <yq/tachyon/api/N.hxx>
#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/vector/Quaternion3.hxx>

YQ_TACHYON_IMPLEMENT(RocksScene)

RocksScene::RocksScene() : RocksScene(Param())
{
}

RocksScene::RocksScene(const Param& p ) : SimpleScene(p)
{
}

RocksScene::~RocksScene()
{
}

void    RocksScene::spawn()
{
    Diamond³::Param dp;
    dp.color        = { (float) urand(), (float) urand(), (float) urand(), (float) urand() };
    dp.size         = { 1.0 + urand(), 1.0 + urand(), 1.0 + urand() };
    dp.draw_mode    = DrawMode::Color;
    if(urand() < 0.2)
        dp.wireframe    = Tristate::YES;
    
    CircularSpatial³::Param cp;
    cp.position     = { 3.0 * urand(), 3.0 * urand(), 3.0 * urand() };
    cp.orientation  = Quaternion3D(HPR, Degree(360.*urand()-180), Degree(180.*urand()-90.), Degree(360.*urand()-180.));
    cp.radius       = 6.0 + 4 * urand();
    cp.period       = Second(10.0 + 50 * urand());
    cp.angle0       = Degree(360. * urand());
    
    Diamond³*           shape   = create_child<Diamond³>(dp);
    CircularSpatial³*   spatial = shape->create_spatial<CircularSpatial³>(cp);
}
    
Execution RocksScene::tick(const Context&u) 
{
    SimpleScene::tick(u);

    if(children().size() < 1000){
        if((m_odds += u.Δt.value) > urand()){
            spawn();
            m_odds  = 0.;
        }
    }
    return {};
}
    
void RocksScene::init_meta()
{
    auto w = writer<RocksScene>();
    w.description("Scene for Rocks");
}

