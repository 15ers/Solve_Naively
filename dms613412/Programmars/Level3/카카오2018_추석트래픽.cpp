#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

struct TRAFFIC {
	int start;
	int end;
};

int solution(vector<string> lines) {
	vector<TRAFFIC> traffic;

	for (auto &x : lines) {
		int end = stoi(x.substr(11, 2)) * 3600000 + stoi(x.substr(14, 2)) * 60000 + stof(x.substr(17, 6)) * 1000;
		int start = end - stof(x.substr(24, x.size() - 25)) * 1000 + 1;
		traffic.push_back({ start,end });
	}
	int answer = 0;
	for (auto &x : traffic) {
		int tmp = 0;
		for (auto &y : traffic) {
			if (x.start - 999 <= y.start && y.start <= x.start) ++tmp;
			else if (x.start - 999 <= y.end && y.end <= x.start) ++tmp;
			else if (y.start<x.start - 999 && y.end>x.start)++tmp;
		}
		answer = max(tmp, answer);
	}


	return answer;
}