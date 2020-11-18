#pragma once
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Tools/Logging.h>

namespace Leng{

    class EngineCore{

        private:
            Window* _window;
            VkInstance _vulkanInstance;

        public:
            void load();
            void update();
            void render();
            void unload();
            bool isRunning() const {return _window->isRunning();}

    };

}