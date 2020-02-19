#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;
	int a = s / n;
	int size = n;
	if (a == 0) {
		answer.push_back(-1);
		return answer;
	}
	for (int i = 0; i < size; ++i) {
		if (s%n == 0) {
			answer.resize(size, s / n);
			break;
		}
		a = s / n--;
		answer.push_back(a);
		s -= a;
	}

	if (answer.empty())answer.push_back(-1);
	return answer;
}