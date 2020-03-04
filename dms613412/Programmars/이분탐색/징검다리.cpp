#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
	int answer = 0;
	int left = 0, right = distance, mid;
	sort(rocks.begin(), rocks.end());
	int prev = 0, num = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		//cout<<left<<" "<<mid<<" "<<right<<endl;
		prev = 0; num = 0;
		for (int x : rocks) {
			if (x - prev < mid)++num;
			else prev = x;
		}
		if (distance - prev < mid)++num;
		//cout<<num<<endl;
		if (num <= n) {
			left = mid + 1;
			answer = mid;
		}
		else right = mid - 1;

	}
	return answer;
}