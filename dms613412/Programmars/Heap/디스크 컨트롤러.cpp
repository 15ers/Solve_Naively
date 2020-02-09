#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return  a.second > b.second;
	}
};


int solution(vector<vector<int>> jobs) {
	int index = 0, time = 0, sum = 0, num = 0;
	int size = jobs.size();
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
	sort(jobs.begin(), jobs.end());
	while (num < size) {
		for (int i = index; i < size; ++i) {
			if (jobs[i][0] > time) {
				index = i;
				break;
			}
			pq.push({ jobs[i][0],jobs[i][1] });
			if (i == size - 1)index = size;
		}

		if (pq.empty()) {
			++time;
		}
		else {
			pair<int, int> cur = pq.top(); pq.pop();
			time += cur.second;
			sum += (time - cur.first);
			++num;
			// cout<<sum<<" "<<num<<" "<<time<<" "<<cur.second<<endl;
		}

	}

	return sum / num;
}