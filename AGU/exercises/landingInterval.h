#pragma once
#include "exercises.h"
#include <opencv2/core/mat.hpp>
#include "../objects/polygon.h"
#include "../vizualize.h"

class LandingInterval : public Exercise
{
public:
	void run() override;
private:
	cv::Mat image;
	std::vector<cv::Point2f> points;
	//std::vector<cv::Point2f> goodPoints;
	Polygon poly;
	Vizualize viz;
	void findPoints();
	int locationOfPoint(cv::Point2f p1, cv::Point2f p2, cv::Point2f p3);
	void locatePoint(cv::Mat &duplicate, std::vector<cv::Point2f> polyP, cv::Point2f firstP, cv::Point2f point);
	void splitPoly(std::vector<cv::Point2f> &polyP, int from, int to);
};
