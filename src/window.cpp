#include "core/window.hpp"

using namespace LLIDE::Core;

Window::Window() {

    set_title("L-LIDE");
    set_default_size(defaultWidth, defaultHeight);

    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", TRUE, NULL);

    set_child(codeViewer.viewer);
}
