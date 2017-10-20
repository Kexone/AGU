#pragma once
#include <opencv2/core/mat.hpp>


class Polygon
{
public:
	Polygon();
	std::vector<cv::Point2f> getPoints();
	void setPoints(std::vector<cv::Point2f> points);
	static cv::Point2f center;
private:
	std::vector<cv::Point2f> points;
};
