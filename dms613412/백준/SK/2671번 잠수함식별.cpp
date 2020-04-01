#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {

	string str;
	cin >> str;
	int size = str.size();
	int index;
	int type = 0;
	if (size < 2) {
		cout << "NOISE" << endl;
		return 0;
	}
	if (str[0] == '1') {
		index = 1;
		type = 1;
	}
	else {
		index = 0;
		type = 2;
	}

	while (index < size) {
		if ((type == 4 || type == 1) && str[index] == '0'&&str[index + 1] == '0') {
			auto tmp1 = find(str.begin() + index + 2, str.end(), '1');
			if (tmp1 == str.end()) {
				cout << "NOISE" << endl;
				return 0;
			}
			if (str[tmp1 - str.begin() + 1] == '0') {
				index = tmp1 - str.begin() + 1;
				type = 2;
				continue;
			}
			index = find(tmp1 + 1, str.end(), '0') - str.begin();
			type = 4;
		}
		else if ((type == 4 || type == 2) && str[index] == '0'&&str[index + 1] == '1') {
			index += 2;
			type = 2;
			if (str[index] == '1') {
				++index;
				type = 1;
			}
		}
		else {
			cout << "NOISE" << endl;
			return 0;
		}
	}

	cout << "SUBMARINE" << endl;
	return 0;
}