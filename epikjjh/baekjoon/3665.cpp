#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d",&n);
        vector<int> arr(n);
        for(int &p: arr)    scanf("%d",&p);
        scanf("%d",&m);
        vector<int> indegree(n+1);
        int rank[501][501];
        memset(rank,0,sizeof(rank));
        for(int i=0;i<n;i++)    for(int j=i+1;j<n;j++)  rank[arr[i]][arr[j]] = 1;
        while(m--){
            int x,y;
            scanf("%d %d",&x,&y);
            swap(rank[x][y],rank[y][x]);
        }
        vector<vector<int>> adj(n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)    continue;
                if(rank[i][j]){
                    adj[i].push_back(j);
                    indegree[j]++;
                }
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++) if(!indegree[i])    q.push(i);
        vector<int> ret;
        bool flag=true;
        while(!q.empty()){
            if(q.size()>1)  flag = false;
            int cur=q.front();
            q.pop();
            ret.push_back(cur);
            for(int nxt: adj[cur])  if(!(--indegree[nxt]))  q.push(nxt);
        }
        if(ret.size()!=n)   printf("IMPOSSIBLE\n");
        else{
            if(!flag)   printf("?\n");
            else{
                for(int p: ret) printf("%d ",p);
                printf("\n");
            }
        }
    }

    return 0;
}
