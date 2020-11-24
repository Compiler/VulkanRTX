#pragma once
#include <Leng.h>
#define GLFW_INCLUDE_VULKAN
#include <Rendering/Window.h>
#include <Startup/Startup.h>
#include <Tools/Logging.h>
#include <vector>
#include <cstring>
namespace Leng{

    class EngineCore{

        private:
            Window* _window;
            VkInstance _vulkanInstance;
            VkPhysicalDevice _selectedDevice;
            void validatationLayersAssert();

        public:
            void load();
            void update();
            void render();
            void unload();
            bool isRunning() const {return _window->isRunning();}

    };

}