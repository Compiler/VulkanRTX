#pragma once
#include <Rendering/Window.h>
#include <Tools/Logging.h>

namespace lk{

    class EngineCore{

        private:
            Window* _window;
        

        public:
            void load();
            void update();
            void render();
            void unload();
            bool isRunning() const {return _window->isRunning();}

    };

}