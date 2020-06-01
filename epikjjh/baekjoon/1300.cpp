#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    long long left=0,right=1LL*n*n+1;
    while(left+1<right){
        long long mid=(left+right)/2,cnt=0;
        for(int i=1;i<=n;i++)   cnt += min(mid/i,1LL*n);
        if(cnt>=k)   right = mid; 
        else    left = mid;
    }
    printf("%lld\n",right);

    return 0;
}
