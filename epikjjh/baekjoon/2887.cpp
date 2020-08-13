#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int p[100000];

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

struct cord{
    int x;
    int y;
    int z;
    int num;
};

bool cmp1(cord &a, cord &b){
    return  a.x<b.x;
}
bool cmp2(cord &a, cord &b){
    return  a.y<b.y;
}
bool cmp3(cord &a, cord &b){
    return  a.z<b.z;
}

int main(){
    int n;
    memset(p,-1,sizeof(p));
    scanf("%d",&n);
    vector<cord> cords(n);
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&cords[i].x,&cords[i].y,&cords[i].z);
        cords[i].num = i;
    }
    sort(cords.begin(),cords.end(),cmp1);
    for(int i=0;i<n-1;i++){
        int dist=abs(cords[i].x-cords[i+1].x);
        edges.push_back({dist,{cords[i].num,cords[i+1].num}});
    }
    sort(cords.begin(),cords.end(),cmp2);
    for(int i=0;i<n-1;i++){
        int dist=abs(cords[i].y-cords[i+1].y);
        edges.push_back({dist,{cords[i].num,cords[i+1].num}});
    }
    sort(cords.begin(),cords.end(),cmp3);
    for(int i=0;i<n-1;i++){
        int dist=abs(cords[i].z-cords[i+1].z);
        edges.push_back({dist,{cords[i].num,cords[i+1].num}});
    }
    sort(edges.begin(),edges.end());
    int ret=0,cnt=0;
    for(auto &edge: edges){
        int a=edge.second.first,b=edge.second.second,c=edge.first;
        if(find(a)==find(b))    continue;
        if(cnt==n-1)    break;
        ret += c;
        cnt++;
        join(a,b);
    }
    printf("%d\n",ret);

    return 0;
}
