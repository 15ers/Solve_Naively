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

int main(){
    int n,px,py;
    scanf("%d",&n);
    scanf("%d %d",&px,&py);
    vector<Point> arr;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        arr.push_back(Point(x,y));
    }

    int ret=0;
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
        bool sign[2]={0},visited[1000]={0};
        s.push(0);
        while(s.size()>1){
            int a=s.top();
            s.pop();
            int b=s.top();
            if(ccw(arr[a],arr[b],Point(px,py))>=0)    sign[1] = true;
            else    sign[0] = true;
            visited[a] = true;
        }
        if(sign[0] && sign[1])  break;
        ret++; 
        vector<Point> arr_tmp;
        for(int i=0;i<n;i++){
            if(!visited[i]) arr_tmp.push_back(Point(arr[i].x,arr[i].y));
        }
        arr = arr_tmp;
        n = arr.size();
    }
    printf("%d\n",ret);

    return 0;
}

