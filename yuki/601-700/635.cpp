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
long double X[3],Y[3];

int hoge(long double t) {
	double a=X[0]+t*Y[0];
	double b=X[1]+t*Y[1];
	double c=X[2]+t*Y[2];
	if(t<0) return 0;
	
	if(abs(a-b)<1e-12) return 0;
	if(abs(a-c)<1e-12) return 0;
	if(abs(b-c)<1e-12) return 0;
	if(a>b && c>b) return 1;
	if(a<b && c<b) return 1;
	return 0;
}

int ok() {
	
	if(X[0]==X[1] && Y[0]==Y[1]) return 0;
	if(X[0]==X[2] && Y[0]==Y[2]) return 0;
	if(X[1]==X[2] && Y[1]==Y[2]) return 0;
	if(hoge(0)) return 1;
	if(hoge(1<<30)) return 1;
	
	int C[2]={};
	double T=0;
	if(X[0]==X[1] && hoge(1e-5)) return 1;
	if(Y[0]!=Y[1]) {
		T=1.0*(X[1]-X[0])/(Y[0]-Y[1]);
		if(hoge(T+(1e-5))) return 1;
		if(hoge(T-(1e-5))) return 1;
	}
	if(X[2]==X[1] && hoge(1e-4)) return 1;
	if(Y[2]!=Y[1]) {
		T=1.0*(X[1]-X[2])/(Y[2]-Y[1]);
		if(hoge(T+(1e-5))) return 1;
		if(hoge(T-(1e-5))) return 1;
	}
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	while(N--) {
		cin>>X[0]>>X[1]>>X[2]>>Y[0]>>Y[1]>>Y[2];
		
		if(ok()) _P("YES\n");
		else _P("NO\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
