#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct CAMERA {
	int start;
	int end;
};

int solution(vector<vector<int>> routes) {
	int answer = 60000;
	int s = 0;
	sort(routes.begin(), routes.end());
	vector<CAMERA> vec;
	vec.push_back({ -30000,30000 });
	for (auto &x : routes) {
		bool in = false;
		for (auto &y : vec) {
			if (y.start <= x[0] && x[1] <= y.end) {
				y.end = x[1]; y.start = x[0];
				in = true;
				break;
			}
			else if (x[0] < y.start && y.end >= x[1] && y.start <= x[1]) {
				y.end = x[1];
				in = true;
				break;
			}
			else if (x[1] > y.end && y.end >= x[0] && y.start <= x[0]) {
				y.start = x[0];
				in = true;
				break;
			}
			else if (x[1] >= y.end && x[0] <= y.start) {
				in = true;
				break;
			}
		}
		if (!in) {
			vec.push_back({ x[0],x[1] });
		}
	}

	return vec.size();
}

