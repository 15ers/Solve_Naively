#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int n;
    scanf("%d",&n);
    int arr[16][16];
    for(int i=0;i<n;i++)    for(int j=0;j<n;j++)    scanf("%d",&arr[i][j]);
    int ans=0;
    queue<P> q;
    q.push({0,1});
    while(!q.empty()){
        int s=q.front().first,e=q.front().second;
        q.pop();
        int sr=s/n,sc=s%n,er=e/n,ec=e%n;
        if((sr==n-1&&sc==n-1) || (er==n-1&&ec==n-1))    ans++;
        else{
            int nr,nc,nnr,nnc,nnnr,nnnc;
            bool nnflag=true,nnnflag=true;
            if(sr==er){
               nr = er;
               nc = ec+1;
               nnr = er+1;
               nnc = ec+1;
               if(nnr<1 || nnr>= n || nnc<1 || nnc>=n)  nnflag = false;
               if(nnflag)   if(arr[nnr][nnc-1] || arr[nnr-1][nnc])   nnflag = false;
            }
            else if(sc==ec){
                nr = er+1;
                nc = ec;
                nnr = er+1;
                nnc = ec+1;
                if(nnr<1 || nnr>= n || nnc<1 || nnc>=n)  nnflag = false;
                if(nnflag)  if(arr[nnr][nnc-1] || arr[nnr-1][nnc])    nnflag = false;
            }
            else{
                nr = er;
                nc = ec+1;
                nnr = er+1;
                nnc = ec;
                nnnr = er+1;
                nnnc = ec+1;
                if(nnr<0 || nnr>= n || nnc<0 || nnc>=n)  nnflag = false;
                if(nnnr<1 || nnnr>=n || nnnc<1 || nnnc>=n)  nnnflag = false;
                if(nnnflag) if(arr[nnnr][nnnc-1] || arr[nnnr-1][nnnc])    nnnflag = false;
                if(nnnflag && !arr[nnnr][nnnc])  q.push({er*n+ec,nnnr*n+nnnc});
            }
            if(0<=nr&&nr<n && 0<=nc&&nc<n && !arr[nr][nc])  q.push({er*n+ec,nr*n+nc});
            if(nnflag && !arr[nnr][nnc])    q.push({er*n+ec,nnr*n+nnc});
        }
    }
    printf("%d\n",ans);
    
    return 0;
}
