#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

char arr[1000][1000];
bool visited[1000][1000];

int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

int main(){
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    vector<int> sp(p+1);
    vector<queue<P>> vq(p+1);
    for(int i=1;i<=p;i++)   scanf("%d",&sp[i]);
    for(int i=0;i<n;i++){
        getchar();
        for(int j=0;j<m;j++){
            scanf("%1c",&arr[i][j]);
            if(arr[i][j]=='#' || arr[i][j]=='.')    continue;
            visited[i][j] = true;
            vq[arr[i][j]-'0'].push({0,i*m+j});
        }
    }
    bool flag=true;
    int round=1;
    while(flag){ 
        flag = false;
        for(int i=1;i<=p;i++){
            while(!vq[i].empty()){
                int d=vq[i].front().first;
                int r=vq[i].front().second/m;
                int c=vq[i].front().second%m;
                if(d==sp[i]*round)    break;
                vq[i].pop();
                for(int j=0;j<4;j++){
                    int nr=r+dr[j];
                    int nc=c+dc[j];
                    if(nr<0 || nr>=n || nc<0 || nc>=m)  continue;
                    if(visited[nr][nc]) continue;
                    if(arr[nr][nc]!='.')    continue;
                    visited[nr][nc] = true;
                    arr[nr][nc] = i+'0';
                    vq[i].push({d+1,nr*m+nc});
                }
            }
            flag |= !vq[i].empty();
        }
        round++;
    }

    vector<int> ret(p+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='#' || arr[i][j]=='.')  continue;
            ret[arr[i][j]-'0']++;
        }
    }
    for(int i=1;i<=p;i++)   printf("%d ",ret[i]);
    printf("\n");

    return 0;
}
