#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int graph[20000][20000] = { 0, };
int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	//vector<vector<int> > graph(0,vector<int>(n,0));
	vector<int> arr(n, 0);

	for (auto &y : edge) {
		graph[y[0] - 1][y[1] - 1] = 1;
		graph[y[1] - 1][y[0] - 1] = 1;
	}

	queue<int> index;
	index.push(0);
	int max_ = 0;
	while (!index.empty()) {
		int cur = index.front(); index.pop();
		for (int i = 1; i < n; ++i) {
			if (arr[i] == 0 && graph[cur][i] == 1) {
				arr[i] = arr[cur] + 1;
				index.push(i);
				max_ = max(max_, arr[i]);
			}
		}
	}

	for (auto &y : arr) {
		if (y == max_)++answer;
	}

	return answer;
}