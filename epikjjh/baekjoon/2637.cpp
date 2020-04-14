#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> indegree(n+1),outdegree(n+1),ret(n+1);
    vector<vector<P>> adj(n+1);
    ret[n] = 1;
    while(m--){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        adj[x].push_back({y,z});
        indegree[y]++;
        outdegree[x]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)   if(!indegree[i])    q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto p: adj[cur]){
            int nxt=p.first,cost=p.second;
            ret[nxt] += ret[cur]*cost;
            if(!(--indegree[nxt]))  q.push(nxt);
        }
    }
    for(int i=1;i<=n;i++)   if(!outdegree[i])   printf("%d %d\n",i,ret[i]);

    return 0;
}
