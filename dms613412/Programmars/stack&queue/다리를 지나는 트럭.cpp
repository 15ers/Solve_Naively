#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct TRUCK {
	int weight, time;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int time = 1, w = 0;
	queue<TRUCK> before, after, ing;
	for (auto &x : truck_weights) before.push({ x,0 });
	ing.push({ truck_weights[0],1 });
	w = truck_weights[0]; before.pop();
	while (after.size() < truck_weights.size()) {
		++time;
		if ((time - ing.front().time) == bridge_length) {
			w -= ing.front().weight;
			after.push(ing.front());
			ing.pop();
		}
		if (before.size() != 0) {
			int cur = before.front().weight;
			if (cur + w > weight) {
				continue;
			}
			ing.push({ cur,time });
			w += cur;
			before.pop();
		}
	}

	return time;
}