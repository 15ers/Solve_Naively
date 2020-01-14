#include <bits/stdc++.h>

using namespace std;

char arr[50][50];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[50][50];

int main(){
	int r,c;
	queue<int> q,w;
	cin >> r >> c;
	memset(arr,0,sizeof(arr));
	fill((bool*)visited,(bool*)visited+50*50,false);
	for(int i=0;i<r;i++){
		getchar();
		for(int j=0;j<c;j++){
			arr[i][j] = getchar();
			if(arr[i][j]=='S'){
				q.push(i*c+j);
				visited[i][j] = true;
			}
			else if(arr[i][j]=='*')	w.push(i*c+j);
		}
	}
	bool flag = false;
	int ret = 0;
	while(!q.empty()){
		int s = w.size();
		for(int i=0;i<s;i++){
			int cur_r = w.front()/c;
			int cur_c = w.front()%c;
			w.pop();
			for(int j=0;j<4;j++){
				int nxt_r = cur_r+dy[j];
				int nxt_c = cur_c+dx[j];
				if(nxt_r<0||nxt_r>=r||nxt_c<0||nxt_c>=c)	continue;
				if(arr[nxt_r][nxt_c]=='.'){
					arr[nxt_r][nxt_c] = '*';
					w.push(nxt_r*c+nxt_c);
				}
			}
		}
		s = q.size();
		for(int i=0;i<s;i++){
			int cur_r = q.front()/c;
			int cur_c = q.front()%c;
			q.pop();
			if(arr[cur_r][cur_c]=='D'){
				cout << ret << endl;
				flag = true;
				break;
			}
			for(int j=0;j<4;j++){
				int nxt_r = cur_r+dy[j];
				int nxt_c = cur_c+dx[j];
				if(nxt_r<0||nxt_r>=r||nxt_c<0||nxt_c>=c)	continue;
				if(arr[nxt_r][nxt_c]=='*')	continue;
				if(arr[nxt_r][nxt_c]=='X')	continue;
				if(!visited[nxt_r][nxt_c]){
					q.push(nxt_r*c+nxt_c);
					visited[nxt_r][nxt_c] = true;
				}
			}
		}
		if(flag)	break;
		ret++;
	}
	if(!flag)	cout << "KAKTUS" << endl;
		
	return 0;
}