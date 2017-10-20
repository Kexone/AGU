#pragma once
#include "polygon.h"


namespace cv {
	class Mat;
}

class Vizualize
{
public:
	void setPoly(Polygon &poly);
	void drawPoly(cv::Mat &dst);
	void drawPoints(cv::Mat &dst, std::vector<cv::Point2f> &points);
	void drawPoint(cv::Mat &dst, cv::Point2f point);
	void drawArrowedLine(cv::Mat &dst, cv::Point2f from, cv::Point2f to);
	void drawLine(cv::Mat &dst, cv::Point2f from, cv::Point2f to);

private:
	Polygon p;
};
