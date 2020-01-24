#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int h = triangle.size();
	vector<vector<int>> dptable(h, vector<int>(h, 0));
	dptable[0][0] = triangle[0][0];
	for (int i = 0; i < h - 1; ++i) {
		for (int j = 0; j < i + 1; ++j) {
			int tmp = triangle[i + 1][j] + dptable[i][j];
			dptable[i + 1][j] = max(tmp, dptable[i + 1][j]);
			tmp = triangle[i + 1][j + 1] + dptable[i][j];
			dptable[i + 1][j + 1] = max(tmp, dptable[i + 1][j + 1]);
		}
	}


	return  *max_element(dptable[h - 1].begin(), dptable[h - 1].end());
}