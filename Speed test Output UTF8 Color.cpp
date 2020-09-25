#include <iostream>
#include <string>
#include <sstream>
#include <fcntl.h>
#include <locale.h>
#include <Windows.h>
#include <time.h>

#define ESC "\x1b"
#define CSI "\x1b["

int main()
{
	// This enables Virtual Terminal Escape Sequences
	DWORD dwMode = 0;
	GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &dwMode);
	dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), dwMode);

	// This enables UTF8
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	//This sets the Locale to en_US
	setlocale(LC_ALL, "american");

	clock_t t_ini, t_fin;
	double secs;
	t_ini = clock();

	std::wstringstream s;

	for (int i = 0; i < 120 * 30; i++)
	{
		if (i % 2 == 0)
			s << ESC"[0m" << ESC"[32m";
		else
			s << ESC"[0m" << ESC"[1m" << ESC"[32m";
		s << "a";
	}

	// Ways to write

	//WriteConsoleW(GetStdHandle(STD_OUTPUT_HANDLE), s.str().c_str(), s.str().size(), NULL, NULL);  // 120	milisegundos
	//wprintf(s.str().c_str());									// 1300	milisegundos
	//std::wcout << s.str() << std::flush;								// 2604	milisegundos
	//std::wcout.write(s.str().c_str(), s.str().size());						// 2632 milisegundos										// 2632 milisegundos
	//std::wcout.flush();

	t_fin = clock();
	secs = (double)(t_fin - t_ini) / 1000.0;
	std::wcout << secs * 1000.0 << " milisegundos";

	std::cin.get();

	return 0;
}
