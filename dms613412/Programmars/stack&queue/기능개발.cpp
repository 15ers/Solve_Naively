#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	int m, n, i = 0, max_day = 0;

	for (auto &x : progresses) {
		n = 100 - x;
		m = n / speeds[i];
		if (n%speeds[i])++m;
		if (m <= max_day) {
			++answer[answer.size() - 1];
		}
		else {
			answer.push_back(1);
			max_day = m;
		}
		++i;
	}


	return answer;
}