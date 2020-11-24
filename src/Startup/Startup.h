#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Tools/Logging.h>
#include <Tools/VkHelpers.h>
#include <vector>
namespace Leng{

    class Startup{
        private:
            static bool _isDeviceSuitable(VkPhysicalDevice device);
        public:        
            static VkInstance createVKInstance(const char* appName, const char* engineName, bool enableValidationLayers = true);
            static VkPhysicalDevice selectPhysicalDevice(VkInstance curInstance);
            static const std::vector<const char*> validationLayers;

        
    };

}