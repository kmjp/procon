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


int N,S,I;
ll A[101010],L[101010];
ll my;
int U[101010];

ll sc(int r) {
	return 50LL*S+500LL*S/(8+2*r);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>I;
	FOR(i,N) {
		cin>>A[i];
		if(I==i) {
			my=A[i]+100*S;
			i--;
			N--;
			I=-1;
		}
	}
	sort(A,A+N);
	reverse(A,A+N);
	double ret=1;
	FOR(i,N) {
		ll left=my-A[i];
		if(left < sc(N)) return _P("0\n");
		x = N;
		for(j=20;j>=0;j--) if(x-(1<<j)>=1 && sc(x-(1<<j))<=left) x -= (1<<j);
		int ok=N-x+1;
		if(ok<i) return _P("0\n");
		ret *= (ok-i)*1.0/(N-i);
	}
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
