#include "landingInterval.h"
#include "../objects/polygon.h"
#include "../vizualize.h"
#include <opencv2/highgui.hpp>
#include <iostream>
#include "../generator.h"

void LandingInterval::run()
{
	bool k;
	cv::Mat src(640, 800, CV_8UC3);
	src.copyTo(image);
	Polygon::center = cv::Point2f(image.cols / 2, image.rows / 2);
	poly = Polygon();
	poly.setPoints(Generator::generatePolygon(20));
	Generator::generatePoints(points, 3);
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
	for(int i = 0; i < points.size(); i++)
	{
		std::vector<cv::Point2f> polyPoints = poly.getPoints();
		locatePoint(duplicate, polyPoints, polyPoints[0],points[i]);
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

void LandingInterval::locatePoint(cv::Mat &duplicate, std::vector<cv::Point2f> polyP, cv::Point2f firstP, cv::Point2f point)
{
	bool k;
	int pLen = polyP.size() / 2;
	viz.drawLine(duplicate, firstP, polyP[ pLen ]);
	cv::waitKey(10);
	cv::imshow("Computating", duplicate);
	cv::waitKey(10);
	int rlSide = locationOfPoint(firstP, polyP[ pLen ], point);
	if(rlSide == 1) //left
	{
		splitPoly(polyP, 0, pLen );
	}
	else if(rlSide == 2) //right
	{
		splitPoly(polyP, pLen , pLen * 2);
	}
	else //on line
	{
		
	}
	//std::cout << " SIZE:   " << pLen << std::endl;
//	k = cv::waitKey(0);
	if(pLen <= 2)
	{
		viz.drawLine(duplicate, firstP, polyP[pLen -1 ]);
		viz.drawArrowedLine(duplicate, polyP[0], polyP[1]);
		//rlSide = locationOfPoint(polyP[0], polyP[1], point);
		rlSide = locationOfPoint(polyP[0], polyP[1],point);
		
		if(rlSide == 2)
		{
			viz.drawPoint(image, point);
		}
		cv::waitKey(10);
		cv::imshow("Computating", duplicate);
		cv::imshow("Polygon", image);
		bool k = cv::waitKey(0);
		return;
	}
	locatePoint(duplicate, polyP, firstP, point);
}

void LandingInterval::splitPoly(std::vector<cv::Point2f>& polyP, int from, int to)
{
	std::vector<cv::Point2f> temp;
	for (int i = from; i < to; i++)
	{
		temp.emplace_back(polyP[i]);
	}
	polyP = temp;
	temp.clear();
}
