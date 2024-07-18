#ifndef LLIDE_CORE_VIEWER_HPP
#define LLIDE_CORE_VIEWER_HPP

#include "core/theme.hpp"

#include <gtkmm/textview.h>

namespace LLIDE::Core {
    class CodeViewer {
        private:

        public:
            Gtk::TextView viewer;

            CodeViewer();

            void addHighlight(const std::string regex, const std::string id);

            void highlight(const std::string regex, const TextStyle hexColor);
    };
}

#endif