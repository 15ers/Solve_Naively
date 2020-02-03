#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue< long long, vector<long long>, greater<long long> > pq;
	//pq.assign( scoville.begin(), scoville.end() );
	for (int i = 0; i < scoville.size(); ++i) {
		pq.push(scoville[i]);
	}

	long long a, b, c;

	while (!pq.empty()) {
		a = pq.top(); pq.pop();
		if (a >= K)break;
		if (pq.size() < 1)return -1;
		b = pq.top(); pq.pop();
		c = a + 2 * b;
		pq.push(c);
		++answer;
	}
	return answer;
}