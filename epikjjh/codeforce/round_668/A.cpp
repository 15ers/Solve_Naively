#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int &cur: arr)  scanf("%d",&cur);
        reverse(arr.begin(),arr.end());
        for(int &cur: arr)  printf("%d ",cur);
        printf("\n");
    }

    return 0;
}
