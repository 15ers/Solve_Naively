#include <bits/stdc++.h>

using namespace std;

struct rule{
    int a;
    int b;
    int c;
};

int main(){
    int n,k,d;
    scanf("%d %d %d",&n,&k,&d);
    int left=0,right=n;
    vector<rule> arr(k);
    for(auto &p: arr)   scanf("%d %d %d",&p.a,&p.b,&p.c);
    while(left+1<right){
        int mid=(left+right)/2;
        long long s=0;
        for(auto &p: arr){
            int tmp=min(mid,p.b);
            if(tmp>=p.a)    s += (tmp-p.a)/p.c + 1;
        }
        if(s>=d)    right = mid;
        else    left = mid;
    }
    printf("%d\n",right);

    return 0;
}
