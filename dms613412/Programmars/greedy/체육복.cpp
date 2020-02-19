#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 31, count = 0;
	vector<int> vec(n, 1); vector<int> vec_tmp;
	for (auto &x : reserve) vec[x - 1]++;
	for (auto &y : lost)vec[y - 1]--;
	int lsize = lost.size();
	int index = 0;
	for (int k = 0; k < 50; ++k) {
		vec_tmp = vec;
		count = 0;
		for (int i = index; i < index + lsize; ++i) {
			int tmpi = i % lsize;
			if (!vec[lost[tmpi] - 1]) {
				if (vec[lost[tmpi]] == 2) {
					--vec[lost[tmpi]];
					++vec[lost[tmpi] - 1];
				}
				else if (vec[lost[tmpi] - 2] == 2) {
					--vec[lost[tmpi] - 2];
					++vec[lost[tmpi] - 1];
				}
				else {
					++count;
				}
			}
		}
		answer = min(count, answer);
		vec = vec_tmp;
		++index;
	}


	return n - answer;
}