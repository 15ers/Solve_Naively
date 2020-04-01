#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
#define ALPHABETS 26

int char_to_index(char c) {
	return c - 'a';
}
int answer = 0, tmp = 0;
struct Trie {

	bool is_terminal; // this represents end of string
	Trie * children[ALPHABETS];
	int children_num = 0;

	// Constructor
	Trie() : is_terminal(false) {
		memset(children, 0, sizeof(children));
	}

	// Delete all children
	~Trie() {
		for (int i = 0; i < ALPHABETS; ++i) {
			if (children[i])
				delete children[i];
		}
	}

	void insert(const char * key) {
		if (*key == '\0') {
			is_terminal = true;
		}
		else {
			int index = char_to_index(*key);

			if (children[index] == 0) {
				children[index] = new Trie();
				++(children_num);

			}
			children[index]->insert(key + 1);
		}
	}


	bool count(const char * key) {
		if (*key == 0) {
			return true;
		}

		int index = char_to_index(*key);

		if (*key != '\0' && is_terminal) {
			answer += tmp;
			tmp = 0;
		}

		if (children[index]->children_num > 1) {
			++answer;
			answer += tmp;
			tmp = 0;
		}
		else if (children[index]->children_num == 1) {
			if (*(key + 1) == '\0') {
				answer += tmp;
				return true;
			}
			++tmp;
		}



		return children[index]->count(key + 1);
	}

};

int solution(vector<string> words) {
	Trie*root = new Trie();
	for (int i = 0; i < words.size(); ++i) {
		root->insert(words[i].c_str());
	}

	for (int i = 0; i < words.size(); ++i) {
		++answer;
		tmp = 0;
		root->count(words[i].c_str());
	}
	delete root;

	return answer;
}