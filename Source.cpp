#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

bool withinTriangle(pair<int, int> p0, pair<int, int> p1,
	pair<int, int> p2, pair<int, int> test) {
	int point0[2] = { get<0>(p0), get<1>(p0) };
	int point1[2] = { get<0>(p1), get<1>(p1) };
	int point2[2] = { get<0>(p2), get<1>(p2) };
	int testPoint[2] = { get<0>(test), get<1>(test) };
	double a, b, c;
	int x0 = point0[0], x1 = point1[0] - point0[0], x2 = point2[0] - point0[0], xp = testPoint[0] - point0[0];
	int y0 = point0[1], y1 = point1[1] - point0[1], y2 = point2[1] - point0[1], yp = testPoint[1] - point0[1];
	float d = x1 * y2 - x2 * y1;
	a = (xp * (y1 - y2) + yp * (x2 - x1) + x1 * y2 - x2 * y1) / d;
	b = (xp * y2 - yp * x2) / d;
	c = (yp * x1 - xp * y1) / d;

	if (a > 0 && b > 0 && c > 0 && a < 1 && b < 1 && c < 1)
		return true;
	else
		return false;
}

int main()
{
	cout << withinTriangle(pair<int, int>(1, 4), pair<int, int>(5, 6), pair<int, int>(6, 1), pair<int, int>(4, 5));
}