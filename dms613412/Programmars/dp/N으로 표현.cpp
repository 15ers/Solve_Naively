#include <string>
#include <vector>
#include <unordered_set>
#include <math.h>

using namespace std;

int solution(int N, int number) {
	int answer = -1;
	unordered_set<int> table[9];
	int tmp = 0;
	for (int i = 0; i < 9; ++i) {
		tmp += N * pow(10, i);
		table[i].insert(tmp);
	}

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < i; ++j) {
			for (auto &a : table[j]) {
				for (auto &b : table[i - j - 1]) {
					//i+1개의 n을 이용한 값을 만들기 위해 n을 j+1개 사용한 값과 n을 i-j개 사용한 값을 연산하여 n이 i+1개 사용된 값의 배열에 저장
					table[i].insert(a + b);
					table[i].insert(a - b);
					table[i].insert(a*b);
					if (b != 0)table[i].insert(a / b);

					if (table[i].count(number) > 0)return i + 1;

				}
			}
		}
	}

	return answer;
}