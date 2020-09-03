#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
    int p,q;
    Point(int x1, int y1): x(x1), y(y1), p(0), q(0){} 
    bool operator <(const Point& tar){
        if(1LL*q*tar.p != 1LL*p*tar.q)  return 1LL*q*tar.p < 1LL*p*tar.q;
        if(y != tar.y)  return y < tar.y;
        return x < tar.x;
    }
};

long long ccw(const Point& a, const Point& b, const Point &c){
    return 1LL*(b.x-a.x)*(c.y-a.y)-1LL*(b.y-a.y)*(c.x-a.x);
}

double get_dist(const Point& a, const Point& b){
    return sqrt(pow((double)a.x-b.x,2)+pow((double)a.y-b.y,2));
}

int main(){
    int n;
    scanf("%d",&n);
    vector<Point> arr;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr.push_back(Point(x,y));
    }

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
    vector<Point> hull;
    while(!s.empty()){
        hull.push_back(arr[s.top()]);
        s.pop();
    }
    double ret=0;
    for(int i=0;i<hull.size();i++){
        for(int j=i+1;j<hull.size();j++){
            double cur=get_dist(hull[i],hull[j]);
            ret = max(ret,cur);
        }
    }
    printf("%lf\n",ret);

    return 0;
}
