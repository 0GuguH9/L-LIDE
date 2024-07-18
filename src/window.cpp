#include "core/window.hpp"

using namespace LLIDE::Core;

Window::Window() {

    set_title("L-LIDE");
    set_default_size(defaultWidth, defaultHeight);

    g_object_set(gtk_settings_get_default(), "gtk-application-prefer-dark-theme", TRUE, NULL);

    set_child(codeViewer.viewer);

    codeViewer.viewer.get_buffer()->set_text("#include \"heleris/fw/elements/size.h\"\n"
"\n"
"#include <string.h>\n"
"\n"
"HRSSize hrssz_create(int width, int height) {\n"
"    \n"
"    HRSSize size = {width, height};\n"
"    return size;\n"
"}\n"
"\n"
"bool hrssz_equals(HRSSize size1, HRSSize size2) {\n"
"    return size1.width == size2.width && size1.height == size2.height;\n"
"}\n"
"\n"
"int hrssz_area(HRSSize size) {\n"
"    return size.width * size.height;\n"
"}\n"
"\n"
"HRSSize hrssz_scale(HRSSize size, float scale) {\n"
"    HRSSize result = { (int)(size.width * scale), (int)(size.height * scale) };\n"
"    return result;\n"
"}\n"
"\n"
"string_t hrssz_toString(HRSSize size) {\n"
"\n"
"    char buffer[50];\n"
"    snprintf(buffer, sizeof(buffer), \"{Width: %d, Height: %d}\", size.width, size.height);\n"
"\n"
"    return strdup(buffer);\n"
"}\n");

    codeViewer.highlight("\\W", {"#88589E"});
    codeViewer.highlight("\\b(goto|if|else|return|for|while|do|break|continue)\\b", {"#EA7723"});
    codeViewer.highlight("\\b(char|short|int|long|float|double)\\b", {"#EF9A5D"});
    codeViewer.highlight("#(include|define|if|endif|else|ifndef|elif)\\b", {"#FFCF55", true});
    codeViewer.highlight("\".*\"", {"#6F9B78"});
    codeViewer.highlight("#include\\s+\".*\"", {"#FFCF55", false, false, false});
    codeViewer.highlight("#include\\s+<.*>", {"#FFCF55", false, false, true});
}
