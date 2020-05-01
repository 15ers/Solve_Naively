#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
bool num[500001];

int main(){
    int n;
    scanf("%d",&n);
    vector<P> arr(n);
    for(auto &p: arr)   scanf("%d %d",&p.first,&p.second);
    sort(arr.begin(),arr.end()); 
    for(auto &p: arr)   num[p.first] = true;
    vector<int> ret,ind(n);
    ret.push_back(arr[0].second);
    ind[0] = 0;
    for(int i=1;i<n;i++){
        if(arr[i].second>ret.back()){
            ret.push_back(arr[i].second);
            ind[i] = ret.size()-1; 
        }
        else{
            int idx = lower_bound(ret.begin(),ret.end(),arr[i].second)-ret.begin();
            ret[idx] = arr[i].second;
            ind[i] = idx; 
        }
    }
    int tar=ret.size()-1;
    for(int i=n-1;i>=0;i--){
        if(ind[i]==tar){
            num[arr[i].first] = false;
            tar--;
        }
    }
    cout << n-ret.size() << endl;
    for(int i=1;i<=500000;i++)  if(num[i])  printf("%d\n",i);

    return 0;
}
