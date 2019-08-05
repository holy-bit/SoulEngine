///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <Collision_Task.hpp>

namespace engine
{
	void Collision_Task::update()
	{ 
		for (std::map<std::string, std::shared_ptr< Entity > >::iterator it1 = entities->begin(); it1 != entities->end(); ++it1)
		{
			auto collider = dynamic_cast<Collision_Component*> (it1->second->get_component("Collision"));
			if (collider)
			{
				for (std::map<std::string, std::shared_ptr< Entity > >::iterator it2 = entities->begin(); it2 != entities->end(); ++it2)
				{
					auto other = dynamic_cast<Collision_Component*> (it2->second->get_component("Collision"));
					if (other && checkCollision(collider, other)) collider->entity->OnCollision(*other);
				}
			}
		}
	}

	bool Collision_Task::checkCollision(Collision_Component* collider, Collision_Component* other)
	{
		glm::vec3 position1 = dynamic_cast<Transform_Component*>(collider->entity->get_component("Transform"))->GetPosition();
		glm::vec3 position2 = dynamic_cast<Transform_Component*>(other->entity->get_component("Transform"))->GetPosition();

		if (collider->entity->entity_id != other->entity->entity_id &&
			position1.x - collider->size.x <= position2.x + other->size.x &&
			position1.x + collider->size.x >= position2.x - other->size.x &&
			position1.y - collider->size.y <= position2.y + other->size.y &&
			position1.y + collider->size.y >= position2.y - other->size.y &&
			position1.z - collider->size.z <= position2.z + other->size.z &&
			position1.z + collider->size.z >= position2.z - other->size.z)
			return true;

		return false;
	}
}