#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;
bool visited[10001];
int n;

void dfs(int cur){
    visited[cur] = true;
    for(int nxt: adj[cur])   if(!visited[nxt])   dfs(nxt);
}

int cnt(){
    int ret=0;
    for(int i=1;i<=n;i++)   if(visited[i])  ret++;
    return ret;
}

int main(){
    int m;
    scanf("%d %d",&n,&m);
    adj.resize(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[b].push_back(a);
    }
    vector<int> ret(n+1);
    int max_e=0;
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof(visited));
        dfs(i);
        ret[i] = cnt();
        max_e = max(ret[i],max_e);
    }
    for(int i=1;i<=n;i++)   if(ret[i]==max_e)   printf("%d ",i);
    printf("\n");

    return 0;
}
