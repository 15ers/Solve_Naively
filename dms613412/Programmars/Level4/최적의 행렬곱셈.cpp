#include <string>
#include <vector>

using namespace std;

int map[200][200] = { 0, };
vector<vector<int>> matrix;

int func(int a, int b) {
	if (a == b)return 0;
	int tmp = 2147483647;
	for (int n = a; n < b; ++n) {
		int &first = map[a][n];
		if (!first)first = func(a, n);
		int &second = map[n + 1][b];
		if (!second)second = func(n + 1, b);

		tmp = min(tmp, first + second +
			matrix[a][0] * matrix[n + 1][0] * matrix[b][1]);
	}
	map[a][b] = tmp;
	return tmp;
}

int solution(vector<vector<int>> matrix_sizes) {
	int size = matrix_sizes.size();
	matrix = matrix_sizes;

	return func(0, size - 1);
}