#pragma once
#include <opencv2/core/mat.hpp>

struct myPoint
{
public:
	myPoint(cv::Point2f coords, std::string clue) : coord(coords), guide(clue) {};
	cv::Point2f coord;
	std::string guide;
};
