/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3	
*/

#include <cstdlib>
#include <iostream>
#include <windows.h>

#include <Entropy/Aoede/Application.hh>

using namespace std;
using namespace Entropy::Aoede;

int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		return EXIT_SUCCESS;
	}
	catch (exception &e)
	{
		MessageBox(nullptr, e.what(), "Error!", MB_ICONEXCLAMATION | MB_OK);
		return EXIT_FAILURE;
	}
}