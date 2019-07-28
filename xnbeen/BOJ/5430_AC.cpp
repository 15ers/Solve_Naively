#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <math.h>
#include <sstream>

using namespace std;

int arr[51];

int main(int argc, char* argv[]) {
	int test;
	cin>>test;
	while(test--){
		vector<int>vec;
		vector<int> res;
		stringstream ss;
		string p,arr;
		int n;
		int r=0,error=0;
		int start, end;
		cin>>p>>n>>arr;
		
		start =0; end = n-1;
		ss.str(arr); // 문자열 arr을 입력값으로 받음
		char k; 
		if(n!=0)
			while(ss>>k){ //변수 k의 타입(char)을 찾을 수 없을때 까지
				int num;
				if(ss>>num) vec.push_back(num);
			}

		for(int i=0;i<p.length();++i){
			if(p[i]=='R'){
				if(r==1) r=0;
				else r=1;
			}
			else{
				if(start>end){error=1; break;}
				if(r==1) end--;
				else start++;
			}
		}
		
		if(r==1)
			for(int i=end;i>=start;--i)
				res.push_back(vec[i]);
		else 
			for(int i=start;i<=end;++i)
				res.push_back(vec[i]);
		
		if(error==1) cout<<"error"<<endl;
		else{
			cout<<'[';
			if(res.size()>0){
				cout<<res[0];
				for(int i=1;i<res.size();++i)
					printf(",%d",res[i]);
			}
			cout<<']'<<endl;
		}
	}
	
	return 0;
}
