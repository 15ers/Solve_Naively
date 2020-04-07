#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int l,n,rf,rb;
    scanf("%d %d %d %d",&l,&n,&rf,&rb);
    int d=rf-rb;
    vector<P> arr(n);
    for(auto &p: arr)   scanf("%d %d",&p.second,&p.first);
    sort(arr.begin(),arr.end(),greater<P>());
    long long ret=0,prev=0;
    for(auto &p: arr){
        int loc=p.second,val=p.first;
        if(prev>loc)    continue;
        ret += 1LL*(loc-prev)*val*d;
        prev = loc;
    }
    printf("%lld\n",ret);

    return 0;
}
