#include "landingInterval.h"
#include "../objects/polygon.h"
#include "../vizualize.h"
#include <opencv2/highgui.hpp>
#include <iostream>
#include "../generator.h"
void printPoints(std::vector<cv::Point2f> p)
{
	std::cout << "_Body:" << std::endl;
	for (int i = 0; i <  p.size();i++)
	{
		std::cout << i << " " <<  p[i].x << " " << p[i].y << std::endl;
	}
}
void LandingInterval::run()
{
	bool k;
	cv::Mat src(640, 800, CV_8UC3);
	src.copyTo(image);
	Polygon::center = cv::Point2f(image.cols / 2, image.rows / 2);
	poly = Polygon();
	poly.setPoints(Generator::generatePolygon(20));
	Generator::generatePoints(points, 50);
	viz = Vizualize();
	viz.setPoly(poly);
	viz.drawPoly(image);
	viz.drawPoints(image, points);
	cv::imshow("Polygon", image);
	findPoints();
	std::cout << "Done";
	k = cv::waitKey(0);
}

void LandingInterval::findPoints()
{
	cv::Mat dup(image.clone());
	cv::Mat duplicate(image.clone());
	for (int i = 0; i < points.size(); i++)
	{
		std::vector<cv::Point2f> polyPoints = poly.getPoints();
		printPoints(polyPoints);
		locatePoint(duplicate, polyPoints, polyPoints[0], points[i]);
		dup.copyTo(duplicate);
	}

}

int LandingInterval::locationOfPoint(cv::Point2f p1, cv::Point2f p2, cv::Point2f p3)
{
	int val = (p2.y - p1.y) * (p3.x - p2.x) -
		(p2.x - p1.x) * (p3.y - p2.y);

	if (val == 0) return 0;  // colinear

	return (val > 0) ? 1 : 2;
}

void LandingInterval::locatePoint(cv::Mat &duplicate, std::vector<cv::Point2f> &polyP, cv::Point2f firstP, cv::Point2f point)
{
	int rlSide;
	int pLen = polyP.size();
	if (pLen < 3)
	{
		viz.drawLine(duplicate, firstP, polyP[pLen / 2]);
		rlSide = locationOfPoint(polyP[0], polyP[1], point);
		if (isInTriangle(point, firstP, polyP[0], polyP[1]))
		{
			viz.drawPoint(image, point);
		}
		cv::waitKey(10);
		cv::imshow("Computating", duplicate);
		cv::imshow("Polygon", image);
		return;
	}
	int iHalf = pLen / 2;
	viz.drawLine(duplicate, firstP, polyP[iHalf]);
	cv::waitKey(10);
	cv::imshow("Computating", duplicate);
	rlSide = locationOfPoint(firstP, polyP[iHalf], point);

	std::vector<cv::Point2f> newPoints;

	if (rlSide == 1) //left
	{
		std::cout << ">>LEFT" << std::endl;
		newPoints = std::vector<cv::Point2f>(polyP.begin(), polyP.begin() + iHalf + 1 );
	}
	else if (rlSide == 2) //right
	{
		std::cout << "<<RIGHT" << std::endl;
		newPoints = std::vector<cv::Point2f>(polyP.begin() + iHalf, polyP.end());
	}
	locatePoint(duplicate, newPoints, firstP, point);
}

float LandingInterval::sign(cv::Point2f p1, cv::Point2f p2, cv::Point2f p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool LandingInterval::isInTriangle(cv::Point2f pt, cv::Point2f v1, cv::Point2f v2, cv::Point2f v3)
{
	bool b1, b2, b3;

	b1 = sign(pt, v1, v2) < 0.0f;
	b2 = sign(pt, v2, v3) < 0.0f;
	b3 = sign(pt, v3, v1) < 0.0f;
	std::cout << b1 << "==" << b2 << " && " << b2 << "==" << b3 << std::endl;
	return ((b1 == b2) && (b2 == b3));
}