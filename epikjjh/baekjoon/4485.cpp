#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

typedef pair<int,int> P;

int arr[125][125];
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(){
    int n,t=1;
    while(scanf("%d",&n), n){
        for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    scanf("%d", &arr[i][j]);
        vector<vector<P>> adj(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int nr=i+dr[k],nc=j+dc[k];
                    if(nr<0 || nr>=n || nc<0 || nc>=n)  continue;
                    adj[i*n+j].push_back({nr*n+nc,arr[nr][nc]});
                }
            }
        }
        vector<bool> visited(n*n);
        vector<int> dist(n*n,INF);
        dist[0] = arr[0][0];
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({dist[0],0});
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
        printf("Problem %d: %d\n",t,dist[n*n-1]);
        t++;
    }

    return 0;
}
