#include <iostream>
#include <Include/Config.h>

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

int main(int argc, char* argv[])
{
    // std::cout << argv[0] << " Version: " 
    //           << Template_VERSION_MAJOR << "."
    //           << Template_VERSION_MINOR << std::endl;

    cv::CommandLineParser parser(argc, argv, "{help h||}");
    if(parser.has("help"))
    {
        std::cout << "help" << std::endl;
    }

   return EXIT_SUCCESS;
}
