#include <bits/stdc++.h>

using namespace std;

struct timetable{
	int start;
	int end;
};

bool cmp(const timetable& a, const timetable& b){
	if(a.end==b.end)	return a.start<b.start;
	else	return a.end<b.end;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int n,ret=0;
	timetable arr[100000];
	cin >> n;
	for(int i=0;i<n;i++)	cin >> arr[i].start >> arr[i].end;
	sort(arr,arr+n,cmp);
	for(int i=0;i<n;i++){
		int start=arr[i].start,end=arr[i].end;
		if(start==-1 && end==-1)	continue;
		ret++;
		for(int j=i+1;j<n;j++){
			if(arr[j].start<end){
				arr[j].start=-1;
				arr[j].end=-1;
			}
			else	break;
		}
	}
	cout << ret << endl;
	
	return 0;
}