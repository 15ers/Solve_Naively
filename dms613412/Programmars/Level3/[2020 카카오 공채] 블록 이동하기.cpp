#include <string>
#include <vector>
#include <queue>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
const int rx0[4][2] = { {0,-1},{1,0},{1,0},{0,-1} };
const int ry0[4][2] = { {0,1},{0,1},{-1,0},{-1,0} };
const int rx1[4][2] = { {0,1},{0,1},{-1,0},{-1,0} };
const int ry1[4][2] = { {0,-1},{1,0},{0,-1},{1,0} };
const int cx1[] = { 1,1,-1,-1 };
const int cy1[] = { 1,0,1,0 };
const int cx0[] = { 1,0,0,1 };
const int cy0[] = { 1,1,-1,-1 };

int N;
int visited[101][101][2] = { 0, };

typedef pair<int, int> Pair;

struct ROBOT {
	Pair a;
	Pair b;
	int time, type;

};

bool check(ROBOT &next, vector<vector<int>> &board, int type) {
	if (next.a.first < 0 || next.a.second < 0 || next.a.first >= N || next.a.second >= N) return false;
	if (next.b.first < 0 || next.b.second < 0 || next.b.first >= N || next.b.second >= N) return false;
	if (board[next.a.second][next.a.first] == 1 || board[next.b.second][next.b.first] == 1) return false;
	if (visited[next.a.second][next.a.first][type] == 1 && visited[next.b.second][next.b.first][type] == 1)return false;
	return true;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	ROBOT robot = { Pair(0,0),Pair(1,0),0,0 };
	queue<ROBOT> que;
	que.push(robot);

	ROBOT cur;
	visited[0][0][0] = 1; visited[0][1][0] = 1;
	while (!que.empty()) {
		cur = que.front(); que.pop();
		if (cur.b.first == N - 1 && cur.b.second == N - 1)return cur.time;
		//visited[cur.a.second][cur.a.first][cur.type]=1; visited[cur.b.second][cur.b.first][cur.type]=1;   
		ROBOT next;

		for (int dir = 0; dir < 4; ++dir) {
			next.a = Pair(cur.a.first + dx[dir], cur.a.second + dy[dir]);
			next.b = Pair(cur.b.first + dx[dir], cur.b.second + dy[dir]);
			if (!check(next, board, cur.type))continue;
			next.time = cur.time + 1; next.type = cur.type;
			visited[next.a.second][next.a.first][next.type] = 1; visited[next.b.second][next.b.first][next.type] = 1;
			que.push(next);
		}
		int cx, cy;
		for (int rot = 0; rot < 4; ++rot) {
			if (cur.type == 0) {
				cx = cur.a.first + cx0[rot];
				cy = cur.a.second + cy0[rot];
				if (cx<0 || cy<0 || cx>N - 1 || cy>N - 1 || board[cy][cx] == 1)continue;
				next.a = Pair(cur.a.first + rx0[rot][0], cur.a.second + ry0[rot][0]);
				next.b = Pair(cur.b.first + rx0[rot][1], cur.b.second + ry0[rot][1]);
				next.type = 1;
			}
			else {
				cx = cur.a.first + cx1[rot];
				cy = cur.a.second + cy1[rot];
				if (cx<0 || cy<0 || cx>N - 1 || cy>N - 1 || board[cy][cx] == 1)continue;
				next.a = Pair(cur.a.first + rx1[rot][0], cur.a.second + ry1[rot][0]);
				next.b = Pair(cur.b.first + rx1[rot][1], cur.b.second + ry1[rot][1]);
				next.type = 0;
			}

			if (!check(next, board, next.type))continue;

			next.time = cur.time + 1;
			visited[next.a.second][next.a.first][next.type] = 1; visited[next.b.second][next.b.first][next.type] = 1;
			que.push(next);

		}

	}
	return -1;
}
