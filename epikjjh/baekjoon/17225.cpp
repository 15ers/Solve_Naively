#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main(){
	int a,b,n;
	vector<pair<int,int> > arr;
	
	cin >> a >> b >> n;
	int b_st=0,r_st=0;
	while(n--){
		int t,m;
		char c;
		
		cin >> t >> c >> m;
		int ts = (c=='B') ? a : b;
		int bc = (c=='B') ? 0 : 1;
		if(bc)	t = (t<b_st) ? b_st : t;	
		else	t = (t<r_st) ? r_st : t;
		for(int i=0;i<m;i++)
			arr.push_back(make_pair(t+i*ts,bc));
		if(bc)	b_st = t+m*ts;
		else	r_st = t+m*ts;
	}
	sort(arr.begin(),arr.end());
	vector<int> blue,red;
	for(int i=0;i<arr.size();i++){
		if(!arr[i].second){
			blue.push_back(i);
		}
		else{
			red.push_back(i);
		}
	}
	cout << blue.size() << endl;
	for(int i=0;i<blue.size();i++){
		cout << blue[i]+1;
		if(i!=blue.size()-1) cout << " ";
		else cout << endl;
	}
	cout << red.size() << endl;
	for(int i=0;i<red.size();i++){
		cout << red[i]+1;
		if(i!=red.size()-1) cout << " ";
		else cout << endl;
	}
	
	return 0;
}