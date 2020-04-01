#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;
long long X;

bool func(vector<int> x) {
	if (x[0] > X)return true;
	else return false;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<vector<int>> data) {
	sort(data.begin(), data.end());
	int answer = 0;
	for (int i = 0; i < data.size(); ++i) {
		int x = data[i][0], y = data[i][1];
		X = x;
		int j = find_if(data.begin() + i, data.end(), func) - data.begin();
		int x_index = data[j][0];
		long long tmp_min = 2200000000, tmp_max = -1, min_num = 2200000000, max_num = -1;
		for (; j < data.size(); ++j) {
			if (x_index < data[j][0]) {
				min_num = tmp_min;
				max_num = tmp_max;
				x_index = data[j][0];

			}
			long long tmp = data[j][1];
			if (y < tmp && min_num >= tmp) {
				++answer; tmp_min = min(tmp, tmp_min);
			}
			else if (y > tmp && max_num <= tmp) {
				++answer; tmp_max = max(tmp, tmp_max);
			}
			// cout<<tmp<<" "<<answer<<" "<<min_num<<" "<<max_num<<"  ";
		}
	}
	return answer;
}