#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int dist[20][20],copied[20][20];
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    scanf("%d",&dist[i][j]);
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    copied[i][j] = dist[i][j];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k==i || k==j)    continue;
                if(dist[i][j]==dist[i][k]+dist[k][j])   copied[i][j] = 0;
                else if(dist[i][j]>dist[i][k]+dist[k][j]){
                    printf("-1\n");
                    return 0;
                }
            }
        }
    }
    int s=0;
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    s += copied[i][j];
    printf("%d\n",s/2);

    return 0;
}
