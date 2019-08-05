///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#pragma once

#ifndef SOULENGINE_WINDOW_HEADER
#define SOULENGINE_wINDOW_HEADER

#include <string>
#include <internal/declarations.hpp>

namespace engine
{

	class Window
	{
	public:

		/** Esta clase Event es específica para los eventos de la ventana.
		  * Por ello está anidada dentro de Window. Se podría generalizar.
		  */
		struct Event
		{
			enum Type
			{
				CLOSE,
				KEY_PRESSED,
				KEY_RELEASED
			}
			type;

			union Data
			{
				struct { int key_code; } keyboard;

				struct
				{
					float x, y;
					int   buttons;
				}
				mouse;
			}
			data;
		};

	private:

		SDL_Window  * window;
		SDL_GLContext gl_context;

	public:

		Window(const std::string & title, int width, int height, bool fullscreen = false);
		~Window();

	public:

		/** Retorna el ancho actual de la ventana (el usuario puede cambiarlo).
		  */
		unsigned get_width() const;

		/** Retorna el alto actual de la ventana (el usuario puede cambiarlo).
		  */
		unsigned get_height() const;

		/** Permite extraer un evento de la cola de eventos asociada a la ventana.
		  */
		bool poll(Event & event) const;

		void enable_vsync();

		void disable_vsync();

		/** Borra el buffer de la pantalla usando OpenGL.
		  */
		void clear() const;

		/** Intercambia el buffer visible con el buffer oculto.
		  */
		void swap_buffers() const;

	};

}

#endif
