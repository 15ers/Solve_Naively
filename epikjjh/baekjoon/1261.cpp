#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
const int INF = 987654321;

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(){
	int arr[100][100],m,n;
	cin >> m >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)	scanf("%1d", &arr[i][j]);
	}
	vector<vector<P>> adj(n*m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<4;k++){
				int nr = i+dr[k];
				int nc = j+dc[k];
				if(nr<0 || nr>=n || nc<0 || nc>=m)	continue;
				int cur = i*m+j;
				int nxt = nr*m+nc;
				int val = arr[nr][nc] ? 1 : 0;
				adj[cur].push_back({nxt,val});
			}
		}
	}
	vector<int> dist(n*m,INF);
	vector<bool> visited(n*m);
	dist[0] = 0;
	priority_queue<P,vector<P>,greater<P>> pq;
	pq.push({0,0});
	while(!pq.empty()){
		int cur;
		do{
			cur = pq.top().second;
			pq.pop();
		}while(!pq.empty() && visited[cur]);
		if(visited[cur])	break;
		visited[cur] = true;
		for(auto &p: adj[cur]){
			int nxt = p.first;
			int d = p.second;
			if(dist[nxt]>dist[cur]+d){
				dist[nxt] = dist[cur]+d;
				pq.push({dist[nxt],nxt});
			}
		}
	}
	cout << dist[n*m-1] << endl;
	
	return 0;
}