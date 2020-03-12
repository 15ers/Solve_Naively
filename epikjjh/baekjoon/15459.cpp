#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

P arr[100000];
long long p[100000];
bool visited[100000];

int find(int n){
    if(p[n]<0)  return n;
    return p[n] = find(p[n]);
}
void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b)    return;
    if(p[a]>p[b])   swap(a,b);
    p[a] += p[b];
    p[b] = a;
}


int main(){
    int n;
    long long m;
    scanf("%d %lld",&n,&m);
    for(int i=0;i<n;i++){
        int f,s;
        scanf("%d %d",&f,&s);
        arr[i] = {s,i};
        p[i] = -f;
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int ind = arr[i].second;
        visited[ind] = true;
        if(ind>0 && visited[ind-1]) merge(ind,ind-1);
        if(ind<n-1 && visited[ind+1])   merge(ind,ind+1);
        if(abs(p[find(ind)])>=m){
            printf("%d\n",arr[i].first);
            break;
        }
    }

    return 0;
}
