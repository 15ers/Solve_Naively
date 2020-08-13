#include <cstring>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int p[10001];

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
    memset(p,-1,sizeof(p));
    int v,e;
    scanf("%d %d",&v,&e);
    vector<pair<int,pair<int,int>>> edges(e);
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
        if(cnt==v-1)    break;
        ret += c;
        cnt++;
        join(a,b);
    }
    printf("%lld\n",ret);

    return 0;
}
