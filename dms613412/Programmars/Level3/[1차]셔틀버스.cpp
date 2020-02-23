
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int TIME = 540;
bool func(int x) {
	return x > TIME;
}

string solution(int n, int t, int m, vector<string> timetable) {
	vector<int> time;
	for (auto &x : timetable) {
		int k = stoi(x.substr(0, 2)) * 60 + stoi(x.substr(3));
		time.push_back(k);
	}
	sort(time.begin(), time.end());
	string answer = "";
	int index = 0;
	for (int i = 0; i < n; ++i) {
		int tmp = find_if(index + time.begin(), time.end(), func) - time.begin();
		int tmp2 = index;
		if (tmp - index > m) {
			index += m;
			if (i == n - 1) {
				//cout<<index<<endl;
				TIME = time[index - 1] - 1;
				break;
			}
		}
		else {
			index = tmp;
		}

		if (i == n - 1) {
			if (index - tmp2 >= m)
				TIME = time[index - 1] - 1;
			break;
		}
		//cout<<index<< " "<<TIME<<endl;
		TIME += t;

	}

	int h = TIME / 60; int min = TIME % 60;
	if (h < 10)answer = "0";
	answer += to_string(h) + ":";

	if (min < 10)answer += "0";
	answer += to_string(min);


	return answer;
}