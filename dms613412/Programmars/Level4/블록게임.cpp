#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const int block[5][3][3] = {
	{{1,-1,-1},{1,1,1},{0,0,0}},
	 {{-1,1,0},{-1,1,0},{1,1,0}},
	 {{1,-1,0},{1,-1,0},{1,1,0}},
	 {{-1,-1,1},{1,1,1},{0,0,0}},
	 {{-1,1,-1},{1,1,1},{0,0,0}},
};

int solution(vector<vector<int>> board) {
	int answer = 0;
	int size = board.size();

	for (auto &x : board) {
		x.push_back(0);
	}
	board.push_back(vector<int>(size + 1, 0));

	bool isupdate = true;
	while (isupdate) {
		vector<int> cant;
		isupdate = false;
		for (int i = 0; i < size - 1; ++i) {
			for (int j = 0; j < size + 1; ++j) {
				if (board[i][j])cant.push_back(j);
				if (j >= size - 1)continue;
				for (int k = 0; k < 5; ++k) {
					bool isSet = true; int sum = 0, index = -100;
					bool havetoescape = false;
					for (int y = 0; y < 3; ++y) {
						if (havetoescape)break;
						for (int x = 0; x < 3; ++x) {
							if (isSet&&block[k][y][x] == 1 && board[i + y][j + x]) {
								isSet = false;
								index = board[i + y][j + x];

							}
							else if (!isSet && block[k][y][x] == 1 && board[i + y][j + x] != index) {
								isSet = true;
								havetoescape = true;
								break;
							}

							if (block[k][y][x] == -1 && (find(cant.begin(), cant.end(), j + x) != cant.end() || board[i + y][j + x])) {
								isSet = true;
								havetoescape = true;
								break;
							}
							sum += block[k][y][x] * board[i + y][j + x];

						}
					}
					if (!isSet && sum == 4 * index) {
						if (board[i][j] && block[k][0][0] != 0) cant.pop_back();
						for (int y = 0; y < 3; ++y) {
							for (int x = 0; x < 3; ++x) {
								if (block[k][y][x] != 0) board[i + y][j + x] = 0;
							}
						}
						isupdate = true;
						++answer;

						break;
					}
				}

			}
		}
	}

	return answer;
}