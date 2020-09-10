#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    unordered_map<int,int> hash;
    vector<int> arr(n),ret(n,-1);
    for(int &cur: arr){
        scanf("%d",&cur);
        if(hash.find(cur) == hash.end())    hash[cur] = 1;
        else    hash[cur] += 1;
    }
    stack<int> nxt;
    for(int i=0;i<n;i++){
        while(!nxt.empty() && hash[arr[nxt.top()]] < hash[arr[i]]){
            int tmp=nxt.top();
            nxt.pop();
            ret[tmp] = arr[i]; 
        }
        nxt.push(i);
    }
    for(int &cur: ret)  printf("%d ",cur);
    printf("\n");

    return 0;
}
