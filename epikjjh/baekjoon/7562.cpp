#include <bits/stdc++.h>

using namespace std;

int dy[8] = {-2,-2,-1,-1,1,1,2,2};
int dx[8] = {-1,1,-2,2,-2,2,-1,1};
bool visited[300][300];

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int s_x,s_y,e_x,e_y;
		cin >> s_y >> s_x >> e_y >> e_x;
		queue<int> q;
		q.push(s_y*n+s_x);
		fill(&visited[0][0],&visited[300][0],false);
		visited[s_y][s_x] = true;
		int ret = 0;
		bool flag = false;
		while(!q.empty()){
			int s = q.size();
			for(int i=0;i<s;i++){
				int cur_x = q.front()%n;
				int cur_y = q.front()/n;
				q.pop();
				if(cur_x==e_x && cur_y==e_y){
					cout << ret << endl;
					flag = true;
					break;
				}
				for(int j=0;j<8;j++){
					int nxt_x = cur_x+dx[j];
					int nxt_y = cur_y+dy[j];
					if(0<=nxt_x&&nxt_x<n && 0<=nxt_y&&nxt_y<n && !visited[nxt_y][nxt_x]){
						visited[nxt_y][nxt_x] = true;
						q.push(nxt_y*n+nxt_x);
					}
				}
			}
			if(flag)	break;
			ret++;
		}
	}
	
	return 0;
}