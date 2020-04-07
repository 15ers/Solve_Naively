#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    vector<int> arr(n);
    for(int &p: arr)    scanf("%d",&p);
    sort(arr.begin(),arr.end());
    int ret=1;
    for(int i=0;i<n;){
        int r=arr[i]+l-1;
        bool flag=true;
        for(int j=i+1;j<n;j++){
            if(r<arr[j]){
                i = j;
                flag = false;
                break;
            }
        }
        if(flag)    break;
        ret++;
    }
    printf("%d\n",ret);
    return 0;
}
