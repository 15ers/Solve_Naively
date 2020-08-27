#include <bits/stdc++.h>

using namespace std;

int fail[1000000];

int gcd(int a, int b){
    int r;
    while(b){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void make_table(string tar){
    int n=tar.size();
    for(int i=1,j=0;i<n;i++){
        while(j>0 && tar[i]!=tar[j])    j = fail[j-1];
        if(tar[i]==tar[j])  fail[i] = ++j;
    }
}

int find(string source, string tar){
    make_table(tar);
    int n=source.size(),m=tar.size(),cnt=0;
    for(int i=0,j=0;i<n;i++){
        while(j>0 && source[i]!=tar[j])  j = fail[j-1];
        if(source[i]==tar[j]){
            if(j==m-1){
                cnt++;
                j = fail[j];
            }
            else    j++;
        }
    }
    return cnt;
}

int main(){
    string source="",tar="";
    int n;
    char tmp;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c",&tmp); 
        tar += tmp;
    }
    for(int i=0;i<n;i++){
        getchar();
        scanf("%c",&tmp); 
        source += tmp;
    }
    for(int i=0;i<n-1;i++)  source += source[i];
    int ret=find(source,tar);
    int g=gcd(ret,n);
    printf("%d/%d\n",ret/g,n/g);

    return 0;
}
