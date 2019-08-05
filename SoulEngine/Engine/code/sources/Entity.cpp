///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <Entity.hpp>

namespace engine
{
	Component * Entity::get_component(const std::string & id)
	{
		auto i = components.find(id);

		return i != components.end() ? i->second.get() : nullptr; // true cambiar a i
	}

	void Entity::add_component(const std::string & id, std::shared_ptr< Component > & c)
	{

		components[id] = c;
		//components.insert({ id,c });
		c->entity = this;
	}
}