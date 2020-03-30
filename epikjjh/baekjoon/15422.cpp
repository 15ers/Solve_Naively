#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, int> P;
const long long INF=10987654321;
const int MAX=50000;
vector<vector<vector<P>>> adj;

int main(){
    int n,m,f,s,t;
    scanf("%d %d %d %d %d",&n,&m,&f,&s,&t);
    adj.resize(2,vector<vector<P>>(n));
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[0][a].push_back({b,c});
        adj[0][b].push_back({a,c});
        adj[1][a].push_back({b,c});
        adj[1][b].push_back({a,c});
    }
    vector<vector<long long>> dist(2,vector<long long>(n,INF));
    vector<vector<bool>> visited(2,vector<bool>(n));
    dist[0][s] = 0;
    while(f--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[0][a].push_back({b,0});
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int cur,flight;
        do{
            flight = pq.top().second/MAX;
            cur = pq.top().second%MAX;
            pq.pop();
        }while(!pq.empty() && visited[flight][cur]);
        if(visited[flight][cur])    break;
        visited[flight][cur] = true;
        if(flight){
            for(auto &p: adj[1][cur]){
                int nxt=p.first;
                long long d=p.second;
                if(dist[1][nxt]>dist[1][cur]+d){
                    dist[1][nxt] = dist[1][cur]+d;
                    pq.push({dist[1][nxt],nxt+MAX});
                }
            }
        }
        else{
            for(auto &p: adj[0][cur]){
                int nxt=p.first;
                long long d=p.second;
                if(!d){
                    dist[1][nxt] = dist[0][cur];
                    pq.push({dist[1][nxt],nxt+MAX});
                }
                else{
                    if(dist[0][nxt]>dist[0][cur]+d){
                        dist[0][nxt] = dist[0][cur]+d;
                        pq.push({dist[0][nxt],nxt});
                    }
                }
            }
        }
    }
    printf("%lld\n",min(dist[0][t],dist[1][t]));

    return 0;
}
