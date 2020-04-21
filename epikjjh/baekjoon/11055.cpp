#include <bits/stdc++.h>

using namespace std;

int arr[1000],dp[1000][1001];
int n;

int dfs(int index, int val){
    if(index>=n)    return 0;
    int &ret=dp[index][val];
    if(ret!=-1)   return ret;
    if(arr[index]>val)  return ret = max(dfs(index+1,val),dfs(index+1,arr[index])+arr[index]);
    else    return ret = dfs(index+1,val);
}

int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++)    cin >> arr[i];
    cout << dfs(0,0) << endl;

    return 0;
}
