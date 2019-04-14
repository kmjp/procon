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
long double P[21],Q[21];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q[0]>>P[0];
	
	if(Q[0]==1) return _P("1\n");
	
	long double CP=1,CQ=0;
	FOR(i,20) {
		if(N&(1<<i)) {
			double PP=CP,PQ=CQ;
			CP=PP*P[i]/(1-PQ*Q[i]);
			CQ=PQ+Q[i]*PP*PP/(1-PQ*Q[i]);
		}
		P[i+1]=P[i]*P[i]/(1-Q[i]*Q[i]);
		Q[i+1]=Q[i]+Q[i]*P[i]*P[i]/(1-Q[i]*Q[i]);
	}
	
	_P("%.12lf\n",(double)CQ);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
