#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        if(n%m) cout << "NO" << endl;
        else    cout << "YES" << endl;
    }

    return 0;
}
