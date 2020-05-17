#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        int n,k;
        scanf("%d %d",&n,&k);
        vector<int> arr(n);
        for(int &p: arr)    scanf("%d",&p);
        int ans=0,cnt=0,index=n-1;
        while(index>=0){
            if(arr[index]==1){
                int length=1;
                while(arr[index-1]==arr[index]+1){
                    length++;
                    index--;
                }
                if(length>=k)   ans++;
            }
            index--;
        }

        printf("Case #%d: %d\n",tc,ans);
    }

    return 0;
}
