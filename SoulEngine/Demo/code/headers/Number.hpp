///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#include <Entity.hpp>
#include <Transform_Component.hpp>
#include <memory>
#include <Scene.hpp>
#include <Component_Factory.hpp>
#include <Render_Component.hpp>

using namespace engine;

class Number : public Entity
{
public:

	Scene * scene;
	

	Number(Scene &sceneP, std::string& id, std::string& path ,glt::Render_Node* rendererP) : Entity(id, rendererP), scene(&sceneP)
	{
		
		shared_ptr< Component > component = Component_Factory::instance()->create_component("Render", dynamic_cast<Entity*>(this));
		add_component("Render", component);
		dynamic_cast<Render_Component*>(get_component("Render"))->Mesh(path);
		scene->renderTask.add(*component);
		component = Component_Factory::instance()->create_component("Transform", dynamic_cast<Entity*>(this));
		add_component("Transform", component);
		component = Component_Factory::instance()->create_component("Collision", dynamic_cast<Entity*>(this));
		add_component("Collision", component);
		scene->renderTask.renderer->add(entity_id, dynamic_cast<Render_Component*>(get_component("Render"))->mesh);
		scene->entities[entity_id] = shared_ptr<Entity>(this);

		auto * transformMatrix = dynamic_cast<Transform_Component*>(get_component("Transform"));
		//stransformMatrix->SetScale(glm::vec3(1.f, 1.f, 1.f));
		dynamic_cast<Collision_Component*>(get_component("Collision"))->size = transformMatrix->GetScale();

	}


	void OnCollision(Collision_Component & other) override
	{
		
	}
};