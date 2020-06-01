#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE = 128;

int total=0;
char tar[31];

struct Trie{
    Trie *node[MAX_NODE];
    int cnt;
    Trie(){
        cnt = 0;
        fill(node,node+MAX_NODE,nullptr);
    }
    ~Trie(){
        for(int i=0;i<MAX_NODE;i++) if(node[i]) delete node[i];        
    }
    void insert(const char *tar){
        if(*tar=='\0'){
            cnt++;
            total++;
        }
        else{
            int nxt = *tar - ' ';
            if(!node[nxt])  node[nxt] = new Trie;
            node[nxt]->insert(tar+1);
        }
    }
    void print(int ind){
        if(cnt){
            tar[ind] = '\0';
            printf("%s %.4lf\n", tar, 100.0*cnt/total);
        }
        for(int i=0;i<MAX_NODE;i++){
            if(node[i]){
                tar[ind] = i + ' ';
                node[i]->print(ind+1);
            }
        }
    }
};

int main(){
    Trie *root = new Trie;
    char tmp[31];

    while(gets(tmp)!=NULL) root->insert(tmp);
    root->print(0);

    return 0;
}
