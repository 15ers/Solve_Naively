#include <string>
#include <vector>
#include <iostream>

using namespace std;

int M, N;
void rotate(vector<vector<int>> &key) {
	vector<vector<int>> tmp = key;
	for (int i_rot = 0; i_rot < M; ++i_rot) {
		for (int j_rot = 0; j_rot < M; ++j_rot) {
			tmp[i_rot][j_rot] = key[M - 1 - j_rot][i_rot];
		}
	}
	key = tmp;
	return;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	M = key.size();
	N = lock.size();
	int total = N + (M - 1) * 2;

	vector<vector<int>> background(total, vector<int>(total, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			background[i + M - 1][j + M - 1] = lock[i][j];
		}
	}

	int flag;
	for (int rot = 0; rot < 4; ++rot) {
		for (int i = 0; i < M + N - 1; ++i) {
			for (int j = 0; j < M + N - 1; ++j) {
				for (int k = 0; k < M; ++k) {
					for (int l = 0; l < M; ++l) {
						background[i + k][j + l] += key[k][l];
					}
				}
				flag = 0;
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < N; ++j) {
						if (background[i + M - 1][j + M - 1] != 1) {
							flag = 1; i = N + 1; break;
						}

					}
				}
				if (flag == 0) { return true; }
				for (int i = 0; i < N; ++i) {
					for (int j = 0; j < N; ++j) {
						background[i + M - 1][j + M - 1] = lock[i][j];
					}
				}
			}
		}
		rotate(key);
	}

	return false;

}