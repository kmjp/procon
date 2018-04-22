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

int T,testcase;
int R,C;
ll B;
ll M[1010],S[1010],P[1010];

ll ok(ll v) {
	int i;
	vector<ll> c;
	FOR(i,C) {
		if(v<P[i]) continue;
		c.push_back(min(M[i],(v-P[i])/S[i]));
	}
	sort(ALL(c));
	reverse(ALL(c));
	ll tot=0;
	FOR(i,min((int)c.size(),R)) tot+=c[i];
	return tot>=B;
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>B>>C;
	FOR(i,C) {
		cin>>M[i]>>S[i]>>P[i];
	}
	
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--){
		if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	}
	
	
	_P("Case #%d: %lld\n",TC,ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
