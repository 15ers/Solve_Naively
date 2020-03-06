#include <bits/stdc++.h>

using namespace std;

char arr[1500][1500];
int p[2250000];
bool visited[2250000];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int find(int n){
	if(p[n]<0)	return n;
	return p[n] = find(p[n]);
}
void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b)	return;
	if(p[a]>p[b])	swap(a,b);
	p[a] += p[b];
	p[b] = a;
}

int main(){
	int r,c,s=-1,e=-1;
	scanf("%d %d",&r,&c);
	memset(p,-1,sizeof(p));
	for(int i=0;i<r;i++){
		getchar();
		for(int j=0;j<c;j++)	scanf("%1c",&arr[i][j]);
	}
	queue<int> q;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(arr[i][j]=='X'){
				for(int k=0;k<4;k++){
					int nr=i+dr[k]; 
					int nc=j+dc[k];
					if(nr<0 || nr>=r || nc<0 || nc>=c)	continue;
					if(arr[nr][nc]!='X'){
						visited[i*c+j] = true;
						q.push(i*c+j);
						break;
					}
				}
			}
			else{
				if(arr[i][j]=='L'){
					if(s>=0)	e = i*c+j;
					else	s = i*c+j;
				}
				for(int k=0;k<4;k++){
					int nr=i+dr[k]; 
					int nc=j+dc[k];
					if(nr<0 || nr>=r || nc<0 || nc>=c)	continue;
					if(arr[nr][nc]!='X')	merge(i*c+j,nr*c+nc);
				}
			}
		}
	}
	int ret=0;
	while(!q.empty()){
		if(find(s)==find(e))	break;
		int s=q.size();
		for(int i=0;i<s;i++){
			int cur_r=q.front()/c;
			int cur_c=q.front()%c;
			q.pop();
			arr[cur_r][cur_c] = '.';
			for(int j=0;j<4;j++){
				int nr=cur_r+dr[j];
				int nc=cur_c+dc[j];
				if(nr<0 || nr>=r || nc<0 || nc>=c)	continue;
				if(arr[nr][nc]=='X'){
					if(!visited[nr*c+nc]){
						visited[nr*c+nc] = true;
						q.push(nr*c+nc);
					}
				}
				else	merge(cur_r*c+cur_c,nr*c+nc);
			}
		}
		ret++;
	}
	printf("%d\n",ret);
	
	return 0;
}