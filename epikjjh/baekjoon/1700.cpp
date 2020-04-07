#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> plug(n,-1),seq(k);
    for(int &p: seq)    cin >> p;
    int ret=0,idx=0;
    for(int i=0;i<k;i++){
        bool flag=false;
        for(int &p: plug){
            if(p==-1){
                p = seq[i];
                flag = true;
                break;
            }
            else if(p==seq[i]){
                flag = true;
                break;
            }
        }
        if(flag)    continue;
        map<int,int> idx_dict;
        for(int p : plug)   idx_dict.insert({p,-1});
        for(int j=i;j<k;j++)    if(idx_dict.find(seq[j])!=idx_dict.end() && idx_dict[seq[j]]==-1)    idx_dict[seq[j]] = j;
        int tar=-1,max_idx=-1,max_elem=-1;
        for(auto p: idx_dict){
            if(p.second==-1){
                tar = p.first;
                break;
            }
            if(p.second>max_elem){
                max_elem = p.second;
                max_idx = p.first;
            }
        }
        if(tar==-1) tar = max_idx;
        for(int &p: plug){
            if(p==tar){
                p = seq[i];
                break;
            }
        }
        ret++;
    }
    cout << ret << endl;

    return 0;
}
