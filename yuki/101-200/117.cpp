#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll mo=1000000007;
const int NUM_=2000003;
ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void init() {
	int i;
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
}
ll combi(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll per(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return fact[N_]*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) {
	if(P_==0 && Q_==0) return 1;
	return combi(P_+Q_-1,Q_);
}

int T;
char hoge[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	init();
	scanf("%d",&T);
	FOR(i,T) {
		scanf("%1s(%d,%d)",hoge,&x,&y);
		ll ret=0;
		if(hoge[0]=='C') ret=combi(x,y);
		else if(hoge[0]=='P') ret=per(x,y);
		else if(hoge[0]=='H') ret=hcomb(x,y);
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
