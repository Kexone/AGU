#include "vizualize.h"
#include <opencv2/videostab/ring_buffer.hpp>

void Vizualize::setPoly(Polygon & poly)
{
	this->p = poly;
}

void Vizualize::drawPoly(cv::Mat & dst)
{
	std::vector<cv::Point2f> points = p.getPoints();
	for (int i = 0; i < points.size(); i++)
	{
		if (i != points.size() - 1)
			cv::line(dst, points[i], points[i + 1], cv::Scalar(0, 0, 0), 2);
		cv::circle(dst, (points[i]), 2, cv::Scalar(0, 0, 255), 1);
	}
	cv::line(dst, points[0], points[points.size() - 1], cv::Scalar(0, 0, 0), 2);
}

void Vizualize::drawPoints(cv::Mat& dst, std::vector<cv::Point2f>& points)
{
	for (int i = 0; i < points.size(); i++)
	{
		cv::circle(dst, points[i], 2, cv::Scalar(255, 0, 255), 4);
	}
}
void Vizualize::drawPoint(cv::Mat& dst, cv::Point2f point)
{
	cv::circle(dst, point, 2, cv::Scalar(255, 0, 0), 5);

}


void Vizualize::drawArrowedLine(cv::Mat& dst, cv::Point2f from, cv::Point2f to)
{
	cv::arrowedLine(dst, from, to, cv::Scalar::all(1.0), 1);
}

void Vizualize::drawLine(cv::Mat& dst, cv::Point2f from, cv::Point2f to)
{
	cv::line(dst, from, to, cv::Scalar(215, 0, 225), 2);
}

