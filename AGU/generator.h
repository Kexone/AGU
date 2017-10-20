#pragma once
#include <opencv2/core/types.hpp>
#include <random>
#include "objects/polygon.h"

class Generator {
private:
	static std::random_device rd;
	static std::mt19937 gen;
	static std::uniform_real_distribution<float> dis;
public:
	static void generatePoints(std::vector<cv::Point2f> &points, size_t count = 100);
	static cv::Point2f generatePoint(size_t count = 1);

	static std::vector<cv::Point2f> generatePolygon(size_t count = 100);
};
