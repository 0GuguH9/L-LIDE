#include "core/theme.hpp"

using namespace LLIDE::Core;

void Theme::addThemeToken(const std::string id, const TextStyle hexColor) {

    themeTokens[id] = hexColor;
}

void Theme::removeThemeToken(const std::string id) {

    themeTokens.erase(id);
}

ThemeToken Theme::getThemeToken(const std::string id) {

    auto findReturn = themeTokens.find(id);

    if (findReturn == themeTokens.end())
        return {id, defaultTextStyle};

    return {id, themeTokens[id]};
}
