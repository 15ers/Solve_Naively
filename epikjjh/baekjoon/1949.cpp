#include <bits/stdc++.h>

using namespace std;

vector<int> score;
vector<vector<int>> adj;
vector<vector<int>> tree;
vector<bool> visited;
int dp[10001][2];

int dfs(int cur, int pick){
    visited[cur] = true;
    int &ret=dp[cur][pick];
    if(ret!=-1) return ret;
    if(pick){
        ret = score[cur];
        for(int nxt: tree[cur]){
            ret += dfs(nxt,0);
        }
    }
    else{
        ret = 0;
        for(int nxt: tree[cur]){
            ret += max(dfs(nxt,1),dfs(nxt,0));
        }
    }
    return ret;
}

void make_tree(int cur){
    visited[cur] = true;
    for(int nxt: adj[cur]){
        if(visited[nxt])    continue;
        tree[cur].push_back(nxt);
        make_tree(nxt);
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    adj.resize(n+1);
    tree.resize(n+1);
    visited.resize(n+1);
    score.resize(n+1);

    for(int i=1;i<=n;i++)   scanf("%d",&score[i]);
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    make_tree(1);
    tree[0].push_back(1);
    printf("%d\n",dfs(0,0));

    return 0;
}
