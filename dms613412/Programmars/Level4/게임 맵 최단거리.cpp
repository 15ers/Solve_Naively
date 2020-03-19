#include<vector>
#include<queue>
using namespace std;
struct Character {
	int y, x, time;
};
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0, -1,1 };
int visited[101][101] = { 0, };
int solution(vector<vector<int> > maps)
{
	int n = maps.size();
	int m = maps[0].size();
	queue<Character> que;
	que.push({ 0,0,1 });
	Character cur;
	while (!que.empty()) {
		cur = que.front(); que.pop();
		if (cur.y == n - 1 && cur.x == m - 1) return cur.time;
		Character next;
		for (int dir = 0; dir < 4; ++dir) {
			next.x = cur.x + dx[dir];
			next.y = cur.y + dy[dir];
			if (next.y<0 || next.x<0 || next.y>n - 1 || next.x>m - 1
				|| visited[next.y][next.x] || !maps[next.y][next.x])continue;
			visited[next.y][next.x] = 1;
			que.push({ next.y,next.x,cur.time + 1 });
		}
	}
	return -1;
}