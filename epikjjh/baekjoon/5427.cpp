#include <bits/stdc++.h>

using namespace std;

char arr[1000][1000];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
bool visited[1000][1000];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int w,h;
		memset(arr,0,sizeof(arr));
		fill((bool*)visited,(bool*)visited+1000*1000,false);
		scanf("%d %d",&w,&h);
        queue<int> f,q;
		for(int i=0;i<h;i++){
			getchar();
			for(int j=0;j<w;j++){
                arr[i][j] = getchar();
                if(arr[i][j]=='@'){
					q.push(i*w+j);
					visited[i][j] = true;
				}
				if(arr[i][j]=='*')    f.push(i*w+j);
            }
		}
		int ret = 0;
		bool flag = false;
		while(!q.empty()){
            ret++;
			int s = f.size();
			for(int i=0;i<s;i++){
				int cur_y = f.front()/w;
				int cur_x = f.front()%w;
				f.pop();
				for(int j=0;j<4;j++){
					int nxt_y = cur_y+dy[j];
					int nxt_x = cur_x+dx[j];
                    if(nxt_y<0||nxt_y>=h||nxt_x<0||nxt_x>=w)    continue;
					if(arr[nxt_y][nxt_x]=='.'){
							arr[nxt_y][nxt_x] = '*';
							f.push(nxt_y*w+nxt_x);
					}
				}
			}
			s = q.size();
			for(int i=0;i<s;i++){
				int cur_y = q.front()/w;
				int cur_x = q.front()%w;
				q.pop();
				for(int j=0;j<4;j++){
					int nxt_y = cur_y+dy[j];
					int nxt_x = cur_x+dx[j];
					if(nxt_y<0||nxt_y>=h||nxt_x<0||nxt_x>=w){
						flag = true;
						break;
					}
                    if(arr[nxt_y][nxt_x]=='.'&&!visited[nxt_y][nxt_x]){
                        visited[nxt_y][nxt_x] = true;
                        q.push(nxt_y*w+nxt_x);
                    }
				}
			}
			if(flag)	break;
		}
		if(flag)	cout << ret << endl;
        else    cout << "IMPOSSIBLE" << endl;
	}
	
	return 0;
}