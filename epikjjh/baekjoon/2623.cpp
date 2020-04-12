#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> indegree(n+1),ret;
    vector<vector<int>> adj(n+1);
    while(m--){
        int num,pre=-1,cur=-1;
        cin >> num;
        while(num--){
            cin >> cur;
            if(pre!=-1){
                adj[pre].push_back(cur);
                indegree[cur]++;
            }
            pre = cur;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)   if(!indegree[i])    q.push(i);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ret.push_back(cur);
        for(int nxt: adj[cur])  if(!(--indegree[nxt]))  q.push(nxt);
    }
    if(ret.size()!=n)   cout << 0 << endl;
    else    for(int p: ret) cout << p << endl;

    return 0;
}
