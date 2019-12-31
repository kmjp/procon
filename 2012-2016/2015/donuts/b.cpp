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

int N,M;
int B[100],C[100],I[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>B[i], I[i]=1<<i;
	FOR(i,M) {
		cin>>B[i+N]>>C[i+N];
		while(C[i+N]--) cin>>x, I[i+N] |= 1<<(x-1);
	}
	
	int ma=0;
	for(int mask=0;mask<1<<N;mask++) if(__builtin_popcount(mask)==9) {
		int tot=0;
		FOR(i,N) if(mask & I[i]) tot+=B[i];
		FOR(i,M) if(__builtin_popcount(mask & I[N+i])>=3) tot+=B[N+i];
		ma=max(ma,tot);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
