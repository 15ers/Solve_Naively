#include <bits/stdc++.h>

using namespace std;

int weight[100],value[100],arr[100][100001];
int n,k;

int func(int index, int w){
    if(index>=n)    return 0;
    int &ret=arr[index][w];
    if(ret!=-1)   return ret;
    if(w<weight[index]) return ret=func(index+1,w);
    else    return ret=max(func(index+1,w),func(index+1,w-weight[index])+value[index]);
}

int main(){
    cin >> n >> k;
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<n;i++)    cin >> weight[i] >> value[i];
    cout << func(0,k) << endl;
    
    return 0;
}
