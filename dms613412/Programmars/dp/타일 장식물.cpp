#include <string>
#include <vector>
#include <iostream>

using namespace std;
long long cache[81] = { 0, };
long long fibo(long long n) {
	if (cache[n])return cache[n];
	return (cache[n] = fibo(n - 1) + fibo(n - 2));
}

long long solution(int N) {
	cache[1] = 4; cache[2] = 6;
	return fibo(N);
}