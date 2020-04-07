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

vector<ll> V[12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	
	for(i=1;i<=9;i++) V[1].push_back(i);
	if(K<=9) return _P("%lld\n",V[1][K-1]);
	K-=9;
	for(i=1;i<=9;i++) {
		FORR(v,V[i]) {
			x=v%10;
			if(x) V[i+1].push_back(v*10+x-1);
			V[i+1].push_back(v*10+x);
			if(x<9) V[i+1].push_back(v*10+x+1);
		}
		if(K<=V[i+1].size()) return _P("%lld\n",V[i+1][K-1]);
		K-=V[i+1].size();
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
