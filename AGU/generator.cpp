#include <cassert>
#include <iostream>
#include "generator.h"
#include "utils.h"


// Generator engines
std::random_device Generator::rd;
std::mt19937 Generator::gen = std::mt19937(rd());
std::uniform_real_distribution<float> Generator::dis = std::uniform_real_distribution<float>(0.0f, 1.0f);

void Generator::generatePoints(std::vector<cv::Point2f> &points, size_t count) {
	assert(count > 0);
	points.reserve(count);
	cv::Point2f center = Polygon::center;
	// Generate points
	for (size_t i = 0; i < count; i++) {
		points.emplace_back(cv::Point2f(2 * center.x * dis(gen),2 * center.y * dis(gen)));
	}
}

std::vector<cv::Point2f> Generator::generatePolygon(size_t count) {

	// Draw points around circle
	std::vector<cv::Point2f> p;
	cv::Point2f center = Polygon::center;
	float radius = 180.0f, step = 360.0f / count;

	for (float angle = 0; angle < 360.0f; angle += step) {
		p.emplace_back(cv::Point2f(
			static_cast<float>(center.x + radius * std::cos(Utils::rad(angle))),
			static_cast<float>(center.y + radius * std::sin(Utils::rad(angle)))
		));
	}

	return p;
}