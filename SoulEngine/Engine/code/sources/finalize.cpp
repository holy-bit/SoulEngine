///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

#include <SDL.h>

namespace engine
{

	/** Esta funci�n se llamar� autom�ticamente al salir de la funci�n main() solo
	  * si se inicializa alg�n subsistema de SDL.
	  */
	void finalize()
	{
		SDL_Quit();
	}

}