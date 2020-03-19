

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> cores) {
	int size = cores.size();
	if (size >= n) { return n; }

	int start = 0, end = n * (*max_element(cores.begin(), cores.end())), mid;
	int time = 0;
	while (start <= end) {
		int sum = 0;
		mid = (start + end) / 2;
		for (auto x : cores) {
			sum += (mid / x);
		}

		if (sum >= n - size) {
			if (sum == n - size)time = mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}
	//cout<<time<<" "<<start<<" "<<end<<endl;
	n -= size;
	if (time == 0)time = start;
	if (time != 0) {
		for (auto x : cores) {
			n -= ((time - 1) / x);
		}
	}
	//cout<<n<<" "<<time<<endl;
	int index = 0;
	for (int i = 0; i < size; ++i) {
		if (time%cores[i] == 0)
			++index;
		if (index == n)return(i + 1);
	}

	return -1;
}