///////////////////////////////////////////////////////
//	Author: Luis Chamarro Alonso
//  Date: 11/01/2019

// SDL no soluciona del todo bien el problema de llamar a main() desde WinMain().
// Esta es una alternativa que funciona y no da problemas.

#if defined(_WIN32) || defined(_WIN64)

    #include <windows.h>

    extern int main (int , char ** );

    int WINAPI WinMain (HINSTANCE , HINSTANCE , LPSTR , INT )
    {
        return main (__argc, __argv);
    }

#endif
