///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_UPDATE_ENTITIES_TASK_HEADER
#define SOULENGINE_UPDATE_ENTITIES_TASK_HEADER

#include <Task.hpp>
#include <Window.hpp>
#include <Keyboard.hpp>
#include <Kernel.hpp>
#include <list>
#include <iostream>
#include <map>
#include <Entity.hpp>

namespace engine {
	class Update_Entities_Task : public Task
	{
	public:

		std::map<std::string, std::shared_ptr< Entity > >* entities;

		Update_Entities_Task(std::map<std::string, std::shared_ptr< Entity > >* entitiesP, int given_priority) : entities(entitiesP), Task(given_priority) {}
		bool exit = false;
		void initialize() override {}
		void update() override
		{
			for (std::map<std::string, std::shared_ptr< Entity > >::iterator it = entities->begin(); it != entities->end(); ++it)
				it->second->Update();
		}


		void finalize() override {}

	};

}

#endif
