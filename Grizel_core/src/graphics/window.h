#pragma once
#include <iostream>
#include <GLFW/glfw3.h>


namespace Grizel
{

    namespace Graphics
    {

        class Window
        {

        private:
            int width, height;
            const char* name;
            GLFWwindow* window;
            bool is_window_closed;

        public:
            Window(const char* name, int width, int height);
            ~Window();
            void clear() const;
            void update();
            bool closed() const;

            inline int getWidth() const { return this->width; }
            inline int getHeight() const { return this-> height; }

        private:
            bool init();
        };

    }

}
