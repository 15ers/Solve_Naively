#include <bits/stdc++.h>

using namespace std;

int p[100001];

int find(int a){
    if(p[a]<0)  return a;
    return p[a] = find(p[a]);
}

void join(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)    return;
    if(abs(p[a])<abs(p[b])) swap(a,b);
    p[a] += p[b];
    p[b] = a;
}


int main(){
    int n,m;
    memset(p,-1,sizeof(p));
    scanf("%d %d",&n,&m);
    vector<pair<int,pair<int,int>>> edges(m);
    for(auto &edge: edges){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        edge.first = c;
        edge.second.first = a;
        edge.second.second = b;
    }
    sort(edges.begin(),edges.end());
    int cnt=0;
    long long ret=0;
    for(auto &edge: edges){
        int a=edge.second.first,b=edge.second.second,c=edge.first;
        if(find(a)==find(b))    continue;
        if(cnt==n-2)    break;
        ret += c;
        cnt++;
        join(a,b);
    }
    printf("%lld\n",ret);

    return 0;
}
