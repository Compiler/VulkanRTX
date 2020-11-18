#pragma once
#include <Tools/Logging.h>
#include <Cores/EngineCore.h>

namespace lk{

    class RenderCore{
        private:
            lk::EngineCore _engineCore;

        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool isRunning() const {return _engineCore.isRunning();}

    };

}