
#include <cstdio>
#include<iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;
int N, M;
int arr[50][50];
int sumarr[51][51];
long long cache[50][50][50][50];

int func(pair<int, int> a, pair<int, int> b) {
	if (a == b)return 0;
	long long sum = 0, total_sum = LLONG_MAX;
	sum = sumarr[b.first + 1][b.second + 1] - sumarr[b.first + 1][a.second] - sumarr[a.first][b.second + 1] + sumarr[a.first][a.second];

	for (int index = a.second; index < b.second; ++index) {
		long long &left = cache[a.first][b.first][a.second][index];
		long long &right = cache[a.first][b.first][index + 1][b.second];
		if (!left) left = func(make_pair(a.first, a.second), make_pair(b.first, index));
		if (!right) right = func(make_pair(a.first, index + 1), make_pair(b.first, b.second));
		total_sum = min(left + right, total_sum);
	}

	for (int index = a.first; index < b.first; ++index) {
		long long &left = cache[a.first][index][a.second][b.second];
		long long &right = cache[index + 1][b.first][a.second][b.second];
		if (!left) left = func(make_pair(a.first, a.second), make_pair(index, b.second));
		if (!right) right = func(make_pair(index + 1, a.second), make_pair(b.first, b.second));
		total_sum = min(left + right, total_sum);
	}

	return cache[a.first][b.first][a.second][b.second] = total_sum + sum;
}

int main()
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(cache, 0, sizeof(cache));
		memset(sumarr, 0, sizeof(sumarr));
		scanf("%d %d", &N, &M);

		for (int y = 0; y < N; ++y) {
			for (int x = 0; x < M; ++x) {
				scanf("%d", &arr[y][x]);
				sumarr[y + 1][x + 1] = sumarr[y][x + 1] + sumarr[y + 1][x] - sumarr[y][x] + arr[y][x];
			}
		}

		printf("#%d %lld\n", test_case, func(make_pair(0, 0), make_pair(N - 1, M - 1)));

		//cout << cache[0][1][0][0] << " " << cache[0][1][1][1] << " " << cache[0][1][2][2] << " " << cache[0][1][0][1] << endl;
	}
	return 0;
}