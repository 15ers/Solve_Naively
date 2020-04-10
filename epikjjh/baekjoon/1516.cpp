#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int n;
    scanf("%d",&n);
    vector<vector<int>> adj(n+1);
    vector<int> ret(n+1);
    int indegree[501];
    memset(indegree,0,sizeof(indegree));
    for(int i=1;i<=n;i++){
        int c,pre;
        scanf("%d",&c);
        ret[i] = c;
        while(scanf("%d",&pre),pre!=-1){
            adj[pre].push_back(i);
            indegree[i]++;
        }
    }
    priority_queue<P,vector<P>,greater<P>> pq;
    for(int i=1;i<=n;i++)   if(!indegree[i])    pq.push({ret[i],i});
    while(!pq.empty()){
        int cur=pq.top().second;
        pq.pop();
        for(int nxt: adj[cur]){
            if(!(--indegree[nxt])){
                ret[nxt] += ret[cur];
                pq.push({ret[nxt],nxt});
            }
        }
    }
    for(int i=1;i<=n;i++)   printf("%d\n",ret[i]);

    return 0;
}
