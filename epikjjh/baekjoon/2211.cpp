#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<bool> visited(n+1);
    vector<int> dist(n+1,100000);
    vector<vector<P>> adj(n+1);
    vector<int> prev(n+1,-1);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    dist[1] = 0;
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
                prev[nxt] = cur;
            }
        }
    }
    printf("%d\n",n-1);
    for(int i=2;i<=n;i++)   printf("%d %d\n",i,prev[i]);

    return 0;
}
