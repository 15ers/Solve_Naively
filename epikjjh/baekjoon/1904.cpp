#include <bits/stdc++.h>
#define MOD 15746

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[1000001]={0,1,2};
    for(int i=3;i<=n;i++)   arr[i] = (arr[i-1]+arr[i-2])%MOD;
    cout << arr[n] << endl;

    return 0;
}
