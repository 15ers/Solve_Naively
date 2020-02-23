#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int dy[] = { -1,1,0,0 };//U D R L
const int dx[] = { 0,0,1,-1 };

int visited1[11][10] = { 0, }; //가로
int visited2[10][11] = { 0, }; //세로

int solution(string dirs) {

	int curx = 5, cury = 5;
	int answer = 0;
	for (auto &x : dirs) {
		//cout<<"좌표:"<<cury<<" "<<curx<<endl;
		//cout<<"answer:"<<answer<<endl;        
		switch (x) {
		case 'U':
			curx += dx[0];
			cury += dy[0];
			if (curx < 0 || cury < 0 || curx>10 || cury >10) {
				curx -= dx[0];
				cury -= dy[0];
				break;
			}

			if (!visited2[cury][curx]) {
				++answer;
				visited2[cury][curx] = 1;
			}
			break;
		case 'D':
			curx += dx[1];
			cury += dy[1];
			if (curx < 0 || cury < 0 || curx>10 || cury >10) {
				curx -= dx[1];
				cury -= dy[1];
				break;
			}
			if (!visited2[cury - dy[1]][curx - dx[1]]) {
				++answer;
				visited2[cury - dy[1]][curx - dx[1]] = 1;
			}
			break;
		case 'R':
			curx += dx[2];
			cury += dy[2];
			if (curx < 0 || cury < 0 || curx>10 || cury >10) {
				curx -= dx[2];
				cury -= dy[2];
				break;
			}
			if (!visited1[cury - dy[2]][curx - dx[2]]) {
				++answer;
				visited1[cury - dy[2]][curx - dx[2]] = 1;
			}
			break;
		case 'L':
			curx += dx[3];
			cury += dy[3];
			if (curx < 0 || cury < 0 || curx>10 || cury >10) {
				curx -= dx[3];
				cury -= dy[3];
				break;
			}
			if (!visited1[cury][curx]) {
				++answer;
				visited1[cury][curx] = 1;
			}
			break;

		}
	}

	return answer;
}