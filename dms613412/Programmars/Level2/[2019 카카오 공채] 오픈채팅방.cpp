#include <string>
#include <vector>
#include <map>
#include <string.h>
#include <iostream>

using namespace std;

constexpr unsigned int HashCode(const char* str)
{
	return str[0] ? static_cast<unsigned int>(str[0]) + 0xEDB8832Full * HashCode(str + 1) : 8603;
}

vector<string> solution(vector<string> record) {
	vector<string> answer; vector<vector<string> > record_split(record.size());
	map<string, string> m;

	for (int i = 0; i < record.size(); ++i) {
		char *str_buff = new char[30];
		strcpy(str_buff, record[i].c_str());

		char *tok = strtok(str_buff, " ");

		while (tok != nullptr) {
			record_split[i].push_back(string(tok));
			tok = strtok(nullptr, " ");
		}

		if (record_split[i][0] != "Leave") {
			m[record_split[i][1]] = record_split[i][2];
		}

	}

	for (int i = 0; i < record.size(); ++i) {
		string s;
		if (record_split[i][0] == "Enter") {
			s = m[record_split[i][1]] + "님이 들어왔습니다.";

			answer.push_back(s);
			continue;
		}
		else if (record_split[i][0] == "Leave") {
			s = m[record_split[i][1]] + "님이 나갔습니다.";

			answer.push_back(s);

			continue;
		}


	}

	return answer;
}