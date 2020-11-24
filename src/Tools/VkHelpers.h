#pragma once
#include <Leng.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <Tools/QueueFamilyIndices.h>
#include <vector>
namespace Leng{

    class VkHelpers{
        public:
            static QueueFamilyIndices findQueueFamilies(VkPhysicalDevice&);

    };

}