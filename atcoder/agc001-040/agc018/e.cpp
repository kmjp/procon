#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

const int NUM_=2200001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll mo=1000000007;
int X[6],Y[6];


ll comb(int x,int y) {
	return fact[x+y]*factr[x]%mo*factr[y]%mo;
}

ll hoge(int L,int U,int R,int B) {
	ll ret=0;
	int x,y;
	
	for(x=X[2];x<=X[3];x++) {
		ll in=comb(x-L,Y[3]-U)*comb(R-x,B-(Y[3]+1))%mo*(x+Y[3])%mo;
		ll out=comb(x-L,(Y[2]-1)-U)*comb(R-x,B-(Y[2]-1+1))%mo*(x+(Y[2]-1))%mo;
		ret += in - out;
	}
	for(y=Y[2];y<=Y[3];y++) {
		ll in=comb(X[3]-L,y-U)*comb(R-(X[3]+1),B-y)%mo*(X[3]+y)%mo;
		ll out=comb((X[2]-1)-L,y-U)*comb(R-(X[2]-1+1),B-y)%mo*((X[2]-1)+y)%mo;
		ret += in - out;
	}
	return (ret%mo+mo)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	FOR(i,6) cin>>X[i];
	FOR(i,6) cin>>Y[i];
	int L[2]={X[0]-1,X[1]};
	int U[2]={Y[0]-1,Y[1]};
	int R[2]={X[5]+1,X[4]};
	int B[2]={Y[5]+1,Y[4]};
	
	ll ret=0;
	FOR(i,16) {
		ll tmp=hoge(L[i/8],U[i/4%2],R[i/2%2],B[i%2]);
		if(__builtin_popcount(i)&1) ret-=tmp;
		else ret+=tmp;
	}
	
	cout<<(ret+8*mo)%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
