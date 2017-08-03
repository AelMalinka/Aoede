/*	Copyright 2017 (c) Michael Thomas (malinka) <malinka@entropy-development.com>
	Distributed under the terms of the GNU Affero General Public License v3
*/

#if !defined ENTROPY_AOEDE_TYPES_INC
#	define ENTROPY_AOEDE_TYPES_INC

#	include "Exception.hh"
#	include <glm/glm.hpp>

	namespace Entropy
	{
		namespace Aoede
		{
			using Matrix = glm::mat4;
			using Vertex = glm::vec3;
			using Dimension = glm::mat4::value_type;
		}
	}

#endif
