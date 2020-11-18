#pragma once
#include <GLFW/glfw3.h>
#include <Tools/Logging.h>
#include <stdint.h>
namespace lk{

    class Window{

        private:
            uint8_t _width, _height; 
            const char* _name;
            GLFWwindow* _window;
        public:
            Window();
            Window(uint8_t width, uint8_t height, const char* name);
            void init();


            GLFWwindow* getWindow()const{return _window;}

            bool isRunning() const {return !glfwWindowShouldClose(_window);}

    };

}