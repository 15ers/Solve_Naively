#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<long long>> map(n, vector<long long>(m, -1));

	for (int i = 0; i < puddles.size(); ++i) {
		map[puddles[i][1] - 1][puddles[i][0] - 1] = 0;
	}

	int num = 1;
	for (int i = 0; i < m; ++i) {
		if (map[0][i] == 0) {
			num = 0;
		}
		map[0][i] = num;
	}

	num = 1;
	for (int i = 0; i < n; ++i) {
		if (map[i][0] == 0) {
			num = 0;
		}
		map[i][0] = num;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (map[i][j] == 0)continue;
			map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
		}
	}

	return map[n - 1][m - 1];
}