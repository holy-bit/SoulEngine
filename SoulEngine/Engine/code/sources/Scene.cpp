///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include "Scene.hpp"


#include <vector>
#include <Window.hpp>

#include <fstream>
#include <Component_Factory.hpp>
#include <Keyboard.hpp>
#include <Transform_Component_Factory.h>
#include <Render_Component_Factory.hpp>
#include <Collision_Component_Factory.hpp>



namespace engine {

	void Scene::run() 
	{
		kernel.run();
		
	}


	bool Scene::isPressed(int key) {
		for (auto it = std::begin(inputTask.pressedKeys); it != std::end(inputTask.pressedKeys); ++it)
		{
			if (*it == key) return true;
		}
		return false;
	}

	void Scene::load_scene()
	{
		Transform_Component_Factory::initialize();
		Render_Component_Factory::initialize();
		Collision_Component_Factory::initialize();

		bool exit = false;
		kernel.add(renderTask);
		kernel.add(inputTask);
		kernel.add(updateTask);
		kernel.add(collisionTask);
	}
}