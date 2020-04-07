#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

bool cmp(P &left, P &right){
    if(left.second==right.second)   return left.first > right.first;
    else    return left.second > right.second;

}

int main(){
    int n;
    cin >> n;
    vector<P> sch(n);
    vector<int> days(1001);
    for(auto &p: sch)    cin >> p.first >> p.second;
    sort(sch.begin(),sch.end(),cmp);
    for(auto p: sch){
        int d=p.first,c=p.second;
        for(int i=d;i>=1;i--){
            if(!days[i]){
                days[i] = c;
                break;
            }
        }
    }
    int ret=0;
    for(int i=1;i<=1000;i++)    ret += days[i];
    cout << ret << endl;

    return 0;
}
