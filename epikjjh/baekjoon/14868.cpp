#include <bits/stdc++.h>

using namespace std;

int p[4000000];
int arr[2000][2000];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

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
	int n,k;
	scanf("%d %d",&n,&k);
	memset(p,-1,sizeof(p));
	memset(arr,-1,sizeof(arr));
	queue<int> q;
	for(int i=0;i<k;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		x--;y--;
		arr[y][x] = i;
		q.push(y*n+x);
		for(int j=0;j<4;j++){
			int nx = x+dx[j];
			int ny = y+dy[j];
			if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx]<0)	continue;
			merge(arr[y][x],arr[ny][nx]);
		}
	}
	int ret=0;
	while(!q.empty()){
		int s=find(0);
		if(abs(p[s])>=k)	break;
		s=q.size();
		for(int i=0;i<s;i++){
			int y = q.front()/n;
			int x = q.front()%n;
 			q.pop();
			for(int j=0;j<4;j++){
				int ny = y+dy[j];
				int nx = x+dx[j];
				if(ny<0 || ny>=n || nx<0 || nx>=n || arr[ny][nx]>=0)	continue;
				arr[ny][nx] = arr[y][x];
				q.push(ny*n+nx);
				for(int l=0;l<4;l++){
					int nny = ny+dy[l];
					int nnx = nx+dx[l];
					if(nny<0 || nny>=n || nnx<0 || nnx>=n || arr[nny][nnx]<0)	continue;
					merge(arr[y][x],arr[nny][nnx]);
				}
			}
		}
		ret++;
	}
	printf("%d\n",ret);
	
	return 0;
}