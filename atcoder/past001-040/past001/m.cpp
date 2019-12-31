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

int N,M,A,B;
ll ma[6][504040];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(x,6) FOR(y,504000) ma[x][y]=-1<<30;
	ma[0][0]=0;
	FOR(i,N) {
		cin>>A>>B;
		for(j=4;j>=0;j--) for(x=0;x<=j*100000;x++) if(ma[j][x]>=0) ma[j+1][x+A]=max(ma[j+1][x+A],ma[j][x]+B);
	}
	
	double ret=0;
	FOR(i,M) {
		cin>>A>>B;
		for(x=0;x<=400000;x++) if(ma[4][x]>=0) {
			ret=max(ret,(B+ma[4][x])/(1.0*(A+x)));
		}
	}
	for(x=0;x<=500000;x++) if(ma[5][x]>=0) ret=max(ret,1.0*ma[5][x]/x);
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
