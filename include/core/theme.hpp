#ifndef LLIDE_CORE_THEME_HPP
#define LLIDE_CORE_THEME_HPP

#include <string>
#include <unordered_map>

namespace LLIDE::Core {

    const std::string defaultColor = "#FFFFFF";

    struct TextStyle {
        std::string hexColor;
        bool bold = false;
        bool strikethrough = false;
        bool underline = false;
        bool resetOnFalse = false;
    };

    const TextStyle defaultTextStyle = {defaultColor, false, false, false};

    struct ThemeToken {
        std::string id;
        TextStyle style;
    };

    class Theme {
        private:
            std::unordered_map<std::string, TextStyle> themeTokens;

        public:
            void addThemeToken(const std::string id, const TextStyle style = defaultTextStyle);
            void removeThemeToken(const std::string id);
            ThemeToken getThemeToken(const std::string id);
    };
}

#endif