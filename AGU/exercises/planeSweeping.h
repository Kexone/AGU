#pragma once
#include "exercises.h"
#include <set>
#include <opencv2/core/mat.hpp>
#include "../collection/point.h"
#include "../generator.h"
#include "../vizualize.h"

class PlaneSweeping : public Exercise
{
public:
	void run() override;

private:
	std::set<myPoint> allPoints;
	std::set<myPoint> queue;
};
