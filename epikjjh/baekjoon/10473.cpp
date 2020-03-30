#include <bits/stdc++.h>

using namespace std;

typedef pair<int,double> P;
typedef pair<double,int> P2;

inline double calc(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    int n;
    double x[100],y[100];
    scanf("%lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1]);
    scanf("%d",&n);
    for(int i=2;i<n+2;i++)  scanf("%lf %lf",&x[i],&y[i]);
    vector<vector<P>> adj(n+2);
    vector<double> cost(n+2,calc(x[0],y[0],x[1],y[1])/5.0);
    for(int i=1;i<n+2;i++){
        double d,t;
        d = fabs(calc(x[0],y[0],x[i],y[i]));
        adj[0].push_back({i,d/5.0});
        t = min(fabs(d-50.0)/5.0+2.0,d/5.0);
        if(i==1)    continue;
        adj[i].push_back({0,t});
    }
    for(int i=2;i<n+2;i++){
        double d,t;
        d = fabs(calc(x[1],y[1],x[i],y[i]));
        t = min(fabs(d-50.0)/5.0+2.0,d/5.0);
        adj[i].push_back({1,t});
        for(int j=i+1;j<n+2;j++){
            d = fabs(calc(x[i],y[i],x[j],y[j]));
            t = min(fabs(d-50.0)/5.0+2.0,d/5.0);
            adj[i].push_back({j,t});
            adj[j].push_back({i,t});
        }
    }
    cost[0] = 0.0;
    vector<bool> visited(n+2);
    priority_queue<P2,vector<P2>,greater<P2>> pq;
    pq.push({0.0,0});
    while(!pq.empty()){
        int cur;
        do{
            cur = pq.top().second;
            pq.pop();
        }while(!pq.empty() && visited[cur]);
        if(visited[cur])    break;
        visited[cur] = true;
        for(auto &p: adj[cur]){
            int nxt=p.first;
            double time=p.second;
            if(cost[nxt]>cost[cur]+time){
                cost[nxt] = cost[cur]+time;
                pq.push({cost[nxt],nxt});
            }
        }
    }
    printf("%lf\n",cost[1]);

    return 0;
}
