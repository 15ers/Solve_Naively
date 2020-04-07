#include <bits/stdc++.h>

using namespace std;

int main(){
    int ret=0,incor=0,time=0;
    int arr[11];
    for(int i=0;i<11;i++){
        int v,d;
        scanf("%d %d",&v,&d);
        arr[i] = v;
        incor += d;
    }
    sort(arr,arr+11);
    for(int i=0;i<11;i++){
        time += arr[i];
        ret += time;
    }
    printf("%d\n",ret+20*incor);
    return 0;
}
