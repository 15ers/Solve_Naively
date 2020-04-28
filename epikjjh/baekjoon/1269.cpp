#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    set<int> a;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        a.insert(tmp);
    }
    int ret=a.size();
    for(int i=0;i<m;i++){
        int tmp;
        cin >> tmp;
        if(a.find(tmp)!=a.end())    ret--;
        else    ret++;
    }
    cout << ret << endl;

    return 0;
}
