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

ll A[4],B[4],C;

ll cost(ll v) {
	ll ret=C*v;
	int i;
	FOR(i,4) ret+=max(A[i]-v,0LL)*B[i];
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>A[i];
	FOR(i,4) cin>>B[i];
	cin>>C;
	ll ret=1LL<<60;
	ret=min(ret,cost(0));
	FOR(i,4) ret=min(ret,cost(A[i]));
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
