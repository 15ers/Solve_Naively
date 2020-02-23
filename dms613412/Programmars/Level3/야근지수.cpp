#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> works) {
	sort(works.begin(), works.end());
	int size = works.size();

	while (n > 0) {
		auto m = max_element(works.begin(), works.end());
		int max_index = m - works.begin();
		if (max_index > 0) {
			int second = works[max_index - 1];
			if ((*m - second)*(size - max_index) <= n) {
				n -= (*m - second)*(size - max_index);
				int max_tmp = *m;
				replace(m, works.end(), works[size - 1], second);
			}
			else {
				int div = n / (size - max_index);
				int raq = n % (size - max_index);
				int tmp = *m - div;
				int max_tmp = *m;
				replace(m, works.end(), works[size - 1], tmp);
				n -= div * n;
				for (int i = 0; i < raq; ++i) {
					--works[max_index + i];
				}
				break;
			}
		}
		else {
			int div = n / size;
			int raq = n % size;
			int tmp = works[0] - div;
			if (tmp <= 0) {
				return 0;
			}
			replace(works.begin(), works.end(), works[size - 1], tmp);

			n -= div * n;
			for (int i = 0; i < raq; ++i) {
				--works[i];
			}

			break;
		}


	}
	long long answer = 0;
	for (auto &x : works) {
		answer += x * x;
	}


	return answer;
}