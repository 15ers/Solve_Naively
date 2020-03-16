#include <bits/stdc++.h>

using namespace std;

int arr[1000][1000];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[2][1000][1000];

int main(){
	int n,m;
    scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)    for(int j=0;j<m;j++)	scanf("%1d",&arr[i][j]);
	queue<int> q;
	q.push(0);
	visited[0][0][0] = true;
	bool flag=false;
	int ret=1;
	while(!q.empty()){
		int s = q.size();
		for(int i=0;i<s;i++){
			int crash = q.front()/(n*m);
			int cur_r = q.front()%(n*m)/m;
			int cur_c = q.front()%(n*m)%m;
			q.pop();
			if(cur_r==n-1&&cur_c==m-1){
				flag = true;
                printf("%d\n",ret);
				break;
			}
			for(int j=0;j<4;j++){
				int nxt_r = cur_r+dy[j];
				int nxt_c = cur_c+dx[j];
				if(nxt_r<0||nxt_r>=n||nxt_c<0||nxt_c>=m)	continue;
				if(visited[crash][nxt_r][nxt_c])	continue;
				if(arr[nxt_r][nxt_c]){
					if(crash)	continue;
					visited[1][nxt_r][nxt_c] = true;
					q.push(n*m+nxt_r*m+nxt_c);
				}
				else{
					visited[crash][nxt_r][nxt_c] = true;
					q.push(crash*n*m+nxt_r*m+nxt_c);
				}
			}
		}
		if(flag)	break;
		ret++;
	}
	if(!flag)	printf("-1\n");
		
	return 0;
}
