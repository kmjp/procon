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
ll X,Q[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	ll S=0;
	FOR(i,N) {
		cin>>Q[i];
		S+=Q[i];
	}
	sort(Q,Q+N);
	reverse(Q,Q+N);
	ll num=(S+(X-1))/X;
	
	ll TS=0;
	FOR(i,num) TS+=Q[i];
	ll mi=0;
	for(x=num;x<N;x++) mi=max(mi,Q[x]);
	
	ll ret=(1LL<<30)-1;
	for(i=29;i>=0;i--) {
		ll pat=ret-(1LL<<i);
		if(pat<mi) continue;
		ll tot=0;
		FOR(x,num) tot+=min(pat,X-Q[x]);
		if(tot>=S-TS) ret=pat;
	}
	cout<<num<<" "<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
