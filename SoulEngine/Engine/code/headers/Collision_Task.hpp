///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_COLLISION_TASK_HEADER
#define SOULENGINE_COLLISION_TASK_HEADER

#include <Task.hpp>
#include <list>
#include <iostream>
#include <map>
#include <Transform_Component.hpp>

namespace engine {
	class Collision_Task : public Task
	{

	public:

		Collision_Task(std::map<std::string, std::shared_ptr< Entity > >* entitiesP, int given_priority) : entities(entitiesP), Task(given_priority) {}

	private:

		std::map<std::string, std::shared_ptr< Entity > >* entities;

		
		bool exit = false;
		void initialize() override {}
		void update() override;

		void finalize() override {}

		bool checkCollision(Collision_Component* collider, Collision_Component* other);
		

	};

}

#endif
