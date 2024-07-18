#include "core/code_viewer.hpp"

using namespace LLIDE::Core;

CodeViewer::CodeViewer() {

    // Padding...
    viewer.set_top_margin(10);
    viewer.set_bottom_margin(10);
    viewer.set_left_margin(10);
    viewer.set_right_margin(10);

    // All sides to 16
    viewer.set_margin(16);
    // One side to 56
    viewer.set_margin_top(56);

    viewer.set_monospace(true);
}
