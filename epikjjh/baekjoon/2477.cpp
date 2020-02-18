#include <bits/stdc++.h>

using namespace std;

int main(){
	int k;
	cin >> k;
	vector<int> arr;
	int max_w=0,max_h=0,max_w_i=-1;
	for(int i=0;i<6;i++){
		int d,v;
		cin >> d >> v;
		arr.push_back(v);
		if(d==1 || d==2){
			if(v>max_w){
				max_w = v;
				max_w_i = i;
			}
		}
		else	max_h = max(max_h,v);
	}
	int ret;
	int left=arr[(max_w_i-1+6)%6];
	int right=arr[(max_w_i+1)%6];
	if(left==max_h){
		int red=arr[(max_w_i-2+6)%6];
		ret = max_w*max_h - (max_w-red)*(max_h-right);
	}
	else{
		int	red=arr[(max_w_i+2)%6];
		ret = max_w*max_h - (max_w-red)*(max_h-left);
	}
	cout << ret*k << endl;
	
	return 0;
}