#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
    int p,q;
    Point(): x(0), y(0), p(0), q(0){} 
    bool operator <(const Point& tar){
        if(1LL*q*tar.p != 1LL*p*tar.q)  return 1LL*q*tar.p < 1LL*p*tar.q;
        if(y != tar.y)  return y < tar.y;
        return x < tar.x;
    }
};

long long ccw(int x1, int y1, int x2, int y2, int x3, int y3){
    return 1LL*((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1));
}

int main(){
    int n;
    scanf("%d",&n);
    vector<Point> arr(n);
    for(auto &cur: arr) scanf("%d %d",&cur.x,&cur.y);
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
            if(ccw(arr[first].x,arr[first].y,arr[second].x,arr[second].y,arr[nxt].x,arr[nxt].y)>0){
                s.push(second);
                break;
            }
        }
        s.push(nxt++);
    }
    printf("%d\n",s.size());

    return 0;
}
