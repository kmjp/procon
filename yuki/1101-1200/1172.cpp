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

int K,N,M;
ll A[202020];
ll C[202020];
ll V[202020];

vector<int> add[202020];
vector<int> del[202020];
int L[202020],R[202020];

const ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N>>M;
	FOR(i,K) cin>>A[i];
	FOR(i,K) cin>>C[i+1];
	for(i=K;i<=N+K+1;i++) {
		for(j=1;j<=K;j++) (A[i]+=C[j]*A[i-j])%=mo;
	}
	
	FOR(i,M) {
		cin>>L[i]>>R[i];
		add[L[i]+K].push_back(L[i]);
		del[R[i]+K].push_back(L[i]);
	}
	
	FOR(i,N+K+1) {
		FORR(e,add[i]) {
			for(j=1;j<=K;j++) (V[i-j]+=A[K-j])%=mo;
		}
		FORR(e,del[i]) {
			for(j=1;j<=K;j++) (V[i-j]+=mo-A[i-e-j])%=mo;
		}
		if(i>=K) {
			for(j=1;j<=K;j++) (V[i]+=C[j]*V[i-j])%=mo;
		}
	}
	FOR(i,N) cout<<V[i]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
