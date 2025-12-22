////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/assetvk/scene/SimpleScene.hpp>

using namespace yq;
using namespace yq::tachyon;

class RocksScene : public SimpleScene {
    YQ_TACHYON_DECLARE(RocksScene, Scene)
public:

    struct Param : public SimpleScene::Param {
    };
    
    RocksScene();
    RocksScene(const Param&);
    ~RocksScene();
    
    Execution tick(const Context&) override;
    void    spawn();
    
    static void init_meta();
    
    double      m_odds  = 0.;
};
