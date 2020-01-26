#include <bits/stdc++.h>

using namespace std;

char dec_dic[] = {'I','V','X','L','C','D','M'};
int dec_dic_i[] = {1,5,10,50,100,500,1000};
int en_dic_i[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
string en_dic[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

void decode(int &s_i, string &s){
	int l = s.size();
	for(int i=l-1;i>=0;i--){
		switch(s[i]){
			case 'I':	s_i++; break;
			case 'V':
				if(i>0 && s[i-1]=='I'){
					s_i += 4;
					i--;
				}
				else	s_i += 5;
				break;
			case 'X':
				if(i>0 && s[i-1]=='I'){
					s_i += 9;
					i--;
				}
				else	s_i += 10;
				break;
			case 'L':
				if(i>0 && s[i-1]=='X'){
					s_i += 40;
					i--;
				}
				else	s_i += 50;
				break;
			case 'C':
				if(i>0 && s[i-1]=='X'){
					s_i += 90;
					i--;
				}
				else	s_i += 100;
				break;
			case 'D':
				if(i>0 && s[i-1]=='C'){
					s_i += 400;
					i--;
				}
				else	s_i += 500;
				break;
			case 'M':
				if(i>0 && s[i-1]=='C'){
					s_i += 900;
					i--;
				}
				else	s_i += 1000;
				break;
		}
	}
}

void encode(int &s_i, string &s){
	while(s_i){
		for(int i=0;i<13;i++){
			if(s_i>=en_dic_i[i]){
				s_i -= en_dic_i[i];
				s += en_dic[i];
				break;
			}
		}
	}
}

int main(){
	string f,s,ret_s="";
	int f_i=0,s_i=0,ret=0;
	
	cin >> f >> s;
	decode(f_i,f);
	decode(s_i,s);
	ret = f_i+s_i;
	cout << ret << endl;
	encode(ret,ret_s);
	cout << ret_s << endl;
	
	return 0;
}