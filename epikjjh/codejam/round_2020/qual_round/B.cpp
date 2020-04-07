#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++){
        string s;
        cin >> s;
        int n=s.size(),pre=0;
        string ret="";
        for(int i=0;i<n;i++){
            int cur=s[i]-'0';
            if(pre<cur) for(int j=0;j<cur-pre;j++)  ret += "(";
            if(pre>cur) for(int j=0;j<pre-cur;j++)  ret += ")";
            ret += s[i];
            pre = cur;
        }
        if(pre) for(int j=0;j<pre;j++)  ret += ")";
        cout << "Case #" << tc << ": " << ret << endl;
    }

    return 0;
}
