///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <Input_Task.hpp>

namespace engine
{
	void Input_Task::update()
	{


		Window::Event event;

		while (window->poll(event))
		{
			switch (event.type)
			{
			case Window::Event::CLOSE:
			{
				Kernel::instance().set_exit(true);
				break;
			}

			case Window::Event::KEY_PRESSED:
			{
				if (event.data.keyboard.key_code == Keyboard::KEY_ESCAPE)
				{
					Kernel::instance().set_exit(true);
				}

				pressedKeys.push_back(event.data.keyboard.key_code);
				pressedKeys.unique();

				break;
			}
			case Window::Event::KEY_RELEASED:
			{
				for (auto it = std::begin(pressedKeys); it != std::end(pressedKeys); ++it)
				{
					if (*it == event.data.keyboard.key_code) {

						pressedKeys.remove(event.data.keyboard.key_code);
						break;

					}
				}

				break;
			}

			}
		}


	}

}