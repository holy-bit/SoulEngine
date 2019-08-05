///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_RENDER_TASK_HEADER
#define SOULENGINE_RENDER_TASK_HEADER


#include <Cube.hpp>
#include <Model.hpp>
#include <list>
#include <memory>
#include <string>
#include <Window.hpp>
#include <internal/declarations.hpp>
#include <Render_Node.hpp>
#include <Light.hpp>

using namespace glt;
using namespace std;

namespace engine {
	class Render_Task : public Task
	{
	public:
		Window * window;
		//Window window{ "TEST", 1280, 720/*, true*/ };
		//Renderer renderer{window};
		unique_ptr< glt::Render_Node > renderer;
		list<Component*> components;
		//Render_Module * parent;
		
	public:
		

		Render_Task(Window& windowptr, int given_priority) : window(&windowptr), Task(given_priority) {
			renderer.reset(new Render_Node);

			// Se crean los elementos básicos necesarios para dibujar un cubo:

			shared_ptr< Model  > cube(new Model);
			shared_ptr< Model  > cube1(new Model);
			shared_ptr< Model  > cube2(new Model);
			shared_ptr< Camera > camera(new Camera(20.f, 1.f, 50.f, 1.f));
			shared_ptr< Light  > light(new Light);

			// Es necesario añadir las mallas a los modelos antes de añadir los modelos a la escena:

			/*cube->add(shared_ptr< Drawable >(new Cube), Material::default_material());
			cube1->add(shared_ptr< Drawable >(new Cube), Material::default_material());
			cube2->add(shared_ptr< Drawable >(new Cube), Material::default_material());*/

			// Se añaden los nodos a la escena:

			/*renderer->add("cube", cube);
			renderer->add("cube1", cube1);
			renderer->add("cube2", cube2);*/
			renderer->add("camera", camera);
			renderer->add("light", light);

			// Se configuran algunas propiedades de transformación:
			/*renderer->get("cube1")->translate(Vector3(0.f, 2.f, 2.f));
			renderer->get("cube2")->translate(Vector3(0.f, 3.f, 3.f));*/
			renderer->get("light")->translate(Vector3(10.f, 10.f, 10.f));
		};
		bool exit = false;
		void initialize() override{}
		void update() override
		{
			GLsizei width = GLsizei(window->get_width());
			GLsizei height = GLsizei(window->get_height());

			renderer->get_active_camera()->set_aspect_ratio(float(width) / height);

			glViewport(0, 0, width, height);
			for (auto * component : components)
			{
				component->update();
			}
			window->clear();
			renderer->render();
			window->swap_buffers();
		}
		void finalize() override {}

		void add(Component& component) { components.push_back(&component); }
		
		
		
		
		};
}

#endif
