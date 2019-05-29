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


int N,M;
vector<ll> V,S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		V.push_back(x);
	}
	sort(ALL(V));
	FOR(i,N) V[i]-=i;
	
	FOR(i,N) V.push_back(V[i]+(M-N));
	FOR(i,N) V.push_back(V[i]+2*(M-N));
	
	FORR(v,V) {
		if(S.size()) {
			S.push_back(S.back()+v);
		}
		else {
			S.push_back(v);
		}
	}
	
	
	ll mi=1LL<<60;
	for(i=N;i<2*N;i++) {
		mi=min(mi,(S[i+N/2]-S[i]-V[i]*(N/2))+(V[i]*(N-N/2)-(S[i]-S[i+N/2-N])));
	}
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
