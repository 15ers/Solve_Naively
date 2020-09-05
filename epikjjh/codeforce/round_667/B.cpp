#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,x,y,n;
        scanf("%d %d %d %d %d",&a,&b,&x,&y,&n);
        long long ret=LLONG_MAX;
        if(a-x+b-y<n)   printf("%lld\n", 1LL*x*y);
        else{
            int na1=x,nb1=b-(n-(a-x));
            while(nb1>b){
                nb1--;
                na1++;
            }
            int na2=a-(n-(b-y)),nb2=y;
            while(na2>a){
                na2--;
                nb2++;
            }
            printf("%lld\n",min(1LL*na1*nb1,1LL*na2*nb2)); 
        }
    }

    return 0;
}
