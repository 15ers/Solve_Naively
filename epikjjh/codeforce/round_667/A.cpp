#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        int diff=abs(a-b);
        int ret=diff%10 ? diff/10+1 : diff/10;
        printf("%d\n",ret);
    }

    return 0;
}
