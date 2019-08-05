#pragma once

#ifndef SOULENGINE_MODULE_HEADER
#define SOULENGINE_MODULE_HEADER


#include <Component.hpp>
#include <Task.hpp>

namespace engine {

	class Module
	{
		virtual Task * get_task() = 0;
		//virtual Component * create_component(xml_node<> * data) = 0;
	};
}

#endif