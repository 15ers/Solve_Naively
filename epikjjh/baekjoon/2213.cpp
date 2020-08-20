#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
vector<vector<int>> tree;
vector<int> score;
vector<int> cands;
vector<bool> visited;
int dp[10001][2];

void make_tree(int cur){
    visited[cur] = true;
    for(int nxt: adj[cur]){
        if(visited[nxt])    continue;
        tree[cur].push_back(nxt);
        make_tree(nxt);
    }
}

int dfs(int cur, int ispick){
    int &ret = dp[cur][ispick];
    if(ret!=-1) return ret;
    
    ret = ispick ? score[cur] : 0;

    for(int nxt: tree[cur]){
        if(ispick)  ret += dfs(nxt,0);
        else    ret += max(dfs(nxt,0),dfs(nxt,1));
    }
    return ret;
}
void trace(int cur, int ispick){
    if(ispick)  cands.push_back(cur);

    for(int nxt: tree[cur]){
        if(ispick)  trace(nxt,0);
        else{
            if(dp[nxt][0]>=dp[nxt][1])   trace(nxt,0);
            else    trace(nxt,1);
        }
    }
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    adj.resize(n+1);
    tree.resize(n+1);
    score.resize(n+1);
    visited.resize(n+1);
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
    trace(0,0);
    sort(cands.begin(),cands.end());
    for(int &e: cands)  printf("%d ",e);
    printf("\n");

    return 0;
}
