#include <bits/stdc++.h>

using namespace std;

int arr[100][100],n,ret=0;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};
bool visited[100][100];

void dfs(int cur, int degree){
    int r=cur/n;
    int c=cur%n;
    visited[r][c] = true;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr<0 || nr>=n || nc<0 || nc>=n)  continue;
        if(visited[nr][nc])     continue;
        if(arr[nr][nc]<=degree) dfs(nr*n+nc,degree);
    }
}
void dfsv(int cur){
    int r=cur/n;
    int c=cur%n;
    visited[r][c] = true;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(nr<0 || nr>=n || nc<0 || nc>=n)  continue;
        if(visited[nr][nc])     continue;
        dfsv(nr*n+nc);
    }
}


int main(){
    scanf("%d",&n);
    int min_d=100,max_d=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int tmp;
            scanf("%d",&tmp);
            arr[i][j] = tmp;
            min_d = min(tmp,min_d);
            max_d = max(tmp,max_d);
        }
    }
    for(int i=min_d-1;i<=max_d;i++){
        memset(visited,0,sizeof(visited));
        int cand=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(!visited[j][k] && arr[j][k]<=i)  dfs(n*j+k,i);
            }
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(!visited[j][k]){
                    dfsv(j*n+k);
                    cand++;
                }
            }
        }
        ret = max(cand,ret);
    }
    printf("%d\n",ret);

    return 0;
}
