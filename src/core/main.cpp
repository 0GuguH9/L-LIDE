#include "core/window.hpp"

#include <gtkmm/application.h>

int main(int argc, char *argv[]) {

    auto app = Gtk::Application::create("com.github.zero-guguh-nine.llide");

    return app->make_window_and_run<LLIDE::Core::Window>(argc, argv);
}