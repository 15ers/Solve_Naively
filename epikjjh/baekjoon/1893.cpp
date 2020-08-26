#include <bits/stdc++.h>

using namespace std;

int fail[50000];

void make_table(string tar){
    memset(fail,0,sizeof(fail));
    for(int i=1,j=0;i<tar.size();i++){
        while(j>0 && tar[i]!=tar[j]) j = fail[j-1];
        if(tar[i]==tar[j])  fail[i] = ++j;
    }
}

int match(string source, string tar){
    int cnt=0;
    make_table(tar);
    for(int i=0,j=0;i<source.size();i++){
        while(j>0 && source[i]!=tar[j])  j = fail[j-1];
        if(source[i]==tar[j]){
            if(j==tar.size()-1){
                cnt++;
                j = fail[j];
            }
            else j++;
        }
    }
    return cnt;
}


int main(){
    int tc;
    scanf("%d",&tc);
    while(tc--){
        char torder[63],torigin[50001],tcrypt[500001];
        scanf("%s %s %s",torder,torigin,tcrypt);
        string order(torder),origin(torigin),crypt(tcrypt); 
        vector<int> ret;
        for(int i=0;i<order.size();i++){
            unordered_map<char,char> hash;
            for(int j=0;j<order.size();j++) hash[order[j]] = order[(j+i)%order.size()];
            string tar="";
            for(int j=0;j<origin.size();j++)    tar += hash[origin[j]];
            int cnt=match(crypt,tar);
            if(cnt==1)  ret.push_back(i);
        }
        if(ret.empty())   printf("no solution\n");
        else if(ret.size()==1)    printf("unique: %d\n",ret[0]);
        else{
            printf("ambiguous: ");
            for(int e: ret) printf("%d ",e);
            printf("\n");
        }
    }

    return 0;
}
