#include <bits/stdc++.h>

using namespace std;

struct info{
    int t;
    int a;
    int h;
};

int main(){
    int n,atk;
    scanf("%d %d",&n,&atk);
    vector<info> arr(n);
    long long left=0,right=0;
    for(auto &p:arr){
        scanf("%d %d %d",&p.t,&p.a,&p.h);
        if(p.t==1)    right += 1LL*(p.h/atk+1)*p.a;
    }
    while(left+1<right){
        bool flag=true;
        long long mid=(left+right)/2;
        long long cur_atk=atk,cur_hp=mid;
        for(auto p:arr){
            if(p.t==1){
                long long cnt=p.h%cur_atk ? p.h/cur_atk : p.h/cur_atk-1;
                if(cnt>=1)  cur_hp -= cnt*p.a;
            }
            else{
                cur_hp = min(cur_hp+p.h,mid);
                cur_atk += p.a;
            }
            if(cur_hp<=0){
                flag = false;
                break;
            }
        }
        if(flag)    right=mid;
        else    left=mid;
    }
    printf("%lld\n",right);
    
    return 0;
}
