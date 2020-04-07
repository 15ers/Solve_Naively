#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> dist(n+1,INF);
    vector<vector<P>> adj(n+1);
    dist[1] = 0;
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(auto &p: adj[j]){
                int nxt=p.first,d=p.second;
                if(dist[j]!=INF && dist[nxt]>dist[j]+d){
                    dist[nxt] = dist[j]+d;
                    if(i==n){
                        printf("-1\n");
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=2;i<=n;i++)   printf("%d\n",(dist[i]==INF) ? -1 : dist[i]);

    return 0;
}
