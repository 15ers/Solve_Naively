#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr(n);
    vector<int> ret(n,-1);
    stack<int> nxt;
    for(int &cur: arr)  scanf("%d",&cur);
    for(int i=0;i<n;i++){
        while(!nxt.empty() && arr[nxt.top()]<arr[i]){
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
