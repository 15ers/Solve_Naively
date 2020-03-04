//1:45
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> food_times, long long k) {

	vector<int> vec = food_times;
	sort(vec.begin(), vec.end());
	long long total_time = 0, sum = 0;

	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] <= sum)continue;
		long long tmp_time = (vec.size() - i)*(vec[i] - sum);

		if (total_time + tmp_time == k) {
			k = 0;
			total_time += tmp_time;
			sum = vec[i];

			break;
		}
		else if (total_time + tmp_time > k) {
			tmp_time = ((k - total_time) / (vec.size() - i))*(vec.size() - i);
			sum += (k - total_time) / (vec.size() - i);
			total_time += tmp_time;
			k -= total_time;
			break;
		}
		else {
			total_time += tmp_time;
			sum += vec[i] - sum;
		}
	}

	int index = 0;

	for (int i = 0; i < food_times.size(); ++i) {
		if (food_times[i] <= sum)continue;
		if (index == k)return i + 1;
		++index;
	}

	return -1;
}