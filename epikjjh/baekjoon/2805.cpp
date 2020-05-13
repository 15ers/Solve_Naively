#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> trees(n);
    int low=0,high=1000000001;
    for(int &p: trees)  scanf("%d",&p);
    while(low+1<high){
        int mid = (low+high)/2;
        long long sums=0;
        for(int p: trees)   sums += (p-mid)>0 ? p-mid : 0;
        if(sums>=m)   low = mid;
        else    high = mid;
    }
    printf("%d\n",low);

    return 0;
}
