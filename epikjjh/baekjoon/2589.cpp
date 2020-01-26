#include <bits/stdc++.h>

using namespace std;

int arr[50][50];
bool visited[50][50];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ret=0;
int r,c;

void bfs(int cur){
	queue<int> q;
	q.push(cur);
	int loc=0;
	while(!q.empty()){
		int s = q.size();
		for(int i=0;i<s;i++){
			int cur_r = q.front()/c;
			int cur_c = q.front()%c;
			q.pop();
			for(int j=0;j<4;j++){
				int nxt_r = cur_r+dy[j];
				int nxt_c = cur_c+dx[j];
				if(nxt_r<0 || r<=nxt_r)	continue;
				if(nxt_c<0 || c<=nxt_c)	continue;
				if(!arr[nxt_r][nxt_c] || visited[nxt_r][nxt_c])	continue;
				visited[nxt_r][nxt_c] = true;
				q.push(nxt_r*c+nxt_c);
			}
		}
		loc++;
	}
	ret = max(ret,loc);
}


int main(){
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++){
		string s;
		cin >> s;
		for(int j=0;j<c;j++)	if(s[j]=='L')	arr[i][j] = 1;
	}
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]){
				fill((bool*)visited,(bool*)visited+50*50,false);
				visited[i][j] = true;
				bfs(i*c+j);
			}
		}
	}
	cout << ret-1 << endl;
	
	return 0;
}