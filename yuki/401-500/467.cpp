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
ll D[1010];
ll X,Y,Z;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>D[i];
	sort(D,D+N);
	cin>>X>>Y;
	X=abs(X);
	Y=abs(Y);
	if(X<Y) swap(X,Y);
	
	if(X==0 && Y==0) return _P("0\n");
	
	FOR(i,N) if(D[i]==X) return _P("1\n");
	if(X<D[N-1]) return _P("2\n");
	_P("%lld\n",(X+D[N-1]-1)/D[N-1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
