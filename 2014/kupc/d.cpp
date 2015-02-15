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

string S1,S2;
int L,D1,D2;
int num[2];
ll mo=1000000007;

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
	int f,i,j,k,l,x,y;
	
	cin>>S1>>D1>>S2>>D2;
	L=S1.size();
	FOR(i,L) num[S1[i]!=S2[i]]++;
	ll ret=0;
	
	if((D1+D2)%2 != num[1]%2) return _P("0\n");
	x=(num[1]-(D2-D1))/2;
	y=num[1]-x;
	if(x<0 || x>num[1] || y<0 || y>num[1]) return _P("0\n");
	int z=D1-x;
	if(z<0 || z>num[0]) return _P("0\n");
	
	_P("%lld\n",combi(num[0],z)*combi(num[1],x)%mo);
}


int main(int argc,char** argv){
	string s;
	if(argc==1) ios::sync_with_stdio(false);
	for(int i=1;i<argc;i++) s+=argv[i],s+='\n';
	for(int i=s.size()-1;i>=0;i--) ungetc(s[i],stdin);
	solve();
	return 0;
}


