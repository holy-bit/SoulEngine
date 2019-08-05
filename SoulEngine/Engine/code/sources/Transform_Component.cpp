///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include "Transform_Component.hpp"
#include "Entity.hpp"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective*/

namespace engine {

	glm::mat4 & Transform_Component::get_transform()
	{
		if (updated) return transform;
		auto parent_entity = entity->get_parent();
		if (parent_entity)
		{
			transform = dynamic_cast<Transform_Component *>(parent_entity->get_component("transform"))->get_transform() * local_transform;
		}
		else
			local_transform = transform;
		//reset = updated;
		return transform;
	}
}