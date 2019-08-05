///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <Kernel.hpp>

namespace engine
{
	void Kernel::run()
	{
		exit = false;

		do
		{
			for (Task * task : tasks)
			{
				task->update();
			}

		} while (!exit);
	}

}