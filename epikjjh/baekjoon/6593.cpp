#include <bits/stdc++.h>

using namespace std;

char arr[30][30][30];
bool visited[30][30][30];
int dz[6] = {0,0,0,0,1,-1};
int dy[6] = {1,-1,0,0,0,0};
int dx[6] = {0,0,1,-1,0,0,};

int main(){
	int l,r,c;
	int s_z,s_y,s_x,e_z,e_y,e_x;
	char ch;
	while(cin>>l>>r>>c,l&&r&&c){
		memset(arr,0,sizeof(arr));
		fill(&visited[0][0][0],&visited[0][0][0]+sizeof(visited),false);
		for(int i=0;i<l;i++){
			getchar();
			for(int j=0;j<r;j++){
				for(int k=0;k<c;k++){
					ch = getchar();
					arr[i][j][k] = ch;
					if(ch=='S'){
						s_z = i;
						s_y = j;
						s_x = k;
					}
					if(ch=='E'){
						e_z = i;
						e_y = j;
						e_x = k;
					}
				}
				getchar();
			}
		}
		queue<int> q;
		q.push(s_z*r*c+s_y*c+s_x);
		visited[s_z][s_y][s_x] = true;
		bool flag = false;
		int ret = 0;
		while(!q.empty()){
			int s = q.size();
			for(int i=0;i<s;i++){
				int cur_z = q.front()/(r*c);
				int cur_y = (q.front()-(cur_z*r*c))/c;
				int cur_x = (q.front()-(cur_z*r*c))%c;
				q.pop();
				if(cur_z==e_z && cur_y==e_y && cur_x==e_x){
					flag = true;
					break;
				}
				for(int j=0;j<6;j++){
					int nxt_z = cur_z + dz[j];
					int nxt_y = cur_y + dy[j];
					int nxt_x = cur_x + dx[j];
					if(0<=nxt_z&&nxt_z<l &&0<=nxt_y&&nxt_y<r && 0<=nxt_x&&nxt_x<c){
						if(!visited[nxt_z][nxt_y][nxt_x]&&arr[nxt_z][nxt_y][nxt_x]!='#'){
							visited[nxt_z][nxt_y][nxt_x] = true;
							q.push(nxt_z*r*c+nxt_y*c+nxt_x);
						}
					}
				}
			}
			if(flag){
				cout << "Escaped in " << ret << " minute(s)." << endl;
				break;
			}
			ret++;
		}
		if(!flag)	cout << "Trapped!" << endl;
	}
	return 0;
}