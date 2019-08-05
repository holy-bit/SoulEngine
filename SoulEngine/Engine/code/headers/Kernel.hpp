///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_KERNEL_HEADER
#define SOULENGINE_KERNEL_HEADER


#include <list>
#include <Task.hpp>
namespace engine {
	class Kernel
	{
		std::list<Task *> tasks;

		bool exit;

	public:

		static Kernel & instance()
		{
			static Kernel kernel;
			return kernel;
		}

	private:

		Kernel() = default;

	public:

		void add(Task & task) { tasks.push_back(&task); }



		const bool& get_exit() { return exit; }

		void set_exit(bool exitP) { exit = exitP; }

		void run();
		

		void stop(){ exit = true;}

	};
}
#endif