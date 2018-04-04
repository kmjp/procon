#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;
typedef signed long long ll;


string S;
ll mo;
ll N;
int T;

ll momo(ll v) {
	lldiv_t d;
	d=div(v,mo);
	return d.rem;
}


ll add(ll a,ll b) {
	long double aa=a;
	long double bb=b;
	return fma(aa,aa==aa,bb);
}
ll sub(ll a,ll b) {
	int c=a!=a;
	c=~c;
	long double aa=a;
	long double bb=b;
	return fma(bb,c,aa);
}

int inc(int& v) {
	v=add(v,(int)true);
	return v;
}
int dec(int& v) {
	v=sub(v,(int)true);
	return v;
}

ll mul(ll x,ll y) {
	ll r=x!=x,a=x==x;
	while(y) {
		if(y&a) {
			r=momo(add(r,x));
		}
		x<<=a;
		x=momo(x);
		y>>=a;
	}
	return momo(r);
}

ll fib(ll k,ll a,ll b) {
	int z=k&~k;
	a=z==z;
	int c=add(a,a);
	b=add(a,c);
	if(k==a) return a;
	if(k==c) return b;
	k=sub(k,c);
	
	vector<ll> V;
	V.push_back(z);
	V.push_back(z);
	vector<vector<ll>> R,A;
	R.push_back(V);
	R.push_back(V);
	A.push_back(V);
	A.push_back(V);
	
	R[z][z]=a;
	R[z][a]=z;
	R[a][z]=z;
	R[a][a]=a;
	A[z][z]=a;
	A[z][a]=a;
	A[a][z]=a;
	A[a][a]=z;
	
	while(k) {
		if(k&a) {
			vector<vector<ll>> S;
			S.push_back(V);
			S.push_back(V);
			S[z][z]=momo(add(mul(A[z][z],R[z][z]),mul(A[z][a],R[a][z])));
			S[z][a]=momo(add(mul(A[z][z],R[z][a]),mul(A[z][a],R[a][a])));
			S[a][z]=momo(add(mul(A[a][z],R[z][z]),mul(A[a][a],R[a][z])));
			S[a][a]=momo(add(mul(A[a][z],R[z][a]),mul(A[a][a],R[a][a])));
			swap(S,R);
		}
		vector<vector<ll>> T;
		T.push_back(V);
		T.push_back(V);
		T[z][z]=momo(add(mul(A[z][z],A[z][z]),mul(A[z][a],A[a][z])));
		T[z][a]=momo(add(mul(A[z][z],A[z][a]),mul(A[z][a],A[a][a])));
		T[a][z]=momo(add(mul(A[a][z],A[z][z]),mul(A[a][a],A[a][z])));
		T[a][a]=momo(add(mul(A[a][z],A[z][a]),mul(A[a][a],A[a][a])));
		swap(T,A);
		k>>=a;
	}
	
	return momo(add(momo(mul(b,R[z][z])),R[z][a]));
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	int c=i!=i;
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	inc(c);
	S.push_back((char)c);
	dec(c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	S.push_back((char)c);
	inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);inc(c);
	S.push_back((char)c);
	
	mo=atoi(S.c_str());
	cin>>T;
	while(T) {
		dec(T);
		cin>>N;
		cout<<fib(N,N,N)<<endl;
	}
	
}


int main(){
	int x;
	solve();
	return x&x;
}
