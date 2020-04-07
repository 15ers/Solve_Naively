#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

const int INF=987654321;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,w;
        scanf("%d %d %d",&n,&m,&w);
        vector<vector<P>> adj(n+1);
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        while(w--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            adj[a].push_back({b,-1*c});
        }
        vector<bool> visited(n+1);
        bool flag=false;
        for(int k=1;k<=n;k++){
            if(visited[k])  continue;
            visited[k] = true;
            vector<int> dist(n+1,INF);
            dist[k] = 0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(auto &p: adj[j]){
                        int nxt=p.first,d=p.second;
                        if(dist[j]!=INF && dist[nxt]>dist[j]+d){
                            visited[nxt] = true;
                            dist[nxt] = dist[j]+d;
                            if(i==n)    flag = true;
                        }
                    }

                }
            }
            if(flag)    break;
        }
        if(flag)    cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
