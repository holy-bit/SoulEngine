///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_INPUT_TASK_HEADER
#define SOULENGINE_INPUT_TASK_HEADER

#include <Task.hpp>
#include <Window.hpp>
#include <Keyboard.hpp>
#include <Kernel.hpp>
#include <list>

namespace engine {
	class Input_Task : public Task
	{
	private:

		
		bool exit = false;
		Window * window;
	public: 

		std::list<int> pressedKeys;

		Input_Task(Window& windowptr, int given_priority) : window(&windowptr), Task(given_priority) {}
		
		void initialize() override {}
		void update() override;	
		void finalize() override {}
	
	};

}

#endif
