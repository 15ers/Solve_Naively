#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { 1,-1,0,0 };


bool func(int x) {
	return x != 0;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<vector<int> > region(m, vector<int>(n, 0));

	while (1) {
		vector<int>::iterator target;
		int target_x = -1, target_y = -1;
		int target_num;
		for (int i = 0; i < m; ++i) {
			target = find_if(picture[i].begin(), picture[i].end(), func);
			if (target != picture[i].end()) {
				target_x = target - picture[i].begin();
				target_y = i;
				break;
			}
		}
		if (target_x == -1) break;
		target_num = picture[target_y][target_x];
		++number_of_area;
		queue<pair<int, int>> que;
		que.push(make_pair(target_y, target_x));
		picture[target_y][target_x] = 0;
		int num = 0;
		while (!que.empty()) {
			pair<int, int> cur = que.front(); que.pop();
			++num;

			for (int dir = 0; dir < 4; ++dir) {
				int next_y = cur.first + dy[dir];
				int next_x = cur.second + dx[dir];
				if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n) continue;
				if (picture[next_y][next_x] != target_num)continue;
				que.push(make_pair(next_y, next_x));
				picture[next_y][next_x] = 0;

			}
		}
		max_size_of_one_area = max(max_size_of_one_area, num);
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}