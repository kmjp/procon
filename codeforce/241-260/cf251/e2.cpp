#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
//-------------------------------------------------------

int Q;
int N[100001],F[100001];
ll mo=1000000007;

//同一の要素を複数含まない素因数分解
vector<ll> enumdiv(ll n) {
	vector<ll> V;
	if(n==1) return vector<ll>(1,1);
	for(ll i=2;i*i<=n;i++) {
		if(n%i==0) V.push_back(i);
		while(n%i==0) n/=i;
	}
	if(n>1) V.push_back(n);
	return V;
}

ll combi(int N_, int C_) {
	const int NUM_=200001;
	static ll fact[NUM_+1],factr[NUM_+1];
	int i;
	if (fact[0]==0) {
		vector<ll> inv(NUM_ + 1);
		inv[1] = 1;
		for (i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		fact[0]=factr[0]=1;
		FOR(i,NUM_) fact[i+1]=fact[i]*(i+1)%mo, factr[i+1]=factr[i]*inv[i+1]%mo;
	}
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int f,i,j,k,l,x,y,mask;
	
	cin>>Q;
	FOR(i,Q) {
		cin>>N[i]>>F[i];
		
		if(N[i]==1) {
			cout<<1<<endl;
			continue;
		}
		ll ret=0;
		vector<ll> VV=enumdiv(N[i]);
		FOR(mask,1<<VV.size()) {
			x=N[i];
			y=1;
			FOR(j,VV.size()) if(mask&(1<<j)) x/=VV[j],y=-y;
			if(x<F[i]) continue;
			x-=F[i];
			ret += y*combi(x+F[i]-1,F[i]-1);
		}
		ret %= mo;
		if(ret<0) ret+=mo;
		cout << ret << endl;
	}
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


