/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#include "Exception.hh"

using namespace std;
using namespace Entropy::Log;

namespace Entropy {
	namespace Aoede {
		Logger Log("Aoede");

		string getAlError(const ALenum code)
		{
			switch(code) {
				case AL_NO_ERROR:	
					return "No Error"s;
				case AL_INVALID_NAME:
					return "Invalid Name"s;
				case AL_INVALID_ENUM:
					return "Invalid Enum"s;
				case AL_INVALID_VALUE:
					return "Invalid Value"s;
				case AL_INVALID_OPERATION:
					return "Invalid Operation"s;
				case AL_OUT_OF_MEMORY:
					return "Out of Memory"s;
				default:
					return "Unknown Error"s;
			}
		}
	}
}
