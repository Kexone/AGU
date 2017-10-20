#include "planeSweeping.h"
#include <opencv2/highgui.hpp>

void PlaneSweeping::run()
{
	int countLines = 10;
	std::set<myPoint> all = std::set<myPoint>(0,10);
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
		myPoint p = myPoint{ pointB, "END" };
		all.insert(myPoint{ pointB, "END" });
		viz.drawLine(img, pointA, pointB);
	}
	cv::imshow("Plane Sweeping", img);
	cv::waitKey(0);
	allPoints.size();
	
}
