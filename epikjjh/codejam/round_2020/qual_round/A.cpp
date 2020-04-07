#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        int arr[100][100];
        for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    scanf("%d",&arr[i][j]);
        int s=0,r=0,c=0;
        for(int i=0;i<n;i++)    s += arr[i][i];
        for(int i=0;i<n;i++){
            set<int> rt,ct;
            for(int j=0;j<n;j++)    rt.insert(arr[i][j]);
            for(int j=0;j<n;j++)    ct.insert(arr[j][i]);
            if(rt.size()!=n)    r++;
            if(ct.size()!=n)    c++;
        }

        printf("Case #%d: %d %d %d\n",i,s,r,c);
    }

    return 0;
}
