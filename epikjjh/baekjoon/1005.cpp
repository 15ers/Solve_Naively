#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        vector<int> cost(n+1),ret(n+1),indegree(n+1);
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++)   scanf("%d",&cost[i]);
        while(k--){
            int pre,cur;
            scanf("%d %d",&pre,&cur);
            adj[pre].push_back(cur);
            indegree[cur]++;
        }
        queue<int> q;
        for(int i=1;i<=n;i++){
            if(!indegree[i]){
                q.push(i);
                ret[i] = cost[i];
            }
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int nxt: adj[cur]){
                ret[nxt] = max(ret[nxt],cost[nxt]+ret[cur]);
                if(!(--indegree[nxt]))  q.push(nxt);
            }
        }
        int w;
        scanf("%d",&w);
        printf("%d\n",ret[w]);
    }
    
    return 0;
}
