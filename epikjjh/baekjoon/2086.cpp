#include <bits/stdc++.h>
#define MOD 1000000000

using namespace std;

class Matrix{
private:
	long long a;
	long long b;
	long long c;
	long long d;
	
public:	
	Matrix(long long a, long long b, long long c, long long d){
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}
	Matrix operator * (Matrix m){
		long long n_a = (a*m.a+b*m.c)%MOD;
		long long n_b = (a*m.b+b*m.d)%MOD; 
		long long n_c = (c*m.a+d*m.c)%MOD;
		long long n_d = (c*m.b+d*m.d)%MOD;
		return Matrix(n_a,n_b,n_c,n_d);
	}
	long long result(){
		return (a+b)%MOD;
	}
};

Matrix power(long long m){
	if(m==0)	return Matrix(1,0,0,1);
	if(m==1)	return Matrix(1,1,1,0);
	if(m%2==0){
		Matrix ret = power(m/2);
		return ret*ret;
	}
	else{
		Matrix ret = power(m/2);
		return ret*ret*power(1);
	}
}


int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	long long a,b;
	cin >> a >> b;
	Matrix sum_b = power(b), sum_a = power(a-1);
	if(sum_b.result()>sum_a.result())	cout << sum_b.result()-sum_a.result() << endl;
	else	cout << MOD+sum_b.result()-sum_a.result() << endl;
	
	return 0;
}