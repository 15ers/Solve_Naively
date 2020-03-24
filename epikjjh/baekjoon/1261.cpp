#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

typedef pair<int,int> P;

int arr[100][100];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    vector<vector<P>> adj(n*m+1);
    vector<bool> visited(n*m+1);
    vector<int> dist(n*m+1);
    fill(dist.begin(),dist.end(),INF);
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    scanf("%1d",&arr[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nr=i+dr[k],nc=j+dc[k];
                if(nr<0 || nr>=n || nc<0 || nc>=m)  continue;
                int d=arr[nr][nc] ? 1 : 0;
                adj[nr*m+nc+1].push_back({i*m+j+1,d});
            }
        }
    }
    dist[1] = 0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        int cur;
        do{
            cur = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[cur]);
        if(visited[cur])    break;
        visited[cur] = true;
        for(auto &p: adj[cur]){
            int nxt=p.first,d=p.second;
            if(dist[nxt]>dist[cur]+d){
                dist[nxt] = dist[cur]+d;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    printf("%d\n",dist[n*m]);

    return 0;
}
