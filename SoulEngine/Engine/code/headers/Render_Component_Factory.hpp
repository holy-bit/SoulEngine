///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once


#ifndef SOULENGINE_RENDER_COMPONENT_FACTORY_HEADER
#define SOULENGINE_RENDER_COMPONENT_FACTORY_HEADER

#include <iostream>
#include <Component_Factory.hpp>
#include <Render_Component.hpp>
#include <Render_Task.hpp>

namespace engine
{
	class Render_Component_Factory
	{
	public:

		static std::shared_ptr< Component > create_component(Entity* entity)
		{
			//shared_ptr< Model  > cube(new Model);
			std::shared_ptr< Component > c(new Render_Component(entity));
			// PARSEAR XML_DATA Y AÑADIR LO QUE SE ENCUENTRE AL COMPONENTE
			return c;
		}

		static void initialize()
		{
			Component_Factory::instance()->register_factory("Render", create_component);
		}

	};
}

#endif