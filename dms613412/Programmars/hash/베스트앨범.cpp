#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	int size = plays.size();
	unordered_map<string, pair<int, vector<int>>> map;

	string str; int play;
	for (int i = 0; i < size; ++i) {
		str = genres[i]; play = plays[i];
		if (map.find(str) == map.end()) {
			map[str].first = play;
			map[str].second.push_back(i);
		}
		else {
			map[str].first += play;
			map[str].second.push_back(i);
		}
	}
	int genre_size = map.size();
	vector<int> answer;
	for (int i = 0; i < genre_size; ++i) {

		unordered_map<string, pair<int, vector<int>>>::iterator best
			= max_element(map.begin(), map.end(), []
			(const std::pair<string, pair<int, vector<int>>>& a, const std::pair<string, pair<int, vector<int>>>& b)->bool {
			return a.second.first < b.second.first; });
		//cout<<best->first<<endl;


		int m = 0, index = 0;
		for (auto &x : best->second.second) {
			if (m < plays[x]) {
				m = plays[x]; index = x;
			}
		}
		answer.push_back(index);
		if (best->second.second.size() > 1) {
			plays[index] = -1; m = 0;
			for (auto &x : best->second.second) {
				if (m < plays[x]) {
					m = plays[x]; index = x;
				}
			}
			answer.push_back(index);
		}
		best->second.first = 0;
	}


	return answer;
}