#include <bits/stdc++.h>

using namespace std;

int arr[2000];

int main(){
    int n,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d",&arr[i]);
    for(int i=0;i<n;i++){
        vector<int> lis,lds;
        int standard=arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]>standard){
                int idx = lower_bound(lis.begin(),lis.end(),arr[j]) - lis.begin();
                if(idx==lis.size()) lis.push_back(arr[j]);
                else    lis[idx] = arr[j];
            }
            if(arr[j]<standard){
                int idx = lower_bound(lds.begin(),lds.end(),-1*arr[j]) - lds.begin();
                if(idx==lds.size()) lds.push_back(-1*arr[j]);
                else    lds[idx] = -1*arr[j];
            }
        }
        int tmp=lis.size()+lds.size()+1;
        ans = max(ans,tmp);
    }
    printf("%d\n",ans);

    return 0;
}
