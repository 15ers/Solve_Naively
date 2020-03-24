#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> adj(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> dist(n+1);
    vector<bool> visited(n+1);
    fill(dist.begin()+2,dist.end(),INF);
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
        for(int nxt: adj[cur]){
            if(dist[nxt]>dist[cur]+1){
                dist[nxt] = dist[cur]+1;
                pq.push({dist[nxt],nxt});
            }
        }
    }
    int ret=0,cnt=0,idx;
    bool flag=true;
    for(int i=2;i<=n;i++)   ret = max(ret,dist[i]);
    for(int i=2;i<=n;i++){
        if(ret==dist[i]){
            cnt++;
            if(flag){
                idx = i;
                flag = false;
            }
        }
    }
    printf("%d %d %d\n",idx,ret,cnt);

    return 0;
}
