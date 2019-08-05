///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019


#pragma once

#ifndef SOULENGINE_COLLISION_COMPONENT_HEADER
#define SOULENGINE_COLLISION_COMPONENT_HEADER

#include <glm/vec3.hpp> // glm::vec3
#include <Component.hpp>


namespace engine
{
	class Collision_Component : public Component
	{
	

	public:
		glm::vec3 size{1,1,1};

		Collision_Component(Entity* entityP) : Component(entityP) {	}
	
	public:
		
		
		void update() override{}
		
	};
}

#endif