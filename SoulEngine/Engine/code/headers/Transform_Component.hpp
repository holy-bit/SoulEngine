///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_TRANSFORM_COMPONENT_HEADER
#define SOULENGINE_TRANSFORM_COMPONENT_HEADER

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective*/
#include <Component.hpp>
#include <Entity.hpp>


namespace engine
{
	class Transform_Component : public Component
	{
		glm::mat4 local_transform;		// guarda solo los cambios locales
		glm::mat4 transform;			// guarda los cambios locales combinados con los parents
		bool updated;

	public:
		glm::mat4 & get_transform();

		
		//Matrix44 transform;
		Transform_Component(Entity* entityP) : Component(entityP) {	}
		void set_transform(glm::mat4 new_Transform){	transform = new_Transform;	}
	public:
		//void move(const Vector3f &);
		void rotate_around_z(float angle);

		//glm::mat4 & set_transform(glm::mat4 &);
		
		void update() override
		{
			updated = false;
		}

		void translate(glm::vec3 translation) {
		set_transform(glm::translate(transform, translation));
		}

		void setPosition(glm::vec3 position) { 
			transform[3] = glm::vec4(position.x, position.y, position.z, transform[3].w);
		}

		

		void SetScale(glm::vec3 scale)
		{
			transform[0].x = scale.x;
			transform[1].y = scale.y;
			transform[2].z = scale.z;
		}

		glm::vec3 GetScale()
		{
			return glm::vec3(transform[0].x, transform[1].y, transform[2].z);
		}

		glm::vec3 GetPosition() { return glm::vec3(transform[3].x, transform[3].y, transform[3].z); }
	};
}

#endif