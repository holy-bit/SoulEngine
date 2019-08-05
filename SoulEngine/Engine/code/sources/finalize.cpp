///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <SDL.h>

namespace engine
{

	/** Esta función se llamará automáticamente al salir de la función main() solo
	  * si se inicializa algún subsistema de SDL.
	  */
	void finalize()
	{
		SDL_Quit();
	}

}