///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019
#pragma once

#ifndef SOULENGINE_ENTITY_HEADER
#define SOULENGINE_ENTITY_HEADER

#include <Component.hpp>
#include <iostream> 
#include <map> 
#include <memory>


#include <Render_Node.hpp>
#include <Collision_Component.hpp>


namespace engine {

	class Entity
	{
	public:

		typedef std::map<std::string , std::shared_ptr< Component >> CPmap;
		
		typedef std::map<std::string, std::shared_ptr< Entity > > Entity_Map;

		Entity * parent;
		std::string entity_id;
		CPmap components;
		Entity_Map children;
		glt::Render_Node* renderer;
		Entity(std::string& id, glt::Render_Node* rendererP) :entity_id(id), renderer(rendererP) {}
		Entity(Entity* parentP, CPmap componentsP, Entity_Map childrenP) : parent(parentP), components(componentsP), children(childrenP) {};
		//Entity() = default;
		~Entity() {
			
		}

		Entity* get_parent() { return parent; };

		virtual void Update() {}

		virtual void OnCollision(Collision_Component & collider) {}

	public:

		Component * get_component(const std::string & id);
		

		void add_component(const std::string & id, std::shared_ptr< Component > & c);
		
	};
}

#endif