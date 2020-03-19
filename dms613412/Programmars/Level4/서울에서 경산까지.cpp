#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int K, vector<vector<int>> travel) {
	int n = travel.size();
	vector<vector<int>> vec(n + 1, vector<int>(K + 1, 0));

	for (int i = 1; i <= n; ++i) {
		int t_walk = travel[i - 1][0], m_walk = travel[i - 1][1], t_bike = travel[i - 1][2], m_bike = travel[i - 1][3];
		for (int j = 0; j <= K; ++j) {
			int walk, bike;
			if (t_walk <= j && vec[i - 1][j - t_walk] != -1)
				walk = vec[i - 1][j - t_walk] + m_walk;
			else
				walk = -1;

			if (t_bike <= j && vec[i - 1][j - t_bike] != -1)
				bike = vec[i - 1][j - t_bike] + m_bike;
			else
				bike = -1;

			vec[i][j] = max(bike, walk);
		}

	}

	return vec[n][K];
}