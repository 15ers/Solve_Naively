#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[100][100];

int main(){
	int n,m;
    scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)	for(int j=0;j<m;j++)	scanf("%1d",&arr[i][j]);
	queue<int> q;
	q.push(0);
	visited[0][0] = true;
	int ret = 1;
	bool flag = false;
	while(!q.empty()){
		int s = q.size();
		for(int i=0;i<s;i++){
			int cur_x = q.front()%m;
			int cur_y = q.front()/m;
			q.pop();
			if(cur_x==m-1 && cur_y==n-1){
				flag = true;
				break;
			}
			for(int j=0;j<4;j++){
				int nxt_x = cur_x+dx[j];
				int nxt_y = cur_y+dy[j];
                if(nxt_x<0 || nxt_x>=m  || nxt_y<0 || nxt_y>=n) continue;
				if(arr[nxt_y][nxt_x]&&!visited[nxt_y][nxt_x]){
					visited[nxt_y][nxt_x] = true;
					q.push(nxt_y*m+nxt_x);
				}
			}
		}
		if(flag)	break;
		ret++;
	}
    printf("%d\n",ret);
	
	return 0;
}
