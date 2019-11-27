#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	int loan_month,record_num;
	double down_payment,loan;
	while(cin>>loan_month>>down_payment>>loan>>record_num,loan_month>0){
		vector<double> records(loan_month+1,-1.0);
		int ind;
		double val;
		for(int i=0;i<record_num;i++){
			cin >> ind >> val;
			records[ind] = val;
		}
		int ret=1;
		double rate=records[0],worth=(loan+down_payment)*(1.0-rate),owe=loan,monthly_payment=loan/loan_month;
		while(owe>=worth){
			if(records[ret]>0.0)	rate = records[ret];
			worth *= (1.0-rate);
			owe -= monthly_payment;
			ret++;
		}
		cout << --ret << " ";
		if(ret==1)	cout << "month" << endl;
		else	cout << "months" << endl;
	}
	
	return 0;
}