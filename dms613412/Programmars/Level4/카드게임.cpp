
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int X = 0;
vector<pair<int, int>> vec(100000000, { 0,0 });//9X

bool func(int b) {
	return b > X;
}

int solution(vector<int> left, vector<int> right) {
	int c = 1;
	vec[0] = { 0,0 };
	for (int x : right) {
		int C = c;
		for (int i = 0; i < C; ++i) {
			int &index = vec[i].first; int& answer = vec[i].second;
			if (index >= left.size())continue;
			if (x < left[index])answer += x;
			else {

				X = x;
				int tmp = find_if(left.begin() + index, left.end(), func) - left.begin();
				X = left[tmp] - 1;
				auto tmp2 = find_if(left.begin() + tmp + 1, left.end(), func);

				if (tmp < left.size()) {
					int t = answer + x;
					if (tmp2 == left.end()) {
						++index;
						vec[c] = { tmp,t };
						++c;
					}
					else {
						index = tmp; answer = t;
					}

				}
				else {
					++index;
				}

			}

		}
	}
	int answer = 0;
	for (int i = 0; i < c; ++i) {
		answer = max(answer, vec[i].second);
	}

	return answer;
}

