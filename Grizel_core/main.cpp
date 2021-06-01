#include "src/graphics/window.h"

int main(void)
{
    using namespace Grizel;
    using namespace Graphics;

    Window window("Grizel engine", 800, 600);
    glClearColor(.3f, .2f, 4.f, 1.0f);

    std::cout << glGetString(GL_VERSION) << std::endl;

    // Game loop
    while(!(window.closed())){
        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-.5f, -.5f);
        glVertex2f(.5f, 0.5f);
        glVertex2f(.5f, -.5f);
        glEnd();

        window.update();
    }

    return 0;
}
