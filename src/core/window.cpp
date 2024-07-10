#include "headers/window.hpp"
#include <gtkmm/cssprovider.h>
#include <gtk/gtk.h>

using namespace LLIDE::Core;

LLIDEWindow::LLIDEWindow() {

    set_title(name);
    set_default_size(defaultWidth, defaultHeight);

    codeView.set_border_width(10);
    codeView.set_margin_top(56);
    codeView.set_margin_left(16);
    codeView.set_margin_right(16);
    codeView.set_margin_bottom(24);
    codeView.set_monospace(true);

    add(codeView);

    GtkSettings* settings = gtk_settings_get_default();
    g_object_set(settings, "gtk-application-prefer-dark-theme", TRUE, "some-custom-dark-theme", NULL);

    GtkWindow* windowGtk = GTK_WINDOW(gobj());

    GdkRGBA bgWindowColor;
    gdk_rgba_parse(&bgWindowColor, "#2E2E28");
    gtk_widget_override_background_color(GTK_WIDGET(windowGtk), GTK_STATE_FLAG_NORMAL, &bgWindowColor);

    GtkTextView* text_view = GTK_TEXT_VIEW(codeView.gobj());

    GdkRGBA bg_color;
    gdk_rgba_parse(&bg_color, "#1C1C13");
    gtk_widget_override_background_color(GTK_WIDGET(text_view), GTK_STATE_FLAG_NORMAL, &bg_color);

    GtkTextBuffer* buffer = gtk_text_view_get_buffer(text_view);
    GtkTextTagTable* tag_table = gtk_text_buffer_get_tag_table(buffer);

    GtkTextTag* selected_tag = gtk_text_tag_new("selected");
    g_object_set(selected_tag, "background-set", TRUE, "background", "#3366CC", NULL); // Cor de fundo azul

    gtk_text_tag_table_add(tag_table, selected_tag);

    GtkTextTag* existing_tag = gtk_text_buffer_create_tag(buffer, "fg_color", "foreground", "#FFFFFF", NULL);

    GtkTextIter start, end;
    gtk_text_buffer_get_selection_bounds(buffer, &start, &end);

    gtk_text_buffer_apply_tag(buffer, existing_tag, &start, &end);

    show_all_children();
}
