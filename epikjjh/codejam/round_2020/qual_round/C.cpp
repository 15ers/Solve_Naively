#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;

int main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n;
        scanf("%d",&n);
        vector<P> arr(n);
        map<P,int> table;
        int idx=0;
        for(auto &p: arr){
            scanf("%d %d",&p.first,&p.second);
            table.insert({{p.first,p.second},idx});
            idx++;
        }
        sort(arr.begin(),arr.end());
        string ret="";
        for(int i=0;i<n;i++)    ret += "J";
        bool flag=true,J=true,C=true;
        int J_e=0,C_e=0;
        for(int i=0;i<n;i++){
            int s=arr[i].first,e=arr[i].second;
            int idx=table[make_pair(s,e)];
            if(J_e<=s)  J = true;
            if(C_e<=s)  C = true;
            if(J){
                J = false;
                J_e = e;
                ret[idx] = 'J';
            }
            else if(C){
                C = false;
                C_e = e;
                ret[idx] = 'C';
            }
            else{
                ret = "IMPOSSIBLE";
                break;
            }
        }
        cout << "Case #" << i << ": " << ret << endl;
    }

    return 0;
}
