#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n;
    scanf("%d %d",&k,&n);
    vector<int> arr(k);
    long long left=1,right;
    for(int &p:arr){
        scanf("%d",&p);
        right = right>p ? right : p;
    }
    right++;
    while(left+1<right){
        long long mid=(left+right)/2;
        long long s=0;
        for(int p:arr)  s += p/mid;
        if(s>=n) left = mid;
        else    right = mid;
    }
    printf("%lld\n",left);

    return 0;
}
