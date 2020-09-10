#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(scanf("%d",&n), n!=0){
        vector<int> arr(n+1);
        for(int i=0;i<n;i++)  scanf("%d",&arr[i]);
        long long ret=0;
        stack<int> inc;
        for(int i=0;i<=n;i++){
            while(!inc.empty() && arr[inc.top()]>arr[i]){
                int cur=inc.top();
                int curh=arr[cur];
                inc.pop();
                int curw = inc.empty() ? i : i-inc.top()-1;
                ret = max(ret,1LL*curh*curw);
            }
            inc.push(i);
        }
        printf("%lld\n",ret);
    }

    return 0;
}
