#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<P>> adj(n+1);
    vector<vector<int>> check(n+1);
    vector<int> dist(n+1,INF),prev(n+1);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c*-1});
        check[b].push_back(a);
    }
    queue<int> q;
    vector<bool> visited(n+1);
    visited[n] = true;
    q.push(n);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int nxt: check[cur]){
            if(!visited[nxt]){
                visited[nxt] = true; 
                q.push(nxt);
            }
        }
    }
    dist[1] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(auto &p: adj[j]){
                int nxt=p.first,d=p.second;
                if(dist[j]!=INF && dist[nxt]>dist[j]+d){
                    dist[nxt] = dist[j]+d;
                    prev[nxt] = j;
                    if(i==n && visited[nxt]){
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
    }
    if(dist[n]==INF)  printf("-1\n");
    else{
        int cur=n;
        vector<int> route;
        do{
            route.push_back(cur);
            cur = prev[cur];
        }while(cur!=1);
        reverse(route.begin(),route.end());
        printf("1 ");
        for(int p: route)   printf("%d ",p);
        printf("\n");
    }
    return 0;
}
