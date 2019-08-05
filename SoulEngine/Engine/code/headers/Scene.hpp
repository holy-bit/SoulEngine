///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019


#ifndef SOULENGINE_SCENE_HEADER
#define SOULENGINE_SCENE_HEADER

#include "Kernel.hpp"


#include <iostream> 
#include <iterator> 
#include <map> 
#include <Entity.hpp>
#include <Render_Task.hpp>
#include <Render_Node.hpp>
#include <Input_Task.hpp>


#include <Update_Entities_Task.hpp>
#include <Collision_Task.hpp>


using namespace std;
using namespace rapidxml;

namespace engine {


	class Scene
	{
	public:
		Kernel kernel = Kernel::instance();
		Window window;

		Render_Task renderTask;
		Input_Task inputTask;
		Update_Entities_Task updateTask;
		Collision_Task collisionTask;
		
		std::string path;
		rapidxml::xml_document<> sceneXML;
		
		
		map<string, std::shared_ptr< Entity > > entities;
		Scene(const string * scene_data_file) : path(*scene_data_file), window(Window("TEST", 1280, 720/*, true*/)), renderTask(Render_Task(window,0)), inputTask(Input_Task(window, 0)),
			updateTask(Update_Entities_Task(&entities,0)),  collisionTask(Collision_Task(&entities, 0)){ load_scene(); }


		void run();
		
		void load_scene();
		
		bool isPressed(int key);
		
		void load_entities(xml_node<> * entities);


		void load_components(xml_node<>* component_node, Entity & entity);
		


	};

}

#endif