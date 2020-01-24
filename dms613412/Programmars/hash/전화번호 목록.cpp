//sorting
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
/*
bool solution(vector<string> phone_book) {
	bool answer = true;
	sort(phone_book.begin(), phone_book.end());
	for (int i = 0; i < phone_book.size() - 1; i++) {
		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size())) return false;
	}
	return answer;
}
*/

//Trie

struct Trie {
	Trie *next[10];
	int count;
	bool term;
	Trie() : term(false), count(1) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 10; ++i) {
			if (next[i])
				delete next[i];
		}
	}
	void insert(const char* key) {
		if (*key == '\0')
			term = true;
		else {
			int cur = *key - '0';
			if (next[cur] == NULL)
				next[cur] = new Trie();
			else
				next[cur]->count++; //count 1에서 시작
			next[cur]->insert(key + 1);
		}
	}

	int find(const char* key) {
		int cur = *key - '0';
		if (next[cur] == NULL) return 0;
		if (*(key + 1) == '\0')return next[cur]->count;
		return next[cur]->find(key + 1);


	}
};

bool solution(vector<string> phone_book) {
	int size = phone_book.size();
	Trie root;
	for (auto &a : phone_book) {
		const char *c = a.c_str();
		root.insert(c);
	}
	int id = 0;
	for (auto &a : phone_book) {
		const char *c = a.c_str();
		if (root.find(c) > 1)return false;
	}

	return true;
}


//hash
/*
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;

	unordered_map<string, int> hash_map;
	for(int i = 0; i < phone_book.size(); i++)
		hash_map[phone_book[i]] = 1;

	for(int i = 0; i < phone_book.size(); i++) {
		string phone_number = "";
		for(int j = 0; j < phone_book[i].size(); j++) {
			phone_number += phone_book[i][j];
			if(hash_map[phone_number] && phone_number != phone_book[i])
				answer = false;
		}
	}

	return answer;
}
*/