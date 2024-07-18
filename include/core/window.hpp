#ifndef LLIDE_CORE_WINDOW_HPP
#define LLIDE_CORE_WINDOW_HPP

#include "core/code_viewer.hpp"
#include <gtkmm/window.h>

namespace LLIDE::Core {

    const int defaultWidth = 800;
    const int defaultHeight = 600;

    class Window : public Gtk::Window{
        private:
            CodeViewer codeViewer;
            
        public:
            Window();

    };
}

#endif