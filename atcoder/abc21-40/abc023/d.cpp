#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll H[101000],S[101000];

bool ok(ll v) {
	vector<ll> D;
	int i;
	FOR(i,N) {
		if(v<H[i]) return false;
		D.push_back((v-H[i])/S[i]);
	}
	sort(ALL(D));
	FOR(i,N) if(D[i]<i) return false;
	return true;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>H[i]>>S[i];
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
