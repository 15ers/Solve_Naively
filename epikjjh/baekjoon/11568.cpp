#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];
vector<int> arr;

int dfs(int index){
    int &ret=dp[index+1];
    if(ret!=-1) return ret;
    ret = 0;
    for(int nxt=index+1;nxt<n;nxt++){
        if(index==-1 || arr[index]<arr[nxt])    ret = max(ret,dfs(nxt)+1);
    }

    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    arr.resize(n);
    for(int &p: arr)    cin >> p;
    cout << dfs(-1) << endl;

    return 0;
}
