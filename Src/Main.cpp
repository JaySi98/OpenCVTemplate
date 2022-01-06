#include <iostream>
#include <Include/Config.h>

int main(int argc, char* argv[])
{
    std::cout << argv[0] << " Version: " 
              << Template_VERSION_MAJOR << "."
              << Template_VERSION_MINOR << std::endl;

   return EXIT_SUCCESS;
}