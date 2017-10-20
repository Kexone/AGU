#include "polygon.h"
#include <opencv2/shape/hist_cost.hpp>
#include <iostream>

cv::Point2f Polygon::center = cv::Point2f(0.0f, 0.0f);

Polygon::Polygon()
{
}

std::vector<cv::Point2f> Polygon::getPoints()
{
	return points;
}

void Polygon::setPoints(std::vector<cv::Point2f> points)
{
	this->points = points;
}

