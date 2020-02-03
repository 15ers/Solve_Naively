#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return  a.second < b.second;
	}
};

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	for (int i = 0; i < supplies.size(); ++i) {
		pq.push({ i,supplies[i] });
	}

	queue<pair<int, int>> tmp;
	pair<int, int> x;
	while (stock < k) {
		while (!tmp.empty()) {
			pq.push(tmp.front());
			tmp.pop();
		}
		while (1) {
			x = pq.top(); pq.pop();
			if (stock < dates[x.first]) {
				tmp.push(x);
				continue;
			}
			stock += x.second;
			++answer;
			break;
		}
	}
	return answer;
}