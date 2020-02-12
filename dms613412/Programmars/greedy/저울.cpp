#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
동일 i 기준, 누적합[i]+1가 원배열[i+1] 이상이어야 하며, 미만이되면 그 때의 누적합[i]+1부터 만들 수 없는 수.
모두 비교하고도 통과 되었다면, 마지막 수인 50+1=51이 만들 수 없는 수.(모든 수들의 합+1)
*/

int solution(vector<int> weight) {
	sort(weight.begin(), weight.end());
	int size = weight.size();
	vector<int> vec;
	vec.push_back(weight[0]);
	for (int i = 1; i < size; ++i) {
		if (vec[i - 1] + 1 < weight[i])return vec[i - 1] + 1;
		vec.push_back(weight[i] + vec[i - 1]);
	}

	return vec[size - 1] + 1;
}