#include <bits/stdc++.h>

using namespace std;

const int INF=987654321;

int main(){
    int v,e;
    scanf("%d %d",&v,&e);
    int dist[401][401];
    for(int i=1;i<=v;i++)   for(int j=1;j<=v;j++)   dist[i][j] = INF;
    while(e--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        dist[a][b] = c;
    }
    for(int k=1;k<=v;k++)   for(int i=1;i<=v;i++)   for(int j=1;j<=v;j++)   dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
    int ret=INF;
    for(int i=1;i<=v;i++)   ret = min(ret,dist[i][i]);
    printf("%d\n",ret==INF ? -1 : ret);

    return 0;
}
