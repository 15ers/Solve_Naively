#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        long long n,d;
        scanf("%lld %lld",&n,&d);
        vector<long long> arr(n);
        for(long long &p: arr)    scanf("%lld",&p);
        vector<long long> ans(n);
        ans[n-1] = d%arr[n-1];
        for(int i=n-2;i>=0;i--){
            long long tmp=d%arr[i];
            if(tmp<ans[i+1])    tmp += (ans[i+1]/arr[i])*arr[i];
            if(tmp<ans[i+1])    tmp += arr[i];
            ans[i] = tmp;
        }
        printf("Case #%d: %lld\n",tc,d-ans[0]);
    }

    return 0;
}
