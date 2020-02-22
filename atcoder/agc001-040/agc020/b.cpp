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

int K;
ll A[101010];

ll hoge(ll v) {
	int i;
	
	FOR(i,K) v-=v%A[i];
	return v;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	FOR(i,K) cin>>A[i];
	
	ll L=1+(1LL<<60),R=2;
	for(i=60;i>=0;i--) {
		if(hoge(L-(1LL<<i))>=2) L-=(1LL<<i);
		if(hoge(R+(1LL<<i))<=2) R+=(1LL<<i);
	}
	
	if(hoge(L)!=2 || hoge(R)!=2) return _P("-1\n");
	cout<<L<<" "<<R<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
