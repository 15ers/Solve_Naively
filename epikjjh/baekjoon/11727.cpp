#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int main(){
    int arr[1001]={0,1,3};
    int n;
    cin >> n;
    for(int i=3;i<=n;i++)   arr[i] = (arr[i-1]%MOD+(2*arr[i-2])%MOD)%MOD;
    cout << arr[n] << endl;

    return 0;
}
