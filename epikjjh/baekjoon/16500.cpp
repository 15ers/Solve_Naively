#include <bits/stdc++.h>

using namespace std;

int n;
string arr[100],tar;
bool flag=false;

int main(){
    cin >> tar >> n;
    for(int i=0;i<n;i++)    cin >> arr[i];
    map<string,int> dict;
    queue<string> q;
    q.push("");
    while(!q.empty()){
        string cur=q.front();
        q.pop();
        if(cur==tar){
            flag = true;
            break;
        }
        for(int i=0;i<n;i++){
            string nxt=cur+arr[i];
            if(nxt.size()>tar.size())   continue;
            if(tar.substr(0,nxt.size())!=nxt)   continue;
            if(dict.find(nxt)!=dict.end())  continue;
            q.push(nxt);
            dict[nxt] = 1;
        }
    }

    if(flag)    cout << 1 << endl;
    else    cout << 0 << endl;

    return 0;
}
