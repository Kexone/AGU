#pragma once
class Utils {
public:
	template <typename T>
	static T sqr(T x) { return x * x; }

	static float radf(float x);
	static double rad(double x);

	static float degf(float x);
	static double deg(double x);
};
