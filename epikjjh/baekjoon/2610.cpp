#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

vector<vector<int>> adj,dict;
vector<bool> visited;

void dfs(int cur,int idx){
    for(int nxt: adj[cur]){
        if(!visited[nxt]){
            visited[nxt] = true;
            dict[idx].push_back(nxt);
            dfs(nxt,idx);
        }
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)   if(i==j)    dist[i][j] = 0;
    }
    adj.resize(n+1);
    dict.resize(n+1);
    visited.resize(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        dist[a][b] = 1;
        dist[b][a] = 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int k=1;k<=n;k++)    for(int i=1;i<=n;i++)    for(int j=1;j<=n;j++)     dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);

    int ret=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited[i] = true;
            dict[ret].push_back(i);
            dfs(i,ret);
            ret++;
        }
    }
    printf("%d\n",ret);
    vector<int> ret_idx;
    for(int i=0;i<ret;i++){
        int min_val=INF,min_idx=-1;
        for(auto &j: dict[i]){
            int tmp=0;
            for(auto &k: dict[i])  tmp = max(tmp,dist[j][k]);
            if(tmp<min_val){
                min_val = tmp;
                min_idx = j;
            }
        }
        ret_idx.push_back(min_idx);
    }
    sort(ret_idx.begin(),ret_idx.end());
    for(int &p: ret_idx)    printf("%d\n",p);

    return 0;
}
