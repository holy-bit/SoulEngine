///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_RENDER_COMPONENT_HEADER
#define SOULENGINE_RENDER_COMPONENT_HEADER


#include <Transform_Component.hpp>
#include <iostream>
#include <internal/declarations.hpp>
#include <Node.hpp>
#include <Model_Obj.hpp>
#include <Model.hpp>
#include <Cube.hpp>

namespace engine {

	class Render_Component : public Component
	{
	public:
		shared_ptr< glt::Node > node;
		shared_ptr< glt::Node > get_node() { return  node; }
		shared_ptr< glt::Model > mesh;

		void update()
		{
			
			auto transform_component = dynamic_cast<Transform_Component*>(entity->get_component("Transform"));
			auto transform = transform_component->get_transform();
			entity->renderer->get(entity->entity_id)->set_transformation(transform);
		}

		void Mesh(const std::string & path)
		{
			shared_ptr< glt::Model > meshobj(new glt::Model_Obj(path));
			mesh = meshobj;
		}

		void cubeMesh() 
		{
			shared_ptr< Model  > cube(new Model);
			cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());
			mesh = cube;
		}

	public:
		
		Render_Component(Entity* entityP) : Component(entityP) {
			//shared_ptr< Model  > cube(new Model);
			//cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());
			//mesh = cube;
		};
	};

	/*class Mesh_Component : public Render_Component
	{
		shared_ptr< glt::Model > mesh;
		Mesh_Component(const std::string & path)
		{
			node = new glt::Model_Obj(path);
		}
	};*/
}

#endif