#pragma once

#include <optional>

namespace Leng{

    struct QueueFamilyIndices{
        std::optional<uint32_t> graphicsFamily;

        bool hasAllValues(){
            return graphicsFamily.has_value();
        }

    };

}