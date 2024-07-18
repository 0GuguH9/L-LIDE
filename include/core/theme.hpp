#ifndef LLIDE_CORE_THEME_HPP
#define LLIDE_CORE_THEME_HPP

#include <string>
#include <unordered_map>

namespace LLIDE::Core {
    struct ThemeToken {
        std::string id;
        std::string hexColor;
    };

    class Theme {
        private:
            std::unordered_map<std::string, std::string> themeTokens;

        public:
            void addThemeToken(std::string id, std::string hexColor);
            void removeThemeToken(std::string id);
            ThemeToken getThemeToken(std::string id);
    };
}

#endif