#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T,N,K;
ll mo=1000000007;
int S[201][100001];

ll combi(ll N_, ll C_) {
	const int NUM_=200001;
	static ll fact[NUM_+1],factr[NUM_+1];
	int i;
	if (fact[0]==0) {
		vector<ll> inv(NUM_ + 1);
		inv[1]=fact[0]=factr[0]=1;
		for (i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		
		FOR(i,NUM_) fact[i+1]=fact[i]*(i+1)%mo, factr[i+1]=factr[i]*inv[i+1]%mo;
	}
	if(C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(y=0;y<=100000;y+=500) {
		FOR(x,100001) S[y/500][x]=((x?S[y/500][x-1]:0)+combi(y,x))%mo;
	}
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		ll ret=0;
		FOR(i,1+(N%500)) if(K-i>=0) ret+=S[N/500][K-i]*combi(N%500,i)%mo;
		cout<<ret%mo<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
