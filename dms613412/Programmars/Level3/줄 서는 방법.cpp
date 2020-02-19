#include <string>
#include <vector>
#include <iostream>

using namespace std;
//int visited[21]={0,};
long long cache[21] = { 0, };

long long fact(int x) {
	if (x == 1)return 1;
	long long &tmp = cache[x];
	if (tmp)return tmp;
	tmp = fact(x - 1)*x;
	return tmp;
}

vector<int> solution(int n, long long k) {
	vector<int> visited(21, 0);
	vector<int> answer;
	long long div = k, raq = k;
	while (answer.size() < n) {
		//cout<<"반복"<<endl;        
		if (fact(n - answer.size() - 1)) {
			div = k / fact(n - answer.size() - 1);
			raq = k % fact(n - answer.size() - 1);
		}
		else {
			div = 0; raq = k;
		}
		//cout<<div<<" "<<raq<<endl;
		if (div > 0 && raq == 0) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (!visited[i]) {
					++cnt;
					if (cnt == div) {
						visited[i] = 1;
						answer.push_back(i);
						break;
					}
				}
			}

			for (int i = n; i > 0; --i) {
				if (!visited[i]) answer.push_back(i);
			}
			break;
		}
		else if (div > 0 && raq > 0) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (!visited[i]) {
					++cnt;
					if (cnt == div + 1) {
						visited[i] = 1;
						answer.push_back(i);
						break;
					}
				}
			}
			k = raq;
		}
		else {
			//cout<<"test"<<endl;
			if (div == 0)div = 1;
			//if(answer.empty()){answer.push_back(1);--k;}

			for (int i = 1; i <= n; ++i) {
				//cout<<visited[3]<<" ";
				if (!visited[i]) {
					visited[i] = 1;
					answer.push_back(i);
					break;
				}
			}
			if (raq == 1) {
				for (int i = 2; i <= n; ++i) {
					if (!visited[i]) {
						//visited[i]=1;
						answer.push_back(i);
					}
				}
				break;
			}
			k = raq;
		}
	}

	return answer;
}