#include "core/code_viewer.hpp"

#include <gtkmm/texttag.h>
#include <pangomm/attributes.h>
#include <pangomm/fontdescription.h>

#include <regex>

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

void CodeViewer::highlight(const std::string regex, const TextStyle style) {

    Glib::RefPtr<Gtk::TextBuffer> buffer = viewer.get_buffer();

    std::string text = buffer->get_text();

    Glib::RefPtr<Gtk::TextTag> keywordTag = Gtk::TextBuffer::Tag::create();

    keywordTag->property_foreground() = style.hexColor;
    if (style.strikethrough)
        keywordTag->property_strikethrough() = style.strikethrough;
    else if (style.resetOnFalse)
        keywordTag->property_strikethrough() = style.strikethrough;

    if (style.bold)
        keywordTag->property_weight() = Pango::Weight::BOLD;
    else if (style.resetOnFalse)
        keywordTag->property_weight() = Pango::Weight::NORMAL;

    if (style.underline)
        keywordTag->property_underline() = Pango::Underline::SINGLE;
    else if (style.resetOnFalse)
        keywordTag->property_underline() = Pango::Underline::NONE;

    buffer->get_tag_table()->add(keywordTag);

    std::regex regexEpr(regex);

    Gtk::TextBuffer::iterator start, end;
    start = buffer->begin();
    end = buffer->end();

    std::smatch match;

    int offset = 0;
    
    while (std::regex_search(text, match, regexEpr)) {

        Gtk::TextBuffer::iterator match_start = start;
        match_start.forward_chars(match.position() + offset);

        Gtk::TextBuffer::iterator match_end = match_start;
        match_end.forward_chars(match.length());

        buffer->apply_tag(keywordTag, match_start, match_end);

        offset += text.length() - match.suffix().str().length();
        
        text = match.suffix().str();
    }
}
