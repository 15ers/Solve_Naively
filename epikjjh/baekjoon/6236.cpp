#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int left,right=0;
    vector<int> arr(n);
    for(int &p: arr){
        scanf("%d",&p);
        left = max(left,p);
        right += p;
    }
    left--;
    while(left+1<right){
        int mid=(left+right)/2;
        int s=0,cnt=0;
        for(int p: arr){
            if(s+p>mid){
                s = p;
                cnt++;
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
