#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> arr(n);
    for(string &p: arr) cin >> p;
    string pre="";
    vector<int> indegree(26);
    vector<bool> isin(26);
    vector<vector<int>> adj(26);
    for(string p: arr){
        for(int i=0;i<p.size();i++) isin[p[i]-'a'] = true;
        if(pre!=""){
            int k=min(pre.size(),p.size()),index=-1;
            for(int i=0;i<k;i++){
                if(pre[i]!=p[i]){
                    index=i;
                    break;
                }
            }
            if(index==-1 && pre.size()>p.size()){
                cout << "!" << endl;
                return 0;
            }
            if(index!=-1){
                adj[pre[index]-'a'].push_back(p[index]-'a');
                indegree[p[index]-'a']++;
            }
        }
        pre = p;
    }
    int cnt=0;
    queue<int> q;
    for(int i=0;i<26;i++){
        if(isin[i]){
            if(!indegree[i])    q.push(i);
            cnt++;
        }
    }
    string ret="";
    bool flag=true;
    while(!q.empty()){
        if(q.size()>1)  flag=false;
        int cur=q.front();
        q.pop();
        ret += cur+'a';
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  q.push(nxt);
    }
    if(ret.size()!=cnt) cout << "!" << endl;
    else{
        if(!flag)   cout << "?" << endl;
        else    cout << ret << endl;
    }

    return 0;
}
