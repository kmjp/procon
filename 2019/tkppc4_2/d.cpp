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
ll P,Q;
ll A[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P>>Q;
	if(abs(P%2)!=abs(Q%2)) return _P("0\n");
	ll X=(P+Q)/2;
	ll YZ=(P-Q)/2;
	
	FOR(i,N) cin>>A[i];
	
	ll ret=0;
	ll yzsum=0;
	map<ll,ll> M;
	for(i=N-1;i>=0;i--) {
		if(A[i]==X) ret+=yzsum;
		yzsum+=M[YZ-A[i]];
		M[A[i]]++;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
