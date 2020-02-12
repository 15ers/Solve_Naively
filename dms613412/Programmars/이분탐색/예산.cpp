#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> budgets, int M) {
	sort(budgets.begin(), budgets.end());
	int size = budgets.size();
	int left = 0, right = size - 1, mid = (left + right) / 2;
	long long sum;

	while (left <= right) {
		sum = 0;
		for (int i = 0; i < mid; ++i)
			sum += budgets[i];

		if (sum + budgets[mid] * (size - mid) < M) {
			if (mid == size - 1)return budgets[mid];
			left = mid + 1; mid = (left + right) / 2;
		}
		else if (sum + budgets[mid] * (size - mid) == M) {
			return budgets[mid];
		}
		else {
			if (mid == 0)return M / size;
			long long tmp = (M - sum) / (size - mid);
			if (tmp >= budgets[mid - 1]) return tmp;
			right = mid - 1; mid = (left + right) / 2;
		}
	}

	int answer = 0;
	return answer;
}