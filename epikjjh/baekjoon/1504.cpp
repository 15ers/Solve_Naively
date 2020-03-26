#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> P;

int n;
vector<vector<P>> adj;

long long dijk(int s, int e){
    vector<bool> visited(n+1);
    vector<int> dist(n+1,INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    dist[s] = 0;
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
                dist[nxt] = dist[cur]+d;
                pq.push({dist[nxt],nxt});
            }
        }
    }

    return dist[e];
}

int main(){
    int e;
    scanf("%d %d",&n,&e);
    adj.resize(n+1);
    while(e--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    int a,b;
    scanf("%d %d",&a,&b);
    long long ret = min(dijk(1,a)+dijk(a,b)+dijk(b,n),dijk(1,b)+dijk(b,a)+dijk(a,n));
    if(ret>=INF)    printf("-1\n");
    else    printf("%lld\n",ret);

    return 0;
}
