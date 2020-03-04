#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long cache[2501] = { 0, };
long long sum[2501] = { 0, };

long long func(int x) {
	if (x == 0)return 1;
	if (x == 1)return 3;
	long long &tmp = cache[x];
	if (tmp) return tmp;
	//tmp = ((func(x-1)*4) - (func(x-2)))%1000000007; (수가 커지면 음수인 경우가 생김)
	tmp = (3 * func(x - 1) + 2 * sum[x - 2]) % 1000000007;
	sum[x] = sum[x - 1] + tmp;
	return tmp;
}

int solution(int n) {
	sum[0] = 1; sum[1] = 4;
	if (n % 2)return 0;
	return func(n / 2);
}