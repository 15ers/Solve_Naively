#include <bits/stdc++.h>

using namespace std;

int main(){
	int width,h;
	cin >> width >> h;
	int k;
	cin >> k;
	vector<int> e,s,n,w;
	for(int i=0;i<k;i++){
		int d,x;
		cin >> d >> x;
		if(d==1)	n.push_back(x);
		else if(d==2)	s.push_back(x);
		else if(d==3)	w.push_back(x);
		else	e.push_back(x);
	}
	int d,x,ret=0;
	cin >> d >> x;
	if(d==1 || d==2){
		for(int i=0;i<n.size();i++){
			if(d==1)	ret += abs(n[i]-x);
			else	ret += h+min(n[i]+x,2*width-n[i]-x);
		}
		for(int i=0;i<s.size();i++){
			if(d==2)	ret += abs(s[i]-x);
			else	ret += h+min(s[i]+x,2*width-s[i]-x);
		}
		for(int i=0;i<w.size();i++){
			ret += x;
			if(d==1)	ret += w[i];
			else	ret += h-w[i];
		}
		for(int i=0;i<e.size();i++){
			ret += width-x;
			if(d==1)	ret += e[i];
			else	ret += h-e[i];
		}
	}
	else{
		for(int i=0;i<n.size();i++){
			ret += x;
			if(d==3)	ret += n[i];
			else	ret += width-n[i];
		}
		for(int i=0;i<s.size();i++){
			ret += h-x;
			if(d==3)	ret += s[i];
			else	ret += width-s[i];
		}
		for(int i=0;i<w.size();i++){
			if(d==3)	ret += abs(w[i]-x);
			else	ret += width+min(w[i]+x,2*h-w[i]-x);
		}
		for(int i=0;i<e.size();i++){
			if(d==4)	ret += abs(e[i]-x);
			else	ret += width+min(e[i]+x,2*h-e[i]-x);
		}
	}
	cout << ret << endl;
	
	return 0;
}