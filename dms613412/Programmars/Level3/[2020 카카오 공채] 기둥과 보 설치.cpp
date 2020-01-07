#include <string>
#include <vector>
#include <iostream>

using namespace std;

int Gi[101][101] = { 0, };
int Bo[101][101] = { 0, };

const int dx[] = { 0,-1,1,0,0, -1,-1,1,1 };
const int dy[] = { 0,0,0,-1,1,-1,1,-1,1 };
int n;

bool correct(int x, int y, int b) {
	if (b == 0) {//remove
		for (int dir = 0; dir < 9; ++dir) {
			int nx = x + dx[dir]; int ny = y + dy[dir];
			if (nx < 0 || ny < 0 || nx>100 || ny>100) continue;
			if (Bo[ny][nx] == 1) { // remove bo
				if (Gi[ny + 1][nx] == 1 || Gi[ny + 1][nx + 1] == 1 || (0 < nx && Bo[ny][nx + 1] == 1 && Bo[ny][nx - 1] == 1));
				else return false;
			}
			if (Gi[ny][nx] == 1) { //remove gi
				if (ny == 100 || (ny < 100 && Gi[ny + 1][nx] == 1) || (0 < nx && Bo[ny][nx - 1] == 1) || Bo[ny][nx] == 1);
				else return false;
			}
		}
	}
	else if (b == 2) { //make bo
		if ((0 < x && Bo[y][x + 1] == 1 && Bo[y][x - 1] == 1) || (Gi[y + 1][x] == 1) || Gi[y + 1][x + 1] == 1) return true;
		else return false;
	}
	else {//make gi       
		if (y == 100 || (x > 0 && Bo[y][x - 1] == 1) || Bo[y][x] == 1 || Gi[y + 1][x] == 1) return true;
		else return false;
	}
	return true;
}

void remove(int x, int y, int a) {
	if (a == 0) {
		Gi[y][x] = 0;
		if (!correct(x, y, 0))Gi[y][x] = 1;
	}
	else {
		Bo[y][x] = 0;
		if (!correct(x, y, 0))Bo[y][x] = 1;
	}
}

void make(int x, int y, int a) {
	if (a == 0) {
		Gi[y][x] = 1;
		if (!correct(x, y, 1))Gi[y][x] = 0;

	}
	else {
		Bo[y][x] = 1;
		if (!correct(x, y, 2))Bo[y][x] = 0;
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	int size = build_frame.size();
	n = n;
	for (int s = 0; s < size; ++s) {
		if (build_frame[s][3] == 0) remove(build_frame[s][0], 100 - build_frame[s][1], build_frame[s][2]);
		else make(build_frame[s][0], 100 - build_frame[s][1], build_frame[s][2]);
	}

	vector<vector<int>> answer;
	for (int x = 0; x < n + 1; ++x) {
		for (int y = 0; y < n + 1; ++y) {
			if (Gi[100 - y][x] == 1) {
				answer.push_back({ x,y,0 });
			}
			if (Bo[100 - y][x] == 1) {
				answer.push_back({ x,y,1 });
			}
		}
	}

	return answer;
}