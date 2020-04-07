#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n),diff(n-1);
    for(int &p: arr)    cin >> p;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-1;i++)  diff[i] = arr[i+1]-arr[i];
    sort(diff.begin(),diff.end(),greater<int>());
    int ret=0;
    for(int i=k-1;i<n-1;i++)  ret += diff[i];
    cout << ret << endl;

    return 0;
}
