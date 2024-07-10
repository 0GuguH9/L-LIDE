#ifndef LLIDE_WINDOW_HPP
#define LLIDE_WINDOW_HPP

#include <gtkmm/window.h>
#include <gtkmm/textview.h>

#include <string>

namespace LLIDE::Core {

    const int defaultWidth = 800;
    const int defaultHeight = 600;

    class LLIDEWindow : public Gtk::Window {
        private:
            std::string name = "L-LIDE";

        public:
            
            LLIDEWindow();

            Gtk::TextView codeView;
    };
}

#endif