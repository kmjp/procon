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
double P[101010],Q[101010];
int A[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i];
	FOR(i,N) cin>>Q[i];
	
	double L=0,R=1;
	FOR(i,100) {
		double M=(L+R)/2;
		double F=0;
		FOR(x,N) F+=P[x]*(1-Q[x])/(1-Q[x]*M);
		if(M<=F) L=M;
		else R=M;
	}
	
	double ret=0;
	FOR(i,N) {
		cin>>A[i];
		ret+=A[i]*log((1-Q[i])/(1-Q[i]*L));
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
