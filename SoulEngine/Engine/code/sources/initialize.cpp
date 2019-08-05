///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019 

#include <SDL.h>
#include <cstdlib>

namespace engine
{

	extern void finalize();

	/** Esta funci�n se llama en aquellos lugares en los que se necesita
	  * inicializar alg�n subsistema de SDL.
	  */
	bool initialize(int subsystem)
	{
		// Se hace que al salir de la funci�n main() se invoque autom�ticamente
		// a la funci�n finalize() una vez:

		static bool finalize_is_not_set = true;

		if (finalize_is_not_set)
		{
			finalize_is_not_set = false;

			std::atexit(finalize);
		}

		// Se inicializa el subsistema si no estaba inicializado:

		if (!SDL_WasInit(subsystem))
		{
			return SDL_Init(subsystem) == 0;
		}

		return true;
	}

}
