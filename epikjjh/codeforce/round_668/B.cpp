#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        long long s=0;
        scanf("%d",&n);
        vector<long long> arr(n);
        for(long long &cur: arr){
            scanf("%lld",&cur);
            s += abs(cur);
        }
        s /= 2;
        long long ret=0,cur=0;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                cur += arr[i];
            }
            else{
                long long diff=min(abs(cur),abs(arr[i]));
                ret += diff;
                cur -= diff;
            }
        }
        printf("%lld\n",s-ret);
    }

    return 0;
}
