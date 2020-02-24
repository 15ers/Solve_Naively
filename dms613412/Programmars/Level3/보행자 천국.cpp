#include <vector>

using namespace std;

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	if (city_map[0][0] == 1)return 0;
	vector<vector<pair<int, int>>> vec(m, vector<pair<int, int>>(n, { 0,0 }));
	vec[0][0] = { 1,1 };
	for (int i = 1; i < m; ++i) {
		if (city_map[i][0] == 1)break;
		vec[i][0].second = 1;
	}
	for (int i = 1; i < n; ++i) {
		if (city_map[0][i] == 1)break;
		vec[0][i].first = 1;
	}

	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			if (city_map[i][j] == 1)continue;
			if (city_map[i - 1][j] == 0) {
				vec[i][j].second = (vec[i - 1][j].first + vec[i - 1][j].second) % 20170805;
			}
			else if (city_map[i - 1][j] == 2) {
				vec[i][j].second = vec[i - 1][j].second % 20170805;
			}

			if (city_map[i][j - 1] == 0) {
				vec[i][j].first = (vec[i][j - 1].first + vec[i][j - 1].second) % 20170805;
			}
			else if (city_map[i][j - 1] == 2) {
				vec[i][j].first = vec[i][j - 1].first % 20170805;
			}
		}
	}


	return (vec[m - 1][n - 1].first + vec[m - 1][n - 1].second) % 20170805;
}