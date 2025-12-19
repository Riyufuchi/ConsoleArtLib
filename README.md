# ConsoleArtLib

- [About](#about)
- [Project guide](#project-guide)
- [Used libraries](#used-libraries)
- [Compilation](#compilation)
- [Donate](#donate)

## About

This library is derivation from ConsoleArt and contains utilities to work with images.

## Project guide

- .hpp is used when there is no coresponding .cpp file

## Used libraries

*The libraries below are listed in the order they were added to the project.*

| Name | Used for | Included in this repository |
| :------: | :----------: | :---: |
| [ConsoleLib](https://github.com/Riyufuchi/ConsoleLib) | General utility | ✅ |
| [stb](https://github.com/nothings/stb) | Working with complex picture formats | ✅ |

## Compilation

### Compiled & Tested on

| OS | Compiler |
| :------: | :----------: |
| Ubuntu | g++ 15.2.0 |
| Windows 10 | MSVC 19.50.35719.0 |

### CMake

   ```bash
   git clone https://github.com/Riyufuchi/ConsoleArtLib.git
   cd ConsoleArtLib
   
   # CMake for Linux, macOS, MinGW, Ninja (single-config)
   cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
   cmake --build build
   
   # CMake for Visual Studio, Xcode, Ninja Multi-Config
   cmake -S . -B build
   cmake --build build --config Release
   ```

## Donate

Few dollars will be enough. If you are planning to use this library in a commercial application, then it would be fair if you would send more, possibly a small share of 5-10% of monthly profits.

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/P5P11WTFL)
