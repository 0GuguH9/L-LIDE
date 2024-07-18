#include "core/theme.hpp"

using namespace LLIDE::Core;

void Theme::addThemeToken(std::string id, std::string hexColor) {

    themeTokens[id] = hexColor;
}

void Theme::removeThemeToken(std::string id) {

    themeTokens.erase(id);
}

ThemeToken Theme::getThemeToken(std::string id) {

    auto findReturn = themeTokens.find(id);

    if (findReturn == themeTokens.end())
        return {id, "#FFFFFF"};

    return {id, themeTokens[id]};
}
