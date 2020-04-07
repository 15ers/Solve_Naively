#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
bool cmp(P &left,P &right){
   if(left.second==right.second)    return left.first<right.first;
   else return left.second<right.second;
}

int main(){
    int n;
    scanf("%d",&n);
    vector<P> arr(n);
    for(auto &p: arr)   scanf("%d %d",&p.first,&p.second);
    sort(arr.begin(),arr.end(),cmp);
    int ret=1;
    for(int i=0;i<n;){
        int e=arr[i].second;
        bool flag=true;
        for(int j=i+1;j<n;j++){
            if(arr[j].first>=e){
                flag = false;
                i = j;
                break;
            }
        }
        if(flag)    break;
        ret++;
    }
    cout << ret << endl;
    
    return 0;
}
