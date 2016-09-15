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

int Q;
ll X,A,B;
map<pair<ll,ll>,ll> M[61];

ll dodo(int d,ll x,ll a) {
	if(d==-1) return 1;
	if(M[d].count({x,a})) return M[d][{x,a}];
	ll D=1LL<<d;
	ll ret;
	if(x&D) {
		if(a&D) ret = dodo(d-1,x^D,a^D);
		else ret = 0;
	}
	else {
		if(a&D) ret = dodo(d-1,x,a^D) + dodo(d-1,x,D-1);
		else ret = dodo(d-1,x,a);
	}
	
	return M[d][{x,a}]=ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>A>>B>>X;
		
		FOR(i,60) M[i].clear();
		cout<<dodo(60,X,B)-dodo(60,X,A-1)<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
