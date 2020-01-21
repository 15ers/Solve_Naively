#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

long long cache[60000] = { 0, };


long long fibo(int n) {
	if (cache[n] != 0) return cache[n];
	cache[n] = (fibo(n - 1) + fibo(n - 2)) % 1000000007;
	return cache[n];
}

int solution(int n) {
	if (n == 1) return 1;
	cache[0] = 1; cache[1] = 2;

	return fibo(n - 1);
}