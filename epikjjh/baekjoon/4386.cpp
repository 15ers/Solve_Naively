#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int p[101];

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
    int n;
    memset(p,-1,sizeof(p));
    scanf("%d",&n);
    vector<pair<double,double>> cords(n);
    for(auto &cord: cords){
        scanf("%lf %lf",&cord.first,&cord.second);
    }
    vector<pair<double,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            double dist=sqrt(pow(cords[i].first-cords[j].first,2) + pow(cords[i].second-cords[j].second,2));
            edges.push_back({dist,{i+1,j+1}});
        }
    }
    sort(edges.begin(),edges.end());
    int cnt=0;
    double ret=0;
    for(auto &edge: edges){
        int a=edge.second.first,b=edge.second.second;
        double c=edge.first;
        if(find(a)==find(b))    continue;
        if(cnt==n-1)    break;
        ret += c;
        cnt++;
        join(a,b);
    }
    printf("%lf\n",ret);

    return 0;
}
