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

int N;
multiset<ll> M;
ll V[2],W[2];

ll proc() {
	ll v=*M.rbegin();
	M.erase(M.find(v));
	assert(v%2==0);
	M.insert(v/2);
	return v/2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		ll v;
		cin>>v;
		M.insert(v*(9LL<<24));
	}
	
	while(*M.begin()*2<*M.rbegin()) {
		V[0]+=proc();
		V[1]+=proc();
	}
	
	FOR(i,N) {
		W[0]+=proc();
		W[1]+=proc();
	}
	assert(W[0]%3==0);
	assert(W[1]%3==0);
	V[0]+=W[0]/3*4;
	V[1]+=W[1]/3*4;
	FOR(i,2) {
		ll P=V[i];
		ll Q=9LL<<24;
		ll g=__gcd(P,Q);
		P/=g;
		Q/=g;
		cout<<P<<"/"<<Q<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
