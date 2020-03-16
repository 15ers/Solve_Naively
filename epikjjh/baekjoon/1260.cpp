#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[1001];

void dfs(int cur){
    visited[cur] = true;
    printf("%d ",cur);
    for(int nxt: adj[cur])  if(!visited[nxt])   dfs(nxt);
}

int main(){
    int n,m,v;
    scanf("%d %d %d",&n,&m,&v);
    adj.resize(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)   sort(adj[i].begin(),adj[i].end());
    dfs(v);
    printf("\n");
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        printf("%d ",cur);
        for(int nxt: adj[cur]){
            if(!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    printf("\n");

    return 0;
}
