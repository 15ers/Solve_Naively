#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer, tmp;
	answer.push_back(0);

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < answer.size(); ++j) {
			tmp.push_back(answer[j]);
		}
		tmp.push_back(0);
		for (int j = 0; j < answer.size(); ++j) {
			if (j == answer.size() / 2) { tmp.push_back(1); continue; }
			tmp.push_back(answer[j]);
		}
		answer = tmp;
		tmp.clear();
	}

	return answer;
}