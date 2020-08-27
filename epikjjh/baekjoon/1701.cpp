#include <bits/stdc++.h>

using namespace std;

int main(){
    char tmp[5001];
    int fail[5001],ret=0;
    scanf("%s",tmp);
    string total(tmp);
    for(int i=0;i<total.size();i++){
        string tar=total.substr(i);
        memset(fail,0,sizeof(fail));
        for(int j=1,k=0;j<tar.size();j++){
            while(k>0 && tar[j]!=tar[k])    k = fail[k-1];
            if(tar[j]==tar[k])  fail[j] = ++k;
        }
        for(int j=0;j<tar.size();j++)   ret = max(ret,fail[j]);
    }
    printf("%d\n",ret);
    return 0;
}
