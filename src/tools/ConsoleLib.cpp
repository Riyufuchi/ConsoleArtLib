//==============================================================================
// File       : ConsoleArtLib.cpp
// Author     : riyufuchi
// Created on : Dec 19, 2025
// Last edit  : Dec 19, 2025
// Copyright  : Copyright (c) 2025, riyufuchi
// Description: consoleartlib
//==============================================================================

#include "../includes/ConsoleArtLib.h"

namespace consoleartlib
{
ConsoleArtLib::ConsoleArtLib()
{
}
ConsoleArtLib::~ConsoleArtLib()
{
}
std::string ConsoleArtLib::aboutLibrary()
{
	return std::format("ConsoleLib {}\n{}\nCompiled on: {} {}\nC++ version: {}", _VERSION, _COPYRIGHT_HEADER, __DATE__, __TIME__, __cplusplus);
}
} /* namespace consolelib */
