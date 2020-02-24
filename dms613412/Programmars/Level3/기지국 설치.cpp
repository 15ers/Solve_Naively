/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	vector<int> vec(n,0);

	for(auto &x:stations){
		fill(((x-1-w<0)?0:x-1-w)+vec.begin(), ((x-1+w>=n)?n-1:x-1+w)+vec.begin()+1, 1);
	}


	int start=0,end=0;
	while(end<n && start<n){
		start=find(vec.begin()+end, vec.end(),0)-vec.begin();
		end=find(vec.begin()+start+1, vec.end(),1)-vec.begin();
		//cout<<start<<" "<<end<<endl;
		answer += (end-start)/(2*w+1);
		if((end-start)%(2*w+1)>0) ++answer;
	}

	return answer;
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int start = 0, end = 0;
	for (auto &x : stations) {
		end = x - 1 - w;
		if (end <= start) {
			start = x + w;
			continue;
		}
		answer += (end - start) / (2 * w + 1);
		if ((end - start) % (2 * w + 1) > 0) ++answer;
		start = x + w;

	}

	if (start < n) {
		end = n;
		answer += (end - start) / (2 * w + 1);
		if ((end - start) % (2 * w + 1) > 0) ++answer;
	}



	return answer;
}