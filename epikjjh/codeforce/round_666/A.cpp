#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++){
            char tmp[1001];
            scanf("%s",tmp);
            string tmps(tmp);
            for(int j=0;j<tmps.size();j++)  hash[tmps[j]]++;
        }
        bool flag = true;
        for(auto& it: hash){
            if(it.second%n){
                flag = false;
                break;
            }
        }
        if(flag)    printf("YES\n");
        else    printf("NO\n");
    }

    return 0;
}
