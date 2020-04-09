#include <bits/stdc++.h>

using namespace std;

int indegree[10];

int main(){
    int n;
    cin >> n;
    vector<char> op(n);
    vector<vector<int>> adj(n+1);
    for(auto &p: op)    cin >> p;
    for(int i=0;i<n;i++){
        if(op[i]=='<'){
            indegree[i]++;
            adj[i+1].push_back(i);
        }
        else{
            indegree[i+1]++;
            adj[i].push_back(i+1);
        }
    }
    int tmp[10];
    copy(indegree,indegree+10,tmp);
    priority_queue<int,vector<int>,greater<int>> max_pq;
    vector<int> max_ret(n+1),min_ret(n+1);
    for(int i=0;i<=n;i++)   if(!indegree[i])    max_pq.push(i);
    int tar=9;
    while(!max_pq.empty()){
        int cur=max_pq.top();
        max_pq.pop();
        max_ret[cur] = tar--;
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  max_pq.push(nxt);
    }
    copy(tmp,tmp+10,indegree);
    priority_queue<int> min_pq;
    for(int i=0;i<=n;i++)   if(!indegree[i])    min_pq.push(i);
    tar=n;
    while(!min_pq.empty()){
        int cur=min_pq.top();
        min_pq.pop();
        min_ret[cur] = tar--;
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  min_pq.push(nxt);
    }
    for(int p: max_ret) cout << p;
    cout << endl;
    for(int p: min_ret) cout << p;
    cout << endl;
}
