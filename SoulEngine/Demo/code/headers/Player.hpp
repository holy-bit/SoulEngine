///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019
#pragma once

#include <Entity.hpp>
#include <Transform_Component.hpp>
#include <Keyboard.hpp>
#include <memory>
#include <Sound.hpp>

using namespace engine;

class Player : public Entity {

public:

	Scene * scene;
	Sound wall_collision;
	Sound pick_sound;
	int currentNumber=0;

	Player(Scene &sceneP, std::string& id, glt::Render_Node* rendererP) : Entity(id, rendererP), scene(&sceneP), wall_collision()
	{
		wall_collision.load("../../assets/sources/oof.wav", 44100, NULL, 2, NULL);
		pick_sound.load("../../assets/sources/takenumber.wav", 44100, NULL, 2, NULL);
		shared_ptr< Component > component = Component_Factory::instance()->create_component("Render", dynamic_cast<Entity*>(this));
		add_component("Render", component);
		dynamic_cast<Render_Component*>(get_component("Render"))->cubeMesh();
		scene->renderTask.add(*component);
		component = Component_Factory::instance()->create_component("Transform", dynamic_cast<Entity*>(this));
		add_component("Transform", component);
		component = Component_Factory::instance()->create_component("Collision", dynamic_cast<Entity*>(this));
		add_component("Collision", component);
		//dynamic_cast<Collision_Component*>(get_component("Collision"))->size = 
		scene->renderTask.renderer->add(entity_id, dynamic_cast<Render_Component*>(get_component("Render"))->mesh);
		scene->entities[entity_id] = shared_ptr<Entity>(this);
		dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
	}

	void Update() override{

		auto * transformMatrix = dynamic_cast<Transform_Component*>(get_component("Transform"));

		if (scene->isPressed(Keyboard::KEY_W))
			transformMatrix->translate(glm::vec3(0.f, 0.4f, 0.f));
		if (scene->isPressed(Keyboard::KEY_A))
			transformMatrix->translate(glm::vec3(-0.4f, 0.f, 0.f));
		if (scene->isPressed(Keyboard::KEY_S))
			transformMatrix->translate(glm::vec3(0.f, -0.4f, 0.f));
		if (scene->isPressed(Keyboard::KEY_D))
			transformMatrix->translate(glm::vec3(0.4f, 0.f, 0.f));
	}

	void OnCollision(Collision_Component & other) override 
	{
		if (other.entity->entity_id == "wall1" || other.entity->entity_id == "wall2" || other.entity->entity_id == "wall3" || other.entity->entity_id == "wall4" || other.entity->entity_id == "wall5")
		{
			dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
			wall_collision.play();
		}
		
		if (other.entity->entity_id == "number1" ) {
		
			pick_sound.play();
			dynamic_cast<Transform_Component*>(other.entity->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
			currentNumber++;
		}
		else if (other.entity->entity_id == "number2") {
			if (currentNumber == 1) {
				pick_sound.play();
				dynamic_cast<Transform_Component*>(other.entity->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				currentNumber++;
			}
			else {
				wall_collision.play();
				dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
			}
		}
		else if (other.entity->entity_id == "number3") {
			if (currentNumber == 2) {
				pick_sound.play();
				dynamic_cast<Transform_Component*>(other.entity->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				currentNumber++;
			}
			else {
				wall_collision.play();
				dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
			}
		}
		else if (other.entity->entity_id == "number4") {
			if (currentNumber == 3) {
				pick_sound.play();
				dynamic_cast<Transform_Component*>(other.entity->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				currentNumber++;
			}
			else {
				wall_collision.play();
				dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
			}
		}
		else if (other.entity->entity_id == "number5") {
			if (currentNumber == 4) {
				pick_sound.play();
				dynamic_cast<Transform_Component*>(other.entity->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				dynamic_cast<Transform_Component*>(scene->entities.find("wall1")->second->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				dynamic_cast<Transform_Component*>(scene->entities.find("wall2")->second->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				dynamic_cast<Transform_Component*>(scene->entities.find("wall3")->second->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));
				dynamic_cast<Transform_Component*>(scene->entities.find("wall4")->second->get_component("Transform"))->setPosition(glm::vec3(100.f, 1000.f, 1000.f));			
			}
			else {
				wall_collision.play();
				dynamic_cast<Transform_Component*>(get_component("Transform"))->setPosition(glm::vec3(0.f, 0.f, -50.f));
			}
		}
	}
};
