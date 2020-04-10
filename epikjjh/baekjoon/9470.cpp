#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int k,m,p;
        scanf("%d %d %d",&k,&m,&p);
        vector<int> indegree(m+1);
        vector<P> ret(m+1);
        vector<vector<int>> adj(m+1);
        while(p--){
            int a,b;
            scanf("%d %d",&a,&b);
            indegree[b]++;
            adj[a].push_back(b);
        }
        queue<int> q;
        for(int i=1;i<=m;i++){
            if(!indegree[i]){
                ret[i].first = 1;
                q.push(i);
            }
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(int nxt: adj[cur]){
                if(!(--indegree[nxt]))  q.push(nxt);
                if(ret[nxt].first<ret[cur].first){
                    ret[nxt].first = ret[cur].first;
                    ret[nxt].second = 1;
                }
                else if(ret[nxt].first==ret[cur].first){
                    if(ret[nxt].second==1){
                        ret[nxt].first = ret[cur].first+1;
                        ret[nxt].second++;
                    }
                    else    ret[nxt].second++;
                }
            }
        }
        printf("%d %d\n",k,ret[m].first);
    }
    
    return 0;
}
