#include <string>
#include <vector>

using namespace std;

//카탈린 수

int combination(int n, int r) {
	if (n == r || r == 0)return 1;
	else
		return combination(n - 1, r - 1) + combination(n - 1, r);
}

int solution(int n) {
	int answer = combination(2 * n, n) / (n + 1);
	return answer;
}