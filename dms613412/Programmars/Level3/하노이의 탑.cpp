#include <string>
#include <vector>

using namespace std;
vector<vector<int>> answer;
void hannoi(int n, int from, int semi, int to) {
	if (n == 1) {
		answer.push_back({ from,to });
		return;
	}
	hannoi(n - 1, from, to, semi);
	hannoi(1, from, semi, to);
	hannoi(n - 1, semi, from, to);
}

vector<vector<int>> solution(int n) {
	hannoi(n, 1, 2, 3);
	return answer;
}