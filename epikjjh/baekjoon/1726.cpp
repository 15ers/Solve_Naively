#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool visited[5][100][100];

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=0;i<m;i++)    for(int j=0;j<n;j++)    scanf("%d",&arr[i][j]);
    int sr,sc,sd,fr,fc,fd;
    scanf("%d %d %d %d %d %d",&sr,&sc,&sd,&fr,&fc,&fd);
    sr--;sc--;fr--;fc--;
    queue<int> q;
    q.push(sd*m*n+sr*n+sc);
    visited[sd][sr][sc] = true;
    int ret=0;
    while(!q.empty()){
        int s = q.size();
        for(int i=0;i<s;i++){
            int cd = q.front()/(m*n);
            int cr = q.front()%(m*n)/n;
            int cc = q.front()%(m*n)%n;
            q.pop();
            if(cd==fd && cr==fr && cc==fc){
                printf("%d\n",ret);
                return 0;
            }
            int dr,dc,left,right;
            switch(cd){
                case 1:
                    dr = 0;
                    dc = 1;
                    left = 4;
                    right = 3;
                    break;
                case 2:
                    dr = 0;
                    dc = -1;
                    left = 3;
                    right = 4; 
                    break;
                case 3:
                    dr = 1;
                    dc = 0;
                    left = 1;
                    right = 2;
                    break;
                case 4:
                    dr = -1;
                    dc = 0;
                    left = 2;
                    right = 1;
                    break;
                default:    break;    
            }
            for(int j=1;j<=3;j++){
                int nr=cr+dr*j;
                int nc=cc+dc*j;
                if(nr<0 || nr>=m || nc<0 || nc>=n)  break;
                if(arr[nr][nc]) break;
                if(!visited[cd][nr][nc]){
                    visited[cd][nr][nc] = true;
                    q.push(cd*m*n+nr*n+nc);
                }
            }
            if(!visited[left][cr][cc]){
                visited[left][cr][cc] = true;
                q.push(left*m*n+cr*n+cc);
            }
            if(!visited[right][cr][cc]){
                visited[right][cr][cc] = true;
                q.push(right*m*n+cr*n+cc);
            }
        }
        ret++;
    }

    return 0;
}
