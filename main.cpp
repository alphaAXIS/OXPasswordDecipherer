#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;

#ifndef OSPLATFORMUTIL_H
#define OSPLATFORMUTIL_H

/*
   The operating system, must be one of: (I_OS_x)

	 DARWIN   - Any Darwin system (macOS, iOS, watchOS, tvOS)
	 ANDROID  - Android platform
	 WIN32    - Win32 (Windows 2000/XP/Vista/7 and Windows Server 2003/2008)
	 WINRT    - WinRT (Windows Runtime)
	 CYGWIN   - Cygwin
	 LINUX    - Linux
	 FREEBSD  - FreeBSD
	 OPENBSD  - OpenBSD
	 SOLARIS  - Sun Solaris
	 AIX      - AIX
	 UNIX     - Any UNIX BSD/SYSV system
*/

#define OS_PLATFORM_UTIL_VERSION 1.0.0.180723

// DARWIN
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
#  include <TargetConditionals.h>
#  if defined(TARGET_OS_MAC) && TARGET_OS_MAC
#    define I_OS_DARWIN
#    ifdef __LP64__
#      define I_OS_DARWIN64
#    else
#      define I_OS_DARWIN32
#    endif
#  else
#    error "not support this Apple platform"
#  endif
// ANDROID
#elif defined(__ANDROID__) || defined(ANDROID)
#  define I_OS_ANDROID
#  define I_OS_LINUX
// Windows
#elif !defined(SAG_COM) && (!defined(WINAPI_FAMILY) || WINAPI_FAMILY==WINAPI_FAMILY_DESKTOP_APP) && (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
#  define I_OS_WIN32
#  define I_OS_WIN64
#elif !defined(SAG_COM) && (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__))
#  if defined(WINAPI_FAMILY)
#    ifndef WINAPI_FAMILY_PC_APP
#      define WINAPI_FAMILY_PC_APP WINAPI_FAMILY_APP
#    endif
#    if defined(WINAPI_FAMILY_PHONE_APP) && WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
#      define I_OS_WINRT
#    elif WINAPI_FAMILY==WINAPI_FAMILY_PC_APP
#      define I_OS_WINRT
#    else
#      define I_OS_WIN32
#    endif
#  else
#    define I_OS_WIN32
#  endif
//CYGWIN
#elif defined(__CYGWIN__)
#  define I_OS_CYGWIN
// sun os
#elif defined(__sun) || defined(sun)
#  define I_OS_SOLARIS
// LINUX
#elif defined(__linux__) || defined(__linux)
#  define I_OS_LINUX
// FREEBSD
#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__)
#  ifndef __FreeBSD_kernel__
#    define I_OS_FREEBSD
#  endif
#  define I_OS_FREEBSD_KERNEL
// OPENBSD
#elif defined(__OpenBSD__)
#  define I_OS_OPENBSD
// IBM AIX
#elif defined(_AIX)
#  define I_OS_AIX
#else
#  error "not support this OS"
#endif

#if defined(I_OS_WIN32) || defined(I_OS_WIN64) || defined(I_OS_WINRT)
#  define I_OS_WIN
#endif

#if defined(I_OS_WIN)
#  undef I_OS_UNIX
#elif !defined(I_OS_UNIX)
#  define I_OS_UNIX
#endif

#ifdef I_OS_DARWIN
#define I_OS_MAC
#endif
#ifdef I_OS_DARWIN32
#define I_OS_MAC32
#endif
#ifdef I_OS_DARWIN64
#define I_OS_MAC64
#endif

#endif
#include <Windows.h>

