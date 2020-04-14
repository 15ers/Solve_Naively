#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<P>> adj(n+1),radj(n+1);
    vector<int> indegree(n+1),outdegree(n+1);
    while(m--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
        indegree[b]++;
    }
    int s,e;
    scanf("%d %d",&s,&e);
    vector<int> ret(n+1);
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto p: adj[cur]){
            int nxt=p.first,cost=p.second;
            ret[nxt] = max(ret[nxt],ret[cur]+cost);
            if(!(--indegree[nxt]))  q.push(nxt);
        }
    }
    cout << ret[e] << endl;
    int cnt=0;
    vector<int> visited(n+1);
    visited[e] = true;
    q.push(e);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto p: radj[cur]){
            int nxt=p.first,cost=p.second;
            if(cost==ret[cur]-ret[nxt]){
                if(!visited[nxt]){
                    visited[nxt] = true;
                    q.push(nxt);
                }
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}
