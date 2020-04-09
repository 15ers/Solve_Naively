#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int p[200000];

int find(int n){
    if(p[n]<0)  return n;
    return p[n] = find(p[n]);
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)    return false;
    if(abs(p[a])<abs(p[b])) swap(a,b);
    p[a] += p[b];
    p[b] = a;
    return true;
}

int main(){
    int m,n;
    while(scanf("%d %d",&m,&n), m||n){
        memset(p,-1,sizeof(p));
        int total=0,x,y,z;
        vector<pair<int,P>> edges;
        while(n--){
            scanf("%d %d %d",&x,&y,&z);
            edges.push_back({z,{x,y}});
            total += z;
        }
        sort(edges.begin(),edges.end());
        int cnt=0,ret=0;
        for(auto edge: edges){
            if(cnt==m-1)    break;
            int a=edge.second.first,b=edge.second.second,d=edge.first;
            if(merge(a,b)){
                cnt++;
                ret += d;
            }
        }
        printf("%d\n",total-ret);
    }
    return 0;
}
