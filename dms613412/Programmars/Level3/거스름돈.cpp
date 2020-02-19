#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> money) {
	int size = money.size();
	vector<int> vec(n + 1, 0);
	for (int i = 0; i <= n; ++i)
		if (i%money[0] == 0)vec[i] = 1;

	for (int i = 1; i < size; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j >= money[i])
				vec[j] += vec[j - money[i]];
		}
	}

	return vec[n];
}