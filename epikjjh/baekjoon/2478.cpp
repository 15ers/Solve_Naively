#include <bits/stdc++.h>

using namespace std;

int n,ret_p=0,ret_q=0;
vector<int> arr;

void rotate(){
	int tmp = arr[n-1];
	for(int i=n-1;i>=0;i--)	arr[i] = arr[i-1];
	arr[0] = tmp;
}

bool is_rev(vector<int> &v){
	vector<int> tmp(n);
	int p=-1,q=-1;
	for(int i=0;i<n;i++)	tmp[i] = arr[i]-v[i];
	for(int i=0;i<n;i++){
		if(tmp[i]){
			if(p==-1)	p=i;
			else	q=i;
		}
	}
	if(p==-1)	p=q=0;
	copy(arr.begin(),arr.end(),tmp.begin());
	for(int i=0;i<=(q-p)/2;i++)	swap(tmp[p+i],tmp[q-i]);
	bool flag=true;
	for(int i=0;i<n;i++)	if(v[i]!=tmp[i])	flag = false;
	if(flag){
		ret_p = p;
		ret_q = q;
	}
	return flag;
}

int main(){
	cin >> n;
	arr.resize(n);	
	vector<int> front(n),back(n);
	for(int &p: arr)	cin >> p;
	int t=0;
	for(;t<n;t++){
		front[0] = arr[0];
		for(int i=1;i<n;i++){
			front[i] = (front[i-1]+1)%n;
			if(!front[i])	front[i] = n;	
		}
		back[n-1] = arr[n-1];
		for(int i=n-2;i>=0;i--){
			back[i] = (back[i+1]-1+n)%n;
			if(!back[i])	back[i] = n;
		}
		if(!is_rev(front))	if(is_rev(back))	break;
		rotate();
	}
	for(int i=0;i<=(ret_q-ret_p)/2;i++)	swap(arr[ret_p+i],arr[ret_q-i]);
	if(arr[0]==1)	cout << n << endl;
	else	cout << arr[0]-1 << endl;
	cout << ret_p+1 << " " << ret_q+1 << endl;
	if(t)	cout << t << endl;
	else	cout << n << endl;
	
	return 0;
}