#include <iostream>
#include <Include/Config.h>
#include <SimpleClass.h>

#ifdef ADD_GLFW
    #include <GLFW/glfw3.h>
#endif

#ifdef ADD_OPENCV
    #include <opencv2/opencv.hpp>
#endif

#ifdef ADD_NCURSES
   #include <ncurses.h>
#endif

#ifdef ADD_NCURSES
    #include <boost/regex.hpp>
#endif

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " Version: " 
              << Template_VERSION_MAJOR << "."
              << Template_VERSION_MINOR << std::endl;

    std::cout << "Testing cmake file includes:";
    SimpleClass simpleClass;
    simpleClass.PrintNumber();

   return EXIT_SUCCESS;
}