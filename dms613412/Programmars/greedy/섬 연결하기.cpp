#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;
int visited[100] = { 0, };

int solution(int n, vector<vector<int>> costs) {
	int answer = 0, num = 0;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	for (auto &x : costs) {
		graph[x[0]][x[1]] = x[2];
		graph[x[1]][x[0]] = x[2];
	}
	unordered_set<int>vec;
	vec.insert(0);
	visited[0] = 1;
	while (num++ < n - 1) {
		int xtmp, jtmp, tmp = 100000;
		for (auto &x : vec) {

			for (int j = 0; j < n; ++j) {
				if (!graph[x][j])continue;
				if (visited[j])continue;
				if (tmp > graph[x][j]) {
					tmp = graph[x][j];
					jtmp = j;
					xtmp = x;
				}
			}
		}
		vec.insert(jtmp);
		answer += tmp;
		visited[jtmp] = 1;
	}

	return answer;
}