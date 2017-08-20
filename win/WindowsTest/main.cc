/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3	
*/

#include <cstdlib>
#include <iostream>

#include <Entropy/Aoede/Application.hh>
#include <Entropy/Aoede/Sound.hh>

using namespace std;
using namespace Entropy;
using namespace Entropy::Aoede;
using namespace Entropy::Tethys;

class Usage :
	public Task
{
	public:
		Usage(const string &);
		void operator () ();
	private:
		string _name;
};

class Application :
	public Aoede::Application
{
	public:
		Application(const int, char *[]);
	private:
		std::shared_ptr<Usage> _usage;
		std::shared_ptr<Sound> _sound;
};

int main(int ArgC, char *ArgV[])
{
	try
	{
		::Application app(ArgC, ArgV);
		app();

		return EXIT_SUCCESS;
	}
	catch (exception &e)
	{
		cerr << e << endl;

		return EXIT_FAILURE;
	}
}

::Application::Application(const int argc, char *argv[])
	: Tethys::Application(argc, argv), Aoede::Application(argc, argv)
{
	if (ArgC() != 2) {
		_usage = make_shared<Usage>(ArgV()[0]);

		Add(*_usage);
	}
	else {
		_sound = make_shared<Sound>(ArgV()[1]);

		Add(*_sound);
	}
}

Usage::Usage(const string &name)
	: _name(name)
{}

void Usage::operator () ()
{
	cout << _name << ": file" << endl;
}
