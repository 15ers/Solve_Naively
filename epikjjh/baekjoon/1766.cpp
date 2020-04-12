#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> indegree(n+1);
    vector<vector<int>> adj(n+1);
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
        indegree[b]++;
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=1;i<=n;i++)   if(!indegree[i])    pq.push(i);
    while(!pq.empty()){
        int cur=pq.top();
        pq.pop();
        cout << cur << " ";
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  pq.push(nxt);
    }

    return 0;
}
