#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0, size;

bool check(vector<int>&vec) {
	int i = vec.size() - 1;
	int j = vec[i];
	for (int k = 0; k < i; ++k) {
		if (vec[k] == j)return false;
		if (vec[i - (k + 1)] == j - (k + 1))return false;
		if (vec[i - (k + 1)] == j + (k + 1))return false;
	}
	return true;
}

void dfs(int index, vector<int> &vec) {
	if (index > 1) {
		bool result = check(vec);
		if (index == size) {
			if (result) {
				++answer;
				//for(auto &x : vec)cout<<x<<" ";
				//cout<<endl;
			}
			return;
		}
		if (!result) return;
	}

	for (int i = 0; i < size; ++i) {
		vec.push_back(i);
		dfs(index + 1, vec);
		vec.pop_back();
	}

}

int solution(int n) {
	if (n == 1)return 1;
	size = n;
	vector<int> vec;
	dfs(0, vec);
	return answer;
}