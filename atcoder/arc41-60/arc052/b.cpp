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

int N,Q;
int X[101],R[101],H[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>N>>Q;
	FOR(i,N) cin>>X[i]>>R[i]>>H[i];
	while(Q--) {
		int a,b;
		cin>>a>>b;
		
		double ret=0;
		FOR(i,N) {
			if(b<X[i]) continue;
			if(a>=X[i]+H[i]) continue;
			double S1,S2;
			
			x=max(0,a-X[i]);
			y=min(H[i],b-X[i]);
			double a1=(H[i]-x)*1.0/H[i]*R[i];
			double a2=(H[i]-y)*1.0/H[i]*R[i];
			ret += (y-x)/3.0*pi*(a1*a1+a1*a2+a2*a2);
			
		}
		_P("%.12lf\n",ret);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
