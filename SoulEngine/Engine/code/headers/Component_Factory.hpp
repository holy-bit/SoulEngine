///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_COMPONENT_FACTORY_HEADER
#define SOULENGINE_COMPONENT_FACTORY_HEADER

#include <iostream>
#include <Component.hpp>

namespace engine {

	class Component_Factory
	{
		typedef std::shared_ptr< Component >(*Function) (Entity* entity);

		std::map< std::string, Function > component_factories; //id

	public:

		static Component_Factory * instance() {
			static Component_Factory componentFactory;
			return &componentFactory;
		}

		void register_factory(std::string id, Function factory) //id
		{
			component_factories[id] = factory;
		}

		std::shared_ptr< Component > create_component(std::string id,Entity* entity) //id
		{
			auto factory = component_factories.find(id);

			if (factory != component_factories.end())
			{
				return factory->second(entity);
			}

			return nullptr;
		}

	};
}

#endif