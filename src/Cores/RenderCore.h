#pragma once
#include <Tools/Logging.h>
#include <Cores/EngineCore.h>

namespace Leng{

    class RenderCore{
        private:
            Leng::EngineCore _engineCore;

        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool isRunning() const {return _engineCore.isRunning();}

    };

}