///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once


#ifndef SOULENGINE_COLLISION_COMPONENT_FACTORY_HEADER
#define SOULENGINE_COLLISION_COMPONENT_FACTORY_HEADER

#include <iostream>
#include <Component_Factory.hpp>
#include <Collision_Component.hpp>
#include <Render_Task.hpp>

namespace engine
{
	class Collision_Component_Factory
	{
	public:

		static std::shared_ptr< Component > create_component(Entity* entity)
		{
			std::shared_ptr< Component > c(new Collision_Component(entity));

			return c;
		}

		static void initialize()
		{
			Component_Factory::instance()->register_factory("Collision", create_component);
		}

	};
}

#endif