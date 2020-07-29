#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    scanf("%d",&n);
    vector<pair<ll,ll>> vec(n);
    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        vec[i] = {x,y};
    }
    double ret=0;
    for(int i=1;i<n-1;i++)  ret += double(vec[0].first*vec[i].second+vec[i].first*vec[i+1].second+vec[i+1].first*vec[0].second-vec[0].second*vec[i].first-vec[i].second*vec[i+1].first-vec[i+1].second*vec[0].first);
    ret = abs(ret);
    printf("%.1lf",ret/2);

    return 0;
}
