#include <bits/stdc++.h>

using namespace std;

const int MAX_NODE=26;

struct Trie{
    Trie *node[MAX_NODE];
    bool isend;
    
    Trie(){
        fill(node,node+MAX_NODE,nullptr);
        isend = false;
    }

    ~Trie(){
        for(int i=0;i<MAX_NODE;i++) if(node[i]) delete node[i];
    }
    void insert(const char* s){
        if(*s=='\0'){
            this->isend = true;
            return;
        }
        int cur=(*s)-'a';
        if(!this->node[cur])    this->node[cur] = new Trie();
        this->node[cur]->insert(s+1);
    }
    bool find(const char* s){
        if(*s=='\0')    return this->isend;
        int cur=(*s)-'a';
        if(!this->node[cur])    return false;
        return this->node[cur]->find(s+1);
    }
};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Trie *root = new Trie();
    for(int i=0;i<n;i++){
        char tmp[501];
        scanf("%s",tmp);
        root->insert(tmp);
    }
    int ret=0;
    for(int i=0;i<m;i++){
        char tmp[501];
        scanf("%s",tmp);
        if(root->find(tmp)) ret++;
    }
    printf("%d\n",ret);

    return 0;
}
