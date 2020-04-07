#include <bits/stdc++.h>

using namespace std;

int main(){
    int l,p,v,i=0;
    while(scanf("%d %d %d",&l,&p,&v),l&&p&&v)   printf("Case %d: %d\n",++i,(v/p)*l+min(l,(v%p)));
}
