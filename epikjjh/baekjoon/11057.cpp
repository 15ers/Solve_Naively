#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[1001][10];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<10;i++)   arr[1][i] = 1;
    for(int i=2;i<=n;i++)   for(int j=0;j<10;j++)   for(int k=0;k<=j;k++)   arr[i][j] = (arr[i][j]+arr[i-1][k])%MOD;
    int ret=0;
    for(int i=0;i<10;i++)   ret = (ret+arr[n][i])%MOD;
    cout << ret << endl;

    return 0;
}
