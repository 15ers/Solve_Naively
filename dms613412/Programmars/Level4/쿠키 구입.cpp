#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool func(pair<int, int>a, pair<int, int>b) {
	return a.second >= b.second;
}

int solution(vector<int> cookie) {
	int answer = 0;
	int size = cookie.size();
	vector<int> vec(size, cookie[0]);
	for (int i = 1; i < size; ++i)
		vec[i] = vec[i - 1] + cookie[i];

	for (int i = 0; i < vec.size(); ++i) {
		int m = vec[i];
		for (int j = i + 1; j < size; ++j) {
			int r = vec[j] - m;
			if (r == m) {
				answer = max(answer, r);
				break;
			}
			if (answer >= r || r > m) continue;
			for (int l = 0; l < i; ++l) {
				if (r == m - vec[l]) {
					answer = max(answer, r);
					break;
				}
			}
		}
	}
	return answer;
}