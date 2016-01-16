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
ll X[101010],Y[101010];
ll A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll miA=1LL<<40;
	ll maA=-1LL<<40;
	ll miB=1LL<<40;
	ll maB=-1LL<<40;
	
	cin>>N;
	if(N==1) return _P("0 0\n");
	
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		A[i]=X[i]+Y[i],B[i]=X[i]-Y[i];
		miA=min(miA,A[i]);
		miB=min(miB,B[i]);
		maA=max(maA,A[i]);
		maB=max(maB,B[i]);
	}
	if(maB-miB>maA-miA) {
		ll t=maA-(maB-miB);
		FOR(i,N) if(A[i]!=t && A[i]!=maA && B[i]!=miB && B[i]!=maB) break;
		if(i==N) miA=t;
		else maA=miA+(maB-miB);
	}
	else if(maB-miB<maA-miA) {
		ll t=maB-(maA-miA);
		FOR(i,N) if(A[i]!=miA && A[i]!=maA && B[i]!=t && B[i]!=maB) break;
		if(i==N) miB=t;
		else maB=miB+(maA-miA);
	}
	
	ll XX=miA+miB+maA+maB;
	ll YY=miA-miB+maA-maB;
	_P("%lld %lld\n",XX/4,YY/4);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
