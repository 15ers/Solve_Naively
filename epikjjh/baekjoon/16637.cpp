#include <bits/stdc++.h>

using namespace std;

vector<int> num;
vector<char> op;

long long ret=-10987654321;
long long e;

int cal(char op, long long left, long long right){
    int ans;
    switch(op){
        case '+':
            ans = left+right;
            break;
        case '-':
            ans = left-right;
            break;
        case '*':
            ans = left*right;
            break;
        default:
            break;
    }
    return ans;
}

void dfs(long long cur, int idx){
    if(idx>=e){
        ret = max(ret,cur);
        return;
    }
    char cop=op[idx];
    long long right=num[idx+1],nxt; 
    dfs(cal(cop,cur,right),idx+1);
    if(idx+1<e){
        char nop=op[idx+1];
        long long nright=num[idx+2];
        dfs(cal(cop,cur,cal(nop,right,nright)),idx+2);
    }
}

int main(){
    int n;
    string eq;

    cin >> n >> eq;
    e = n/2;
    for(int i=0;i<n;i++){
        if(i%2) op.push_back(eq[i]);
        else    num.push_back(eq[i]-'0');
    }
    if(n==1){
        cout << num[0] << endl;
        return 0;
    }
    dfs(num[0],0);
    cout << ret << endl;
    
    return 0;
}
