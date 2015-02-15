#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N,V;
ll C[102],S[102];

ll co[20900];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>V;
	FOR(i,N) cin>>C[i+1],S[i+1]=S[i]+C[i+1];
	if(V<=N) return _P("%lld\n",S[N]);
	
	V-=N;
	
	x=1;
	for(i=2;i<=N;i++) {
		if(S[i]*x < S[x]*i) x=i;
	}
	for(i=0;i<=min(20200,(int)V);i++) {
		co[i]=1LL<<60;
		if((V-i)%x==0) co[i]=(V-i)/x*S[x];
	}
	for(i=min(20000,(int)V);i>=0;i--) {
		for(j=1;j<=N;j++) co[i]=min(co[i],co[i+j]+S[j]);
	}
	cout<<co[0]+S[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
