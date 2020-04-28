#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    unordered_map<string,int> pname;
    unordered_map<int,string> pid;
    for(int i=1;i<=n;i++){
        char tmp[21];
        scanf("%s",tmp);
        pname[string(tmp)] = i;
        pid[i] = tmp;
    }
    while(m--){
        char tmp[21];
        scanf("%s",tmp);
        if('A'<=tmp[0] && tmp[0]<='Z')  printf("%d\n",pname[string(tmp)]);
        else    printf("%s\n",pid[atoi(tmp)].c_str());
    }

    return 0;
}
