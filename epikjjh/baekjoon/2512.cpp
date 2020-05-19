#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d",&n);
    vector<int> arr(n);
    int left=0,right;
    for(int &p: arr){
        scanf("%d",&p);
        right = max(right,p);
    }
    right++;
    scanf("%d",&m);
    while(left+1<right){
        int mid=(left+right)/2;
        int s=0;
        for(int p: arr) s += min(p,mid);
        if(s>m) right = mid;
        else    left = mid;
    }
    printf("%d\n",left);

    return 0;
}
