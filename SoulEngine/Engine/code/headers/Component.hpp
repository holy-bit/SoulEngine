///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_COMPONENT_HEADER
#define SOULENGINE_COMPONENT_HEADER

#include <rapidxml.hpp>

namespace engine {
	class Entity;
	class Component
	{
	public:
		Entity * entity;
		const rapidxml::xml_node<>* Component_Node;


	public:
		Component(Entity* entityP) : entity(entityP) {};

		Component(const rapidxml::xml_node<> & node,Entity* entityP) : Component_Node(&node), entity(entityP) {}
		virtual ~Component() = default;

		virtual void update() = 0;

		Component* get() { return this; }
	};
}

#endif