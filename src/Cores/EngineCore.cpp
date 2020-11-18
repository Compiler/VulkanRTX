#include "EngineCore.h"

namespace Leng{


    void EngineCore::load(){
        DEBUG("EngineCore Loading...");
        const char* appName = "Vulkan Raytracing";
        _window = new Leng::Window(1920, 1080, appName);

        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = appName;
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "Leng";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;


        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;
        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
        createInfo.enabledExtensionCount = glfwExtensionCount;
        createInfo.ppEnabledExtensionNames = glfwExtensions;
        createInfo.enabledLayerCount = 0;
        VkResult result = vkCreateInstance(&createInfo, nullptr, &_vulkanInstance);

        if(result != VK_SUCCESS){
            ERROR("Failed to create vulkan instance");
        }else{
            DEBUG("Vulkan Instance Created!");
        } 

    }

    void EngineCore::update(){

    }

    void EngineCore::render(){


    }

    void EngineCore::unload(){
        WARN("Unloading EngineCore...");
        _window->destroy();
        delete(_window);
        glfwTerminate();

    }



}