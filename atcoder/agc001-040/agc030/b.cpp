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

ll L;
ll N;
ll X[202020];
ll LL[202020];
ll RR[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>L>>N;
	for(i=1;i<=N;i++) cin>>X[i];
	
	for(i=1;i<=N;i++) {
		LL[i]=LL[i-1]+(L-X[N+1-i]);
		RR[i]=RR[i-1]+X[i];
	}
	
	ll ma=max(X[N],L-X[1]);
	for(int le=1;le<=N-1;le++) {
		int ri=N-le;
		
		ll pat=0;
		x=min(le,ri+1);
		y=x-1;
		pat=(LL[le]+LL[le-1]-2*LL[le-x]);
		pat+=2*(RR[ri]-RR[ri-y]);
		ma=max(ma,pat);

		y=min(le+1,ri);
		x=y-1;
		pat=2*(LL[le]-LL[le-x]);
		pat+=RR[ri]+RR[ri-1]-2*RR[ri-y];
		ma=max(ma,pat);
		
		x=y=min(le,ri);
		pat=2*(LL[le]-LL[le-x]);
		pat+=RR[ri]+RR[ri-1]-2*RR[ri-y];
		ma=max(ma,pat);

		pat=(LL[le]+LL[le-1]-2*LL[le-x]);
		pat+=2*(RR[ri]-RR[ri-y]);
		ma=max(ma,pat);
		
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
