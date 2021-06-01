#include "window.h"


namespace Grizel
{

    namespace Graphics
    {

        Window::Window(const char *name, int width, int height)
        {
            this->name = name;
            this->width = width;
            this->height = height;

            if (!(this->init()))
            {
                glfwTerminate();
            }
        }

        Window::~Window()
        {
            std::cout << "Destroying main window" << std::endl;
            glfwTerminate();
        }

        bool Window::init()
        {
            /* Initialize the library */
            if (!glfwInit())
            {
                std::cout << "Error during the process of GLFW initialization" << std::endl;
                return false;
            }
            else
            {
                std::cout << "The window of GLFW was successfuly created!" << std::endl;
            }

            this->window = glfwCreateWindow(width, height, name, NULL, NULL);
            if (!window)
            {
                std::cout << "Failure during the process of creation window";
                glfwTerminate();
                return false;
            }

            glfwMakeContextCurrent(this->window);
            return true;
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void Window::update()
        {
            /* Poll for and process events */
            glfwPollEvents();
            glfwGetFramebufferSize(this->window,&(this->width), &(this->height));
            glViewport(0, 0, this->width, this->height);
            /* Swap front and back buffers */
            glfwSwapBuffers(window);

        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(window) == 1;
        }

    }

}
