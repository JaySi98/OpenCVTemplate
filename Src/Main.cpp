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

    cv::Mat img(500, 500, CV_8UC3);
    cv::RNG& rng = cv::theRNG();

    for(;;)
    {
        int i, count = (unsigned)rng % 100 + 1;
        std::vector<cv::Point> points;

        for(int i = 0; i < count; i++)
        {
            cv::Point point;
            point.x = rng.uniform(img.cols/4, img.cols*3/4);
            point.y = rng.uniform(img.cols/4, img.cols*3/4);

            points.push_back(point);
        }

        std::vector<cv::Point> hull;
        cv::convexHull(points, hull, true);

        img = cv::Scalar::all(0);
        for(int i = 0; i <count; i++)
        {
            cv::circle(img, points[i], 3, cv::Scalar(0,0,255), cv::FILLED, cv::LINE_AA);            
        }

        cv::polylines(img, hull, true, cv::Scalar(0,255,0), 1, cv::LINE_AA);
        cv::imshow("hull", img);

        char key = (char)cv::waitKey();

        if(key == 'q')
            break;
    }

   return EXIT_SUCCESS;
}
