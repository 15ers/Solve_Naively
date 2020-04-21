#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int &p: arr)    cin >> p;
        int cnt=0;
        for(int i=1;i<n-1;i++)  if(arr[i-1]<arr[i] && arr[i]>arr[i+1])  cnt++;

        printf("Case #%d: %d\n",tc,cnt);
    }
    return 0;
}
