#pragma once

namespace lk{

    class RenderCore{

        public:
            void load();
            void update();
            void render();
            void unload();
            inline bool isRunning() const {return true;}

    };

}