#include "EngineCore.h"

namespace Leng{


    void EngineCore::load(){
        DEBUG("EngineCore Loading...");
        const char* appName = "Vulkan Raytracing";
        _window = new Leng::Window(400, 400.0 / (16.0 / 9.0), appName);

       validatationLayersAssert();
       _vulkanInstance = Startup::createVKInstance("Vulkan RayTracing", "Leng", false);
       _selectedDevice = Startup::selectPhysicalDevice();
    }

    void EngineCore::validatationLayersAssert(){
        uint32_t layerCount;
        vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

        std::vector<VkLayerProperties> availableLayers(layerCount);
        vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());
        bool validationLayersSupported = false;
        const std::vector<const char*> _validationLayers = {"VK_LAYER_KHRONOS_validation"};
        for (const char* layerName : _validationLayers) {
            bool layerFound = false;

            for (const auto& layerProperties : availableLayers) {
                if (strcmp(layerName, layerProperties.layerName) == 0) {
                    layerFound = true;
                    break;
                }
            }

            if (!layerFound) {
                validationLayersSupported = false;
            }
        }

        validationLayersSupported = true;

        if(__DEBUG_MODE && !validationLayersSupported){
            ERROR("Debug mode activated but couldn't initialize validation layers");
        }else{
            DEBUG("Validation layers initialized");

        }


    }

    void EngineCore::update(){

    }

    void EngineCore::render(){


    }

    void EngineCore::unload(){
        WARN("Unloading EngineCore...");

        vkDestroyInstance(_vulkanInstance, nullptr);

        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}