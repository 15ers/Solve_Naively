#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int arr[1001][1001];

int func(int n,int k){
    if(!k)  return 1;
    if(n==k)    return 1;
    if(arr[n][k]!=-1)   return arr[n][k];
    return arr[n][k] = (func(n-1,k)+func(n-1,k-1))%MOD;
}

int main(){
    int n,k;
    memset(arr,-1,sizeof(arr));
    cin >> n >> k;
    cout << func(n,k) << endl; 
    
    return 0;
}
