#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
int dp[100];

int main(){
    int n;
    cin >> n;
    vector<P> arr(n);
    for(auto &p: arr)   cin >> p.first >> p.second;
    sort(arr.begin(),arr.end());
    int ret=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i].second>arr[j].second) dp[i] = max(dp[i],dp[j]+1);
        }
        if(!dp[i])  dp[i] = 1;
    }
    for(int i=0;i<n;i++)    ret = max(ret,dp[i]);

    cout << n-ret << endl;

    return 0;
}
