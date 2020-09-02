#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
    int p,q;
    int ind;
    Point(int x1, int y1, int ind1): x(x1), y(y1), p(0), q(0), ind(ind1){} 
    bool operator <(const Point& tar){
        if(1LL*q*tar.p != 1LL*p*tar.q)  return 1LL*q*tar.p < 1LL*p*tar.q;
        if(y != tar.y)  return y < tar.y;
        return x < tar.x;
    }
};

long long ccw(const Point& a, const Point& b, const Point &c){
    return 1LL*(b.x-a.x)*(c.y-a.y)-1LL*(b.y-a.y)*(c.x-a.x);
}

int main(){
    int n,px,py;
    scanf("%d",&n);
    vector<Point> arr;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr.push_back(Point(x,y,i));
    }
    vector<int> ans(n);
    int ret=1;
    while(n>2){
        sort(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            arr[i].p = arr[i].x - arr[0].x;
            arr[i].q = arr[i].y - arr[0].y;
        }
        sort(arr.begin()+1,arr.end());

        stack<int> s;
        s.push(0);
        s.push(1);
        int nxt=2;
        while(nxt<n){
            while(s.size() >= 2){
                int first,second;
                second = s.top();
                s.pop();
                first = s.top();
                if(ccw(arr[first],arr[second],arr[nxt])>0){
                    s.push(second);
                    break;
                }
            }
            s.push(nxt++);
        }
        if(s.size()<=2) break;

        bool visited[1000]={0};
        while(!s.empty()){
            int t=s.top();
            s.pop();
            visited[t] = true;
            ans[arr[t].ind] = ret;
        }
        vector<Point> arr_tmp;
        for(int i=0;i<n;i++){
            if(!visited[i]) arr_tmp.push_back(Point(arr[i].x,arr[i].y,arr[i].ind));
        }
        arr = arr_tmp;
        n = arr.size();
        ret++; 
    }
    for(int &e: ans)    printf("%d ",e);
    printf("\n");

    return 0;
}

