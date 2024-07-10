#include <gtkmm/application.h>

#include "core/headers/window.hpp"

int main(int argc, char *argv[]) {

    auto app = Gtk::Application::create(argc, argv, "com.github.zero-guguh-nine.llide");

    LLIDE::Core::LLIDEWindow window;
    
    return app->run(window);
}