#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int &e: arr)    scanf("%d", &e);
        int max_num=-1;
        int ret=0;
        for(int i=0;i<n;i++){
            if(arr[i]>max_num){
                if(i==n-1)  ret++;
                else    if(arr[i]>arr[i+1]) ret++;
            }
            max_num = max(max_num,arr[i]);
        }

        printf("Case #%d: %d\n",tc,ret);
    }

    return 0;
}
