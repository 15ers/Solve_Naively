#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k,tmp;
        scanf("%d %d",&n,&k);
        vector<int> arr(n),left(n),right(n);
        for(int &cur: arr)  scanf("%d",&cur);
        for(int i=0;i<n;i++)    scanf("%d",&tmp);
        sort(arr.begin(),arr.end());
        int j=0;
        for(int i=0;i<n;i++){
            while(arr[i]-arr[j]>k)  j++;
            left[i] = i-j+1;
            if(i!=0)    left[i] = max(left[i],left[i-1]);
        }
        j=n-1;
        for(int i=n-1;i>=0;i--){
            while(arr[j]-arr[i]>k)  j--;
            right[i] = j-i+1;
            if(j!=n-1)  right[i] = max(right[i],right[i+1]);
        }
        int ret=1;
        for(int i=0;i<n-1;i++){
            ret = max(ret,left[i]+right[i+1]);
        }
        printf("%d\n",ret);
    }

    return 0;
}
