#ifndef LLIDE_CORE_VIEWER_HPP
#define LLIDE_CORE_VIEWER_HPP

#include <gtkmm/textview.h>

namespace LLIDE::Core {
    class CodeViewer {
        private:

        public:
            Gtk::TextView viewer;

            CodeViewer();

            void setTextHighlight();
    };
}

#endif