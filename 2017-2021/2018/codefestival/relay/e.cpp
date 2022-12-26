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

string S;
int N,X,Y;

ll mo=1000000007;
ll comb(ll N_, ll C_) {
	const int NUM_=1400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X;
	N=S.size();
	Y=N-X;
	FORR(c,S) {
		if(c=='W') X--;
		if(c=='F') Y--;
	}
	S+=S;
	ll ret=0;
	FOR(i,N) {
		char c1=S[i];
		char c2=S[i+1];
		// WF
		x=X,y=Y;
		if(c1=='?') x--;
		if(c1=='F') x=-1;
		if(c2=='?') y--;
		if(c2=='W') y=-1;
		if(x>=0 && y>=0) ret+=comb(x+y,x);
		//FW
		x=Y,y=X;
		if(c1=='?') x--;
		if(c1=='W') x=-1;
		if(c2=='?') y--;
		if(c2=='F') y=-1;
		if(x>=0 && y>=0) ret+=comb(x+y,x);
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
