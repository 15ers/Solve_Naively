#include <bits/stdc++.h>

using namespace std;

int dp[200000][2];
vector<int> score;
vector<vector<int>> tree;
vector<int> cands;

int dfs(int cur, int ispick){
    int &ret=dp[cur][ispick];
    if(ret!=-1) return ret;

    if(ispick)  ret = score[cur];
    else    ret = 0;

    for(int nxt: tree[cur]){
        if(ispick)  ret += dfs(nxt,0);
        else    ret += max(dfs(nxt,1),dfs(nxt,0));
    }

    return ret;
}

void trace(int cur, int ispick){
    if(ispick)  cands.push_back(cur);

    for(int nxt: tree[cur]){
        if(ispick)  trace(nxt,0);
        else{
            if(dp[nxt][0]>dp[nxt][1])   trace(nxt,0);
            else    trace(nxt,1);
        }
    }
}

int main(){
    int n;
    vector<int> v1,v2;
    scanf("%d",&n);
    score.resize(n);
    tree.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int &s: score)   scanf("%d",&s);
    for(int i=1;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        tree[--tmp].push_back(i);
    }
    printf("%d ",dfs(0,1));
    trace(0,1);
    v1.assign(cands.begin(),cands.end());
    sort(v1.begin(),v1.end());

    cands.clear();
    vector<int>().swap(cands);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(0,0));
    trace(0,0);
    v2.assign(cands.begin(),cands.end());
    sort(v2.begin(),v2.end());

    for(int &e: v1)  printf("%d ",e+1);
    printf("-1\n");
    for(int &e: v2)  printf("%d ",e+1);
    printf("-1\n");

    return 0;
}
