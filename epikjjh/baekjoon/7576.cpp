#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[1000][1000];

int main(){
	int r,c,cnt=0;
	cin >> c >> r;
	queue<int> q;
	memset(arr,0,sizeof(arr));
	fill((bool*)visited,(bool*)visited+1000*1000,false);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> arr[i][j];
			if(arr[i][j]==1){
				q.push(i*c+j);
				visited[i][j] = true;
			}
			if(!arr[i][j])	cnt++;
		}
	}
	int ret=0;
	while(!q.empty()){
		if(!cnt)	break;
		int s = q.size();
		for(int i=0;i<s;i++){
			int cur_r = q.front()/c;
			int cur_c = q.front()%c;
			q.pop();
			for(int j=0;j<4;j++){
				int nxt_r = cur_r+dy[j];
				int nxt_c = cur_c+dx[j];
				if(nxt_r<0||nxt_r>=r||nxt_c<0||nxt_c>=c)	continue;
				if(visited[nxt_r][nxt_c])	continue;
				if(!arr[nxt_r][nxt_c]){
					visited[nxt_r][nxt_c] = true;
					q.push(nxt_r*c+nxt_c);
					cnt--;
				}
			}
		}
		ret++;
	}
	if(cnt)	cout << -1 << endl;
	else	cout << ret << endl;
		
	return 0;
}