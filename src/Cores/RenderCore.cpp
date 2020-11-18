#include "RenderCore.h"
namespace Leng{

    void RenderCore::load(){
        DEBUG("RenderCore Loading...");
        _engineCore.load();
    }

    void RenderCore::update(){
        _engineCore.update();
        glfwPollEvents();

    }   

    void RenderCore::render(){
        _engineCore.render();

    }

    void RenderCore::unload(){
        _engineCore.unload();

    }

}
