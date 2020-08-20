#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
int dp[50];

int dfs(int cur){
    int &ret=dp[cur];
    if(ret!=-1) return ret;
    ret=0;
    vector<int> tmp;
    for(int nxt: tree[cur]) tmp.push_back(dfs(nxt));
    sort(tmp.begin(),tmp.end(),greater<int>());
    for(int i=0;i<tmp.size();i++)   ret = max(ret,tmp[i]+i+1);

    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    tree.resize(n);
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==-1) continue;
        tree[tmp].push_back(i);
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n",dfs(0));

    return 0;
}
