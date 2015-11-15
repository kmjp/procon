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

ll N,K,R;
ll M,S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M>>R;
	FOR(i,N-1) cin>>S[i];
	sort(S,S+N-1);
	reverse(S,S+N-1);
	
	ll tot=0;
	FOR(i,K-1) tot+=S[i];
	
	ll left=K*R-tot;
	if(left<=S[K-1]) _P("0\n");
	else if(left>M) _P("-1\n");
	else _P("%lld\n",left);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
