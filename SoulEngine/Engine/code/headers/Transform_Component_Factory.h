///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_TRANSFORM_COMPONENT_FACTORY_HEADER
#define SOULENGINE_TRANSFORM_COMPONENT_FACTORY_HEADER

#include <iostream>
#include <Component_Factory.hpp>
#include <Transform_Component.hpp>

namespace engine
{
	class Transform_Component_Factory
	{
	public:

		static std::shared_ptr< Component > create_component(Entity* entity)
		{
			std::shared_ptr< Component > c(new Transform_Component(entity));
				// PARSEAR XML_DATA Y AÑADIR LO QUE SE ENCUENTRE AL COMPONENTE
				return c;
		}

		static void initialize()
		{
			Component_Factory::instance()->register_factory("Transform", create_component);
		}
		
	};
}

#endif