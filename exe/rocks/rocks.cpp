////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "RockApp.hpp"

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    aci.thread.sim      = true;
    aci.thread.viewer   = PER;    // currently with a threading error (needs to be sorted)

    RockApp app(argc, argv, aci);
    if(!app.start()){
        app.stop();
        return -1;
    }
    app.run();
    return 0;
}
