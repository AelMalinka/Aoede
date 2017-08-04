/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Application.hh"

using namespace Entropy::Aoede;
using namespace Entropy::Aoede::AL;
using namespace std;

Application::Application()
	: Tethys::Application(), _context(), _listener()
{}

Application::Application(const int argc, char *argv[])
	: Tethys::Application(argc, argv), _context(), _listener()
{}

Application::~Application() = default;

Context &Application::getContext()
{
	return _context;
}

Listener &Application::getListener()
{
	return _listener;
}

const Context &Application::getContext() const
{
	return _context;
}

const Listener &Application::getListener() const
{
	return _listener;
}
