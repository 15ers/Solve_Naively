#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;
	deque<int> dq;
	bool isupdate = false;

	for (auto &x : operations) {
		if (x[0] == 'D') {
			if (dq.empty())continue;
			if (isupdate)sort(dq.begin(), dq.end());
			if (x[2] == '1') { dq.pop_back(); }
			else { dq.pop_front(); }
			isupdate = false;
		}
		else {
			//sum = stoi(x.substr(2));
			isupdate = true;
			bool minus = false;
			int sum = 0;
			for (int i = 2; i < x.size(); ++i) {
				if (x[i] == '-') { minus = true; continue; }
				sum = 10 * sum + (x[i] - '0');
			}
			if (minus)dq.push_back(-sum);
			else dq.push_back(sum);
		}
	}
	sort(dq.begin(), dq.end());
	if (dq.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(dq.back());
		if (dq.size() == 1)return answer;
		answer.push_back(dq.front());
	}
	return answer;
}