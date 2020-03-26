#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;
typedef pair<int,int> P;

vector<vector<P>> adj;
int n,m,x;

int dijk(int s,int e){
    vector<bool> visited(n+1);
    vector<int> dist(n+1,INF);
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
                dist[nxt] = dist[cur]+d;
                pq.push({dist[nxt],nxt});
            }
        }
    }

    return  dist[e];
}

int main(){  
    scanf("%d %d %d",&n,&m,&x);
    adj.resize(n+1);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
    }
    int ret=0;
    for(int i=1;i<=n;i++)   ret = max(ret,dijk(i,x)+dijk(x,i));
    printf("%d\n",ret);

    return 0;
}
