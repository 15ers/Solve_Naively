#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[1001];
int n;

void dfs(int cur){
    visited[cur] = true;
    for(int nxt: adj[cur])  if(!visited[nxt])   dfs(nxt);
}

int dfsAll(){
    int ret=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
            ret++;
        }
    }
    return ret;
}

int main(){
    int m;
    scanf("%d %d",&n,&m);
    adj.resize(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    printf("%d\n",dfsAll());

    return 0;
}
