#include "Startup.h"
namespace Leng{

    const std::vector<const char*> Startup::validationLayers = { "VK_LAYER_KHRONOS_validation" };

    VkInstance Startup::createVKInstance(const char* appName, const char* engineName, bool enableValidationLayers){
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = appName;
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = engineName;
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
        if(enableValidationLayers){
            createInfo.enabledLayerCount = (uint32_t)(validationLayers.size());
            createInfo.ppEnabledLayerNames = validationLayers.data();
        }
        VkInstance vulkanInstance;
        VkResult result = vkCreateInstance(&createInfo, nullptr, &vulkanInstance);

        if(result != VK_SUCCESS){
            ERROR("Failed to create vulkan instance : %d", result);
        }else{
            DEBUG("Vulkan Instance Created!");
        } 


        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
        return vulkanInstance;
    }


    VkPhysicalDevice Startup::selectPhysicalDevice(){


    }

}