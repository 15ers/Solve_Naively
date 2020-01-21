#include <string>
#include <vector>

using namespace std;

int visited[200] = { 0, };

void dfs(int start, int n, vector<vector<int>> &computers) {
	visited[start] = 1;
	for (int i = 0; i < n; ++i) {
		if (!visited[i] && computers[start][i] == 1)
			dfs(i, n, computers);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; ++i) {
		if (visited[i] == 0)
		{
			++answer;
			dfs(i, n, computers);
		}
	}
	return answer;
}