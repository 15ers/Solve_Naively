#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k,ret=0;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &p: arr)    cin >> p;
    for(int i=n-1;i>=0;i--){
        if(k/arr[i]){
            ret += k/arr[i];
            k %= arr[i];
        }
    }
    cout << ret << endl;

    return 0;
}
