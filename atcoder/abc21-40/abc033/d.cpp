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
ll X[2101],Y[2101];
ll A,B,C;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	double pi=atan(1)*4;
	double eps=1e-10;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	int ret=0;
	FOR(x,N) {
		vector<long double> P;
		FOR(y,N) if(x!=y) P.push_back(atan2(Y[y]-Y[x],X[y]-X[x]));
		sort(ALL(P));
		FOR(i,N) P.push_back(P[i]+2*pi);
		int y=z=0;
		
		FOR(i,N-1) {
			while(P[y]-P[i]<pi/2-eps) y++;
			while(P[z]-P[i]<pi+eps) z++;
			if(fabs(P[i]+pi/2-P[y])<2*eps) B++,y++;
			C+=z-y;
		}
	}
	
	A=1LL*N*(N-1)*(N-2)/6-B-C;
	_P("%lld %lld %lld\n",A,B,C);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
