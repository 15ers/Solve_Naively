#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int cost[401][401];
    for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   cost[i][j] = (i==j) ? 0 : INF; 
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        cost[a][b] = 1;
    }
    for(int k=1;k<=n;k++)   for(int i=1;i<=n;i++)   for(int j=1;j<=n;j++)   cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
    int q;
    scanf("%d",&q);
    while(q--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(cost[a][b]!=INF) printf("-1\n");
        else if(cost[b][a]!=INF)    printf("1\n");
        else    printf("0\n");
    }
    return 0;
}
