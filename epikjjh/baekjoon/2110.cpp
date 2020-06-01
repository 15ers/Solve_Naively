#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    vector<int> arr(n);
    for(int &p: arr)    scanf("%d",&p);
    sort(arr.begin(),arr.end());
    long long left=0,right=arr[n-1]-arr[0]+1;
    while(left+1<right){
        int mid=(left+right)/2;
        int cnt=1;
        int cur=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-cur>=mid){
                cnt++;
                cur = arr[i];
            }
        }
        if(cnt>=c)  left = mid;
        else    right = mid;
    }
    printf("%lld\n",left);

    return 0;
}
