### L-LIDE: Low-Level Integrated Development Environment

**L-LIDE** is a IDE for low level software development in (mainly) Linux (will have suport for Windows). Is a totally open-source and extremely customizable software, so be free to help the IDE or for making your costumizations.

### Features

- **Maded for Low-Level language**: having a good native suport for low-level languages like C, C++, assembly (current supporting x86 and x64) or software helpers/builders like CMake, Make, shell scripts, or frameworks/API like OpenGL, GTK+ and gtkmm.
- **Maded for Linux**: by Linux users, for Linux users.
- **Low-level code preview**: you can view a estimated more low-level of your current language (exemple, linkable binary for assembly, or linkable assembly for C/C++).
- **Modificable with plugins**: you can modify entire IDE with plugins. You can change HUD widgets locations, colors (theme), configurations, or language.

### Warnings

- **Windows compatiblity**: the IDE use a custom wrapper for GTK+ to help making the window, and GTK+ can have errors in Windows, so sorry for that :(

### Languages, Libs, Helpers or Builders compatibility checklist

- ❌ **GTK+ e gtkmm**: native graphics libs/wrapper for apps in Linux.
- ❌ **Custom GTK+ wrapper**: for helping making plugins for this IDE.
- ❌ **CMake e Make**: common projects builders in Linux.
- ❌ **Shell Scripts (.sh)**: shell scripts is a native Linux script for making commands or tasks easily. Its like .bat of windows.
- ❌ **Assembly (x86 adn x64)**: most common assembly in desktops.