int main() {
	std::unordered_map<std::string, char> key_value_map = {
		{"OX", 'a'},
		{"OOX", 'b'},
		{"OXX", 'c'},
		{"OOXX", 'd'},
		{"--O-OX--XX", 'e'},
		{"OO--X-OX--", 'f'},
		{"--O-OX----X-OX--", 'g'},
		{"OO--X-OOX--", 'h'},
		{"O--X-OXX--", 'i'},
		{"OO--X-OXX--", 'j'},
		{"O--X-OOXX--", 'k'},
		{"OO--X-OOXX--", 'l'},
		{"O--X-----O-OX--XX----", 'm'},
		{"OO--X-----O-OX--XX----", 'n'},
		{"O", 'o'},
		{"OO--X---OO--X-OX------", 'p'},
		{"O--X-----O-OX----X-OX------", 'q'},
		{"OO--X-----O-OX----X-OX------", 'r'},
		{"O--X---OO--X-OOX------", 's'},
		{"OO--X---OO--X-OOX------", 't'},
		{"O--X---O--X-OXX------", 'u'},
		{"OO--X---O--X-OXX------", 'v'},
		{"O--X---OO--X-OXX------", 'w'},
		{"X", 'x'},
		{"O--X---O--X-OOXX------", 'y'},
		{"OO--X---O--X-OOXX------", 'z'},
		{"||", '0'},
		{"|O|", '1'},
		{"|X|", '2'},
		{"|OX|", '3'},
		{"|OOX|", '4'},
		{"|OXX|", '5'},
		{"|OOXX|", '6'},
		{"|--O-OX--XX|", '7'},
		{"|OO--X-OX--|", '8'},
		{"|--O-OX----X-OX--|", '9'},
		{"=O--X---OO--X-----O-OX--XX--------=", '!'},
		{"=OO--X---OO--X---OO--X-OOX----------=", ','},
		{"=OO--X---O--X---O--X-OXX----------=", '.'}
	};
#ifdef I_OS_WIN
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	std::cout << "OX Password Decipherer - 1.0.4" << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
	std::cout << "\033[93mOX Password Decipherer - 1.0.4\033[0m" << std::endl;
#endif
	std::cout << "Copyright (C) alphaAXIS, Inc." << std::endl;
	std::cout << "Type \"help\", \"copyright\" or \"credits\" for more information." << std::endl;
	std::string inputLine;
	while (true) {
		std::cout << ">>> ";
		std::getline(std::cin, inputLine);
		if (inputLine == "oxpd --end") {
			break;
		} else if (inputLine == "help") {
			std::cout << "Type \"oxpd --help\" to see the full imformation." << std::endl;
			continue;
		} else if (inputLine == "copyright") {
			std::cout << "Copyright (C) 2018-2024 alphaAXIS, Inc." << std::endl;
			std::cout << "All rights reserved." << std::endl;
			continue;
		} else if (inputLine == "credits") {
			std::cout << "Thanks to The Little Pig Team, ALIndustry Holding Group and"
				"a cast of hundreds for supporting OXPasswordDecipherer and alphaAXIS, Inc. development."
				"See https://www.github.com/alphaAXIS/OXPasswordDecipherer.git for more imformation." << std::endl;
			continue;
		} else if (inputLine == "oxpd --help") {
			std::cout << "Commands:" << std::endl;
			std::cout << "oxpd --version: See the version of this product." << std::endl;
			std::cout << "oxpd --end: End this program." << std::endl;
			continue;
		} else if (inputLine == "oxpd --version") {
#ifdef I_OS_WIN
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			std::cout << "OX Password Decipherer v.1.0.4-beta on 7/29/2024" << std::endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			continue;
#else
			std::cout << "\033[38;5;94mOX Password Decipherer v.1.0.4-beta on 7/29/2024\033[0m" << std::endl;
			continue;
#endif
		}
		std::istringstream iss(inputLine);
		std::string key;
		while (iss >> key) {
			auto it = key_value_map.find(key);
			if (it != key_value_map.end()) {
				std::cout << it->second << std::endl;
			}
			else {
#ifdef I_OS_WIN
					HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cerr << "Error: The key '" << key << "' was not found in the map." << std::endl;
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
					std::cerr << "\033[31mError: The key '" << key << "' was not found in the map.\033[0m" << std::endl;
#endif
			}
		}
	}
	return 0;
}