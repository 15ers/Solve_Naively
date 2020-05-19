#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> arr(n);
    int left=0,right=0;
    for(int &p:arr){
        scanf("%d",&p);
        right += p;
        left = max(left,p);
    }
    left--;
    while(left+1<right){
        int mid=(left+right)/2;
        int s=0,cnt=0;
        for(int p:arr){
            if(s+p>mid){
                cnt++;
                s = p;
            }
            else    s += p;
        }
        if(s)   cnt++;
        if(cnt>m)   left = mid;
        else    right = mid;
    }
    printf("%d\n",right);

    return 0;
}
