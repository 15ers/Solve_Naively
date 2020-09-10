#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,l;
    scanf("%d %d",&n,&l);
    vector<int> arr(n);
    for(int &cur: arr)  scanf("%d",&cur);
    deque<pair<int,int>> pre;
    for(int i=0;i<n;i++){
        while(!pre.empty() && pre.front().second<=i-l)   pre.pop_front();
        while(!pre.empty() && pre.back().first>=arr[i])   pre.pop_back();
        pre.push_back({arr[i],i});
        printf("%d ",pre.front().first);
    }
    printf("\n"); 

    return 0;
}
