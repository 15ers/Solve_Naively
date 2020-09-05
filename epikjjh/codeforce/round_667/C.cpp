#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
        int diff=y-x;
        int div=n-1;
        while(diff%div) div--;
        int dist=diff/div;
        for(int i=0;i<=div;i++)  printf("%d ",x+i*dist);
        int lc=0;
        for(int i=1;i<=n-1-div;i++){
            if(x-i*dist>0){
                printf("%d ",x-i*dist);
                lc++;
            }
            else    printf("%d ",y+(i-lc)*dist);
        }
        printf("\n");
    }

    return 0;
}
