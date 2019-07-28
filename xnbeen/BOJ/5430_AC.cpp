#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <math.h>

using namespace std;

int arr[51];

int main(int argc, char* argv[]) {
	int test;
	cin>>test;
	while(test--){
		deque<int>dq;
		vector<int>vec;
		string p,arr;
		int n;
		int r=0;
		cin>>p>>n>>arr;
		
		if(n!=0){
			arr = arr.substr(1,arr.length()-2);

			while(arr.find(',')!=string::npos){
				dq.push_back(stoi(arr.substr(0,arr.find(','))));
				arr=arr.substr(arr.find(',')+1);
			}
			dq.push_back(stoi(arr));
		}
		for(int i=0;i<p.length();++i){
			if(p[i]=='R'){
				if(r==1) r=0;
				else r=1;
			}
			else{
				if(dq.empty()){cout<<"error"<<endl; break;}
				if(r==1) dq.pop_back();
				else dq.pop_front();
			}
		}
		
		if(r==1)
			while(!dq.empty()){
				vec.push_back(dq.back());
				dq.pop_back();
			}
		else 
			while(!dq.empty()){
				vec.push_back(dq.front());
				dq.pop_front();
			}
		cout<<'[';
		if(vec.size()>0){
			cout<<vec[0];
			for(int i=1;i<vec.size();++i)
				cout<<','<<vec[i];
		}
		cout<<']'<<endl;
		
	}
	
	return 0;
}
