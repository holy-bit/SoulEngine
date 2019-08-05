///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <Scene.hpp>

#include <iostream>
#include <Transform_Component_Factory.h>
#include <Render_Component_Factory.hpp>
#include <Collision_Component_Factory.hpp>
#include <Component_Factory.hpp>
#include <Player.hpp>
#include <Wall.hpp>
#include <Number.hpp>

using namespace engine;
using namespace std;

int main() {

	std::string path{ "..\\..\\..\\Demo\assets\\scene.xml" };
	Scene scena{&path};



	std::string entity_id = "player";
	shared_ptr< Entity > entity(new Player(scena, entity_id,scena.renderTask.renderer.get()));

	std::string entity_id2 = "wall1";
	shared_ptr<Entity> wall_1(new Wall(scena, entity_id2, scena.renderTask.renderer.get()));
	auto * transformComponent = dynamic_cast<Transform_Component*>(wall_1->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(30.f, 0.f, -50.f));
	transformComponent->SetScale(glm::vec3(1.f, 30.f, 1.f));

	 entity_id2 = "wall2";
	shared_ptr<Entity> wall_2(new Wall(scena, entity_id2, scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(wall_2->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(-30.f, 0.f, -50.f));
	transformComponent->SetScale(glm::vec3(1.f, 30.f, 1.f));

	
	 entity_id2 = "wall3";
	shared_ptr<Entity> wall_3(new Wall(scena, entity_id2, scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(wall_3->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(0.f, 30.f, -50.f));
	transformComponent->SetScale(glm::vec3(30.f, 1.f, 1.f));


	 entity_id2 = "wall4";
	shared_ptr<Entity> wall_4(new Wall(scena, entity_id2, scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(wall_4->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(0.f, -30.f, -50.f));
	transformComponent->SetScale(glm::vec3(30.f, 1.f, 1.f));


	path = "..//..//assets//sources//number1.obj";
	std::string entity_id3 = "number1";
	shared_ptr<Entity> number1(new Number(scena, entity_id3, path , scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(number1->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(0.f, 20.f, -50.f));
	

	std::string entity_id4 = "number2";
	path = "..//..//assets//sources//number2.obj";
	shared_ptr<Entity> number2(new Number(scena, entity_id4, path ,scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(number2->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(5.f, 10.f, -50.f));

	std::string entity_id5 = "number3";
	path = "..//..//assets//sources//number3.obj";
	shared_ptr<Entity> number3(new Number(scena, entity_id5, path ,scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(number3->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(10.f, -10.f, -50.f));

	std::string entity_id6 = "number4";
	path = "..//..//assets//sources//number4.obj";
	shared_ptr<Entity> number4(new Number(scena, entity_id6, path ,scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(number4->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(-5.f, 10.f, -50.f));

	std::string entity_id7 = "number5";
	path = "..//..//assets//sources//number5.obj";
	shared_ptr<Entity> number5(new Number(scena, entity_id7, path ,scena.renderTask.renderer.get()));
	transformComponent = dynamic_cast<Transform_Component*>(number5->get_component("Transform"));
	transformComponent->setPosition(glm::vec3(-10.f, -10.f, -50.f));




	

	//dynamic_cast<Render_Component*>(entity->get_component("Render"))->Mesh("C://Users//Versus//Desktop//Motor//Motor//Demo//assets//sources//Lowpoly_tree_sample.obj");
	//scena.renderTask.renderer->get(entity->entity_id)->translate(Vector3(0.f, 2.f, 2.f));
	
	//transformMatrix->set_transform(glm::translate(transformMatrix->get_transform(), glm::vec3(0.f,2.f,2.f)));


	//scena.kernel.get_task()
	/*map<string, Entity >* entities = &scena.entities;
	std::cout << "hola "  << endl;*/
	scena.run();
	
	std::cin.get();
	return 0;
}