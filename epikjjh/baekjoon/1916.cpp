#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<P>> adj(n+1);
    vector<bool> visited(n+1);
    vector<int> dist(n+1);
    fill(dist.begin(),dist.end(),INF);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
    }
    int s,e;
    scanf("%d %d",&s,&e);
    dist[s] = 0;
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,s});
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
                dist[nxt] = dist[cur] + d;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    printf("%d\n",dist[e]);
}
