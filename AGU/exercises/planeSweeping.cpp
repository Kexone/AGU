#include "planeSweeping.h"
#include <opencv2/highgui.hpp>

void PlaneSweeping::run()
{
	int countLines = 10;
	cv::Mat img(400, 1000, CV_8UC3);
	Vizualize viz = Vizualize();
	for(int i = 0; i < countLines; i++)
	{
		cv::Point2f pointA = Generator::generatePoint();
generateAgainB:
		cv::Point2f pointB = Generator::generatePoint();
		if(pointA.y < pointB.y)
		{
			goto generateAgainB;
		}
		//const myPoint p = myPoint{ pointB, "END" };
		//allPoints.insert(p);
		viz.drawLine(img, pointA, pointB);
	}
	cv::imshow("Plane Sweeping", img);
	cv::waitKey(0);
	allPoints.size();
	
}
