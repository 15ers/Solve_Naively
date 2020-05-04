#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

int dp[101][101][2];

int func(int start, int end, vector<string> &arr) {
	if (start == end)
		return dp[start][end][1] = stoi(arr[2 * start]);

	int sum1 = INT_MIN, sum2 = INT_MAX;
	for (int i = start; i < end; ++i) {
		int tmp1, tmp2;
		int &left_max = dp[start][i][0];
		int &right_max = dp[i + 1][end][0];
		if (left_max == 0) left_max = func(start, i, arr);
		if (right_max == 0) right_max = func(i + 1, end, arr);
		int right_min = dp[i + 1][end][1], left_min = dp[start][i][1];

		if (arr[2 * i + 1] == "-") {
			tmp1 = left_max - right_min;
			tmp2 = left_min - right_max;
		}
		else {
			tmp1 = left_max + right_max;
			tmp2 = left_min + right_min;
		}
		sum1 = max(sum1, tmp1);
		sum2 = min(sum2, tmp2);
	}
	//cout << sum1<< " "<<sum2<<endl;
	dp[start][end][1] = min(sum1, sum2); // 최소
	return dp[start][end][0] = max(sum1, sum2); // 최대

}

int solution(vector<string> arr) {
	return func(0, arr.size() / 2, arr);
}