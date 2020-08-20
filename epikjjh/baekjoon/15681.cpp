#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> dp;
vector<bool> visited;

int dfs(int cur){
    if(dp[cur]!=-1) return dp[cur]; 
    int ret=1;
    visited[cur] = true;
    for(int nxt: tree[cur]){
        if(visited[nxt])    continue;
        ret += dfs(nxt);
    }
    return dp[cur]=ret;
}

int main(){
    int n,r,q;
    scanf("%d %d %d",&n,&r,&q);
    dp.resize(n+1,-1);
    visited.resize(n+1);
    tree.resize(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(r);
    while(q--){
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",dp[tmp]);
    }

    return 0;
}
