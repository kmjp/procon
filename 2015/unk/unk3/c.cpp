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

int N;
double A;
ll X[101000];
double R[101000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	FOR(i,N) cin>>X[i];
	
	double c=0;
	for(i=1;i<N;i++) {
		c = pow(A,X[i]-X[i-1])*(c+1);
		R[i] += c;
	}
	c=0;
	for(i=N-2;i>=0;i--) {
		c = pow(A,X[i+1]-X[i])*(c+1);
		R[i] += c;
	}
	
	FOR(i,N) _P("%.12lf\n",R[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
