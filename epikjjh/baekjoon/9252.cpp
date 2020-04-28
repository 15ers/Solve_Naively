#include <bits/stdc++.h>

using namespace std;

int dp[1001][1001],path[1001][1001];

int main(){
    string a,b; 
    cin >> a >> b;
    for(int i=1;i<=a.size();i++){
        for(int j=1;j<=b.size();j++){
            if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                path[i][j] = 3;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(dp[i][j]==dp[i-1][j])    path[i][j] = 1;
                else    path[i][j] = 2;
            }
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    if(dp[a.size()][b.size()]){
        stack<char> s;
        int a_i=a.size(),b_i=b.size();
        while(a_i && b_i){
            if(path[a_i][b_i]==1)    a_i--;
            else if(path[a_i][b_i]==2)   b_i--;
            else{
                s.push(a[a_i-1]);
                a_i--;
                b_i--;
            }
        }
        while(!s.empty()){
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }

    return 0;
}
