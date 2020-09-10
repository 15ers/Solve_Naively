#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    vector<int> ret(n);
    for(int i=0;i<n;i++)    ret[i] = n-i-1;
    stack<int> nxt;
    for(int &cur: arr)  scanf("%d",&cur);
    for(int i=0;i<n;i++){
        while(!nxt.empty() && arr[nxt.top()]<=arr[i]){
            int tmp=nxt.top();
            nxt.pop();
            ret[tmp] = i-tmp-1;
        }
        nxt.push(i);
    }
    long long ans=0;
    for(int i=0;i<n;i++)    ans += 1LL*ret[i];
    printf("%lld\n",ans);

    return 0;
}
