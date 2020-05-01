#include <bits/stdc++.h>

using namespace std;

int dp[1000];
int n;
vector<int> arr;

int dfs(int index){
    int &ret=dp[index];
    if(ret!=-1) return ret;
    ret = 1;
    for(int nxt=index+1;nxt<n;nxt++){
        if(arr[nxt]>arr[index]) ret = max(ret,dfs(nxt)+1);
    }
    return ret;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    arr.resize(n);
    for(int &p: arr)    cin >> p;
    int ret=0;
    for(int i=0;i<n;i++)    ret = max(ret,dfs(i));
    cout << ret << endl;

    return 0;
}
