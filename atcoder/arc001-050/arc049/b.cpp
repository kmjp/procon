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
int X[1010],Y[1010],C[1010];

int ok(double v) {
	int i;
	double L=-1e9;
	double R=1e9;
	double T=-1e9;
	double B=1e9;
	
	FOR(i,N) {
		double d=v/C[i];
		L=max(L,X[i]-d);
		R=min(R,X[i]+d);
		T=max(T,Y[i]-d);
		B=min(B,Y[i]+d);
	}
	
	if(L>R) return 0;
	if(T>B) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>C[i];
	
	double L=0,R=1e9;
	FOR(i,200) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	_P("%.12lf\n",L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
