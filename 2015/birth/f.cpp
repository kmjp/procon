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

int LL,N,K;
int X[101010],D[101010];

ll ok(long double v,int x) {
	ll ret=0;
	for(int i=0;i<N;i++) if(i!=x) {
		if(D[i]/v>1e10) return 1LL<<60;
		ret += ceil(D[i]/v)-1;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>LL>>N>>K;
	FOR(i,N) cin>>X[i];
	
	X[N]=LL;
	FOR(i,N) D[i]=X[i+1]-X[i];
	sort(D,D+N);
	
	long double L=0,R=1e10;
	FOR(i,70) {
		long double M=(L+R)/2;
		((ok(M,-1)<=K)?R:L)=M;
	}
	long double res=R;
	
	x=N-1;
	for(i=20;i>=0;i--) if(x-(1<<i)>=0 && ok(D[x-(1<<i)],x-(1<<i))<=K) x-=1<<i;
	
	L=0,R=1e10;
	FOR(i,70) {
		long double M=(L+R)/2;
		((ok(M,x)<=K)?R:L)=M;
	}
	res=min(res,(D[x]+R)/2);
	
	_P("%.12Lf\n",res);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
