#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> indegree(n+1);
    vector<vector<int>> adj(n+1);
    while(m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)   if(!indegree[i])    q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout << cur << " ";
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  q.push(nxt);
    }

    return 0;
}
