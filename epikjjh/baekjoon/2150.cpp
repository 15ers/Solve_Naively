#include <bits/stdc++.h>

using namespace std;
const int MAX = 10000;

vector<vector<int>> adj(MAX+1),scc;
int dfsn[MAX+1],cnt;
bool finished[MAX+1];
stack<int> s;

int dfs(int cur){
    dfsn[cur] = cnt++;
    s.push(cur);
    int ret=dfsn[cur];
    for(int nxt: adj[cur]){
        if(dfsn[nxt]==-1)   ret = min(ret,dfs(nxt));
        else if(!finished[nxt]) ret = min(ret,dfsn[nxt]);
    }
    if(ret==dfsn[cur]){
        vector<int> curscc;
        while(1){
            int tmp = s.top();
            s.pop();
            curscc.push_back(tmp);
            finished[tmp] = true;
            if(tmp==cur)    break;
        }
        sort(curscc.begin(),curscc.end());
        scc.push_back(curscc);
    }

    return ret;
}

int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    memset(dfsn,-1,sizeof(dfsn));
    while(e--){
        int a,b;
        scanf("%d %d",&a,&b);
        adj[a].push_back(b);
    }
    for(int i=1;i<=v;i++)   if(dfsn[i]==-1) dfs(i);
    printf("%lu\n",scc.size());
    sort(scc.begin(),scc.end());
    for(auto &p: scc){
        for(int &c: p)    printf("%d ",c);
        printf("-1\n");
    }    

    return 0;
}
