#include <bits/stdc++.h>

using namespace std;

class Info{
public:
	string name;
	int kor,eng,math;
	Info(string name, int kor, int eng, int math){
		this->name = name;
		this->kor = kor;
		this->eng = eng;
		this->math = math;
	}
	bool operator <(Info &info){
		if(this->kor==info.kor){
			if(this->eng==info.eng){
				if(this->math==info.math) return this->name < info.name;
				else return this->math > info.math;
			}
			else return this->eng < info.eng;
		}
		else return this->kor > info.kor;
	}
};
int main(){
	int n,kor,eng,math;
	char name[11];
	scanf("%d",&n);
	vector<Info> arr;
	for(int i=0;i<n;i++){
		scanf("%s %d %d %d",name,&kor,&eng,&math);
		arr.push_back(Info(name,kor,eng,math));
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)	printf("%s\n",arr[i].name.c_str());
	return 0;
}