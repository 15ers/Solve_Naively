/*정확도
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

vector<int> answer(100000,0);
vector<int> update(100000,0);
vector<int> solution(vector<string> words, vector<string> queries) {
	int wn = words.size(), qn=queries.size();
	vector<string>::iterator iter;
	size_t start,last;
	for(int i=0; i<qn;++i){
		if(update[i])continue;//이미 update된 queryword
		update[i]=1;
		int size = queries[i].size();
			if(queries[i][0]=='?'){
				start=queries[i].find_last_of('?')+1;
				last=queries[i].size();//-1
			}else{
				start=0;
				last=queries[i].find('?');
			}
		string tmp = queries[i].substr(start,last);
		for(int j=0; j<wn;++j){
			if(words[j].size()!=size)continue;
			if(words[j].substr(start,last)==tmp)++answer[i];
		}



		//동일한 query word들 모두 update
		if((iter=find(queries.begin()+i+1, queries.end(), queries[i])) != queries.end()){//!=조건 change
			int index = distance(queries.begin(),iter);
			answer[index]=answer[i];
			update[index]=1;
		}


	}

	vector<int>::iterator it=answer.begin()+qn;
	vector<int> Vec(answer.begin(), it);
	return Vec;
}
*/

//정확도 + 효율성
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct Trie {
	Trie *next[26];
	int count;
	bool term;
	Trie() : term(false), count(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; ++i) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0')
			term = true;
		else {
			int cur = *key - 'a';
			if (next[cur] == NULL)
				next[cur] = new Trie();
			else
				next[cur]->count++; //count 1에서 시작
			next[cur]->insert(key + 1);
		}
	}

	int find(const char* key) {
		int cur = *key - 'a';
		if (*key == '?') {
			int tmp = 0;
			for (int k = 0; k < 26; ++k) {
				if (next[k] != NULL)
					tmp += next[k]->count;
			}
			return tmp;
		}
		if (next[cur] == NULL) return 0;
		if (*(key + 1) == '?')return next[cur]->count;
		return next[cur]->find(key + 1);
	}
};

Trie *root[10001];
Trie *reroot[10001];

vector<int>solution(vector<string> words, vector<string> queries) {
	int wn = words.size();
	int qn = queries.size();
	vector<int> answer(qn, 0);

	for (auto &a : words) {//for(int a;a<wn;++a)
		int size = a.size();
		const char *c = a.c_str();
		if (root[size] == NULL)root[size] = new Trie();
		root[size]->insert(c);

		string rstring = a;
		reverse(rstring.begin(), rstring.end());

		const char *k = rstring.c_str();
		if (reroot[size] == NULL)reroot[size] = new Trie();
		reroot[size]->insert(k);
	}

	int idx = 0;

	for (auto &a : queries) {
		int size = a.size();
		if (a[size - 1] == '?') {
			const char *c = a.c_str();
			if (root[size] == NULL) { ++idx; continue; }
			else answer[idx] = root[size]->find(c);
		}
		else {
			string rstring = a;
			reverse(rstring.begin(), rstring.end());

			const char *c = rstring.c_str();
			if (reroot[size] == NULL) { ++idx; continue; }
			else answer[idx] = reroot[size]->find(c);
		}
		++idx;
	}
	return answer;
}






