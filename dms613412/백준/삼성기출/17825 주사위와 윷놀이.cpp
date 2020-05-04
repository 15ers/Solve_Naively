#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


const int pan1[] = { 10,13,16,19,25,30,35,40 };
const int pan2[] = { 20,22,24,25,30,35,40 };
const int pan3[] = { 30,28,27,26,25,30,35,40 };

struct MAL {
	int x, pan_index;
	bool finish;
	int number;
};
vector<MAL> mal(4, { 0,0,false,0 });
int arr[10], answer = 0;

void dfs(int num, int sum) {

	if (num == 10) {
		answer = max(answer, sum);


		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (mal[i].finish)continue;
		int init_panindex = mal[i].pan_index, init_x = mal[i].x, init_number = mal[i].number;
		mal[i].x += arr[num];

		switch (mal[i].pan_index) {
		case 0:
			if (mal[i].x > 20) {
				mal[i].finish = true;
				dfs(num + 1, sum);
				mal[i].finish = false;
			}
			else {
				int tmp = mal[i].x;
				if (mal[i].x < 20 && (mal[i].x % 5) == 0) {
					mal[i].pan_index = mal[i].x / 5;
					mal[i].x = 0;
				}

				bool ispossible = true;
				for (int j = 0; j < 4; ++j) {
					if (i == j)continue;
					if (mal[j].finish)continue;

					if (mal[i].x == mal[j].x && mal[i].pan_index == mal[j].pan_index) {
						ispossible = false;
						break;
					}
					else if (mal[i].x == 20 && mal[j].number == 40) {
						ispossible = false;
						break;
					}
				}
				if (!ispossible) {
					break;
				}
				mal[i].number = 2 * tmp;
				//cout << mal[i].number << endl;
				dfs(num + 1, sum + 2 * tmp);
			}
			break;
		case 1:
			if (mal[i].x >= 8) {
				mal[i].finish = true;
				dfs(num + 1, sum);
				mal[i].finish = false;
			}
			else {
				bool ispossible = true;
				for (int j = 0; j < 4; ++j) {
					if (i == j)continue;
					if (mal[j].finish)continue;

					if (mal[i].x == mal[j].x && mal[i].pan_index == mal[j].pan_index) {
						ispossible = false;
						break;
					}
					else if (mal[j].x > 2 && mal[j].pan_index != 0 && pan1[mal[i].x] == mal[j].number) {
						ispossible = false;
						break;
					}
					else if (mal[j].number == 40 && pan1[mal[i].x] == 40) {
						ispossible = false;
						break;
					}
				}
				if (!ispossible) {
					break;
				}
				mal[i].number = pan1[mal[i].x];
				dfs(num + 1, sum + pan1[mal[i].x]);
			}
			break;
		case 2:
			if (mal[i].x >= 7) {
				mal[i].finish = true;
				dfs(num + 1, sum);
				mal[i].finish = false;
			}
			else {
				bool ispossible = true;
				for (int j = 0; j < 4; ++j) {
					if (i == j)continue;
					if (mal[j].finish)continue;

					if (mal[i].x == mal[j].x && mal[i].pan_index == mal[j].pan_index) {
						ispossible = false;
						break;
					}
					else if (mal[j].x > 2 && mal[j].pan_index != 0 && pan2[mal[i].x] == mal[j].number) {
						ispossible = false;
						break;
					}
					else if (mal[j].number == 40 && pan2[mal[i].x] == 40) {
						ispossible = false;
						break;
					}
				}
				if (!ispossible) {
					break;
				}
				mal[i].number = pan2[mal[i].x];
				dfs(num + 1, sum + pan2[mal[i].x]);
			}
			break;
		case 3:
			if (mal[i].x >= 8) {
				mal[i].finish = true;
				dfs(num + 1, sum);
				mal[i].finish = false;
			}
			else {
				bool ispossible = true;
				for (int j = 0; j < 4; ++j) {
					if (i == j)continue;
					if (mal[j].finish)continue;

					if (mal[i].x == mal[j].x && mal[i].pan_index == mal[j].pan_index) {
						ispossible = false;
						break;
					}
					else if (mal[j].x > 2 && mal[j].pan_index != 0 && pan3[mal[i].x] == mal[j].number) {
						ispossible = false;
						break;
					}
					else if (mal[j].number == 40 && pan3[mal[i].x] == 40) {
						ispossible = false;
						break;
					}
				}
				if (!ispossible) {
					break;
				}
				mal[i].number = pan3[mal[i].x];
				dfs(num + 1, sum + pan3[mal[i].x]);
			}
			break;
		}
		mal[i].x = init_x; mal[i].pan_index = init_panindex; mal[i].number = init_number;
	}
}


int main() {

	for (int i = 0; i < 10; ++i)
		scanf("%d", &arr[i]);

	dfs(0, 0);
	printf("%d\n", answer);
	return 0;
}