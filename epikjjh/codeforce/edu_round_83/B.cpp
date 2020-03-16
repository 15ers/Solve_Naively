#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int &p: arr)    cin >> p;
        sort(arr.begin(),arr.end(),greater<int>());
        for(int &p: arr)    cout << p << " ";
        cout << endl;
    }

    return 0;
}
