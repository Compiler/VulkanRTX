#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Tools/Logging.h>
#include <vector>
namespace Leng{

    class Startup{
        public:        
            static VkInstance createVKInstance(const char* appName, const char* engineName, bool enableValidationLayers = true);
            static VkPhysicalDevice selectPhysicalDevice();
            static const std::vector<const char*> validationLayers;

        
    };

}