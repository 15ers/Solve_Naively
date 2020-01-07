#include <string>
#include <vector>
#include <iostream>

using namespace std;

string u, v, answer = "";


string change(string u) {
	u = u.substr(1, u.size() - 2);
	string rel = "";
	for (int i = 0; i < u.size(); ++i) {
		if (u[i] == '(')
			rel += ")";
		else
			rel += "(";
	}
	cout << rel << endl;
	return rel;
}

bool balance(string u) {
	if (u[0] == ')')return false;
	int left = 1;
	for (int i = 1; i < u.size(); ++i) {
		if (u[i] == '(')++left;
		else if (--left < 0) return false;
	}
	if (left == 0) return true;
}

string solution(string p) {
	if (p == "")
		return p;

	int left = 0, right = 0, slash = 0;
	for (int i = 0; i < p.size(); ++i) {
		if (p[i] == '(')++left;
		else ++right;
		if (left == right) {
			slash = left + right - 1;
			break;
		}
	}

	u = p.substr(0, slash + 1);
	v = p.substr(slash + 1);
	if (balance(u)) {
		answer += u;
		solution(v);
	}
	else {
		string v_ = v, u_ = u;
		answer += "(";
		solution(v);
		v = v_; u = u_;
		answer += ")";
		answer += change(u);
	}

	return answer;
}