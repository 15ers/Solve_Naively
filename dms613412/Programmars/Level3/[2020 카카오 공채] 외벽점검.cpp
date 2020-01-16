#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int work[8];
int cover[15];
int answer = 9, wn, dn;

int dfs(int people, vector<int> weak, vector<int> dist) {
	bool isSuccess = true;
	for (int i = 0; i < wn; ++i) {
		if (cover[i] == 0) { isSuccess = false; break; }
	}

	if (isSuccess && people <= dn && people > 0) { return answer = min(answer, people); }
	if (!isSuccess && people > 8) { return -1; }

	for (int i = 0; i < dn; ++i) {
		if (work[i] == 0) {
			int tmp[15];
			for (int j = 0; j < 15; ++j) { tmp[j] = cover[j]; }
			for (int j = 0; j < wn; ++j) {
				if (cover[j] == 0) {
					int t = 0;
					while (j + t < wn && weak[j + t] - weak[j] <= dist[i]) {
						cover[j + t] = 1;
						++t;
					}
					break;
				}
			}
			work[i] = 1;
			dfs(people + 1, weak, dist);
			work[i] = 0;
			for (int j = 0; j < 15; ++j) { cover[j] = tmp[j]; }
		}
	}
	return answer;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	wn = weak.size();
	dn = dist.size();
	for (int i = 0; i < wn; ++i) {
		dfs(0, weak, dist);
		int start = weak[0] + n;
		for (int j = 0; j < wn - 1; ++j) {
			weak[j] = weak[j + 1];
		}
		weak[wn - 1] = start;
	}
	if (answer == 9)return -1;
	return answer;


}