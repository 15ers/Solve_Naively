#include <string>
#include <vector>

using namespace std;
long long cache[2001] = { 0, };
long long fibonachi(long long x) {
	if (x == 1)return 1;
	if (x == 2)return 2;
	long long &tmp = cache[x];
	if (tmp)return cache[x];
	tmp = (fibonachi(x - 1) + fibonachi(x - 2)) % 1234567;
	return tmp;
}

long long solution(int n) {
	long long answer = fibonachi(n) % 1234567;
	return answer;
}