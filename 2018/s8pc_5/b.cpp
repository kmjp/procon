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

int N,M;
double X[202],Y[202],R[202];

int ok() {
	int i,j;
	FOR(j,N+M) FOR(i,j) if(hypot(X[i]-X[j],Y[i]-Y[j])<R[i]+R[j]) return 0;
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	double RR=1e9;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>R[i];
		RR=min(RR,R[i]);
	}
	FOR(i,M) cin>>X[N+i]>>Y[N+i];
	
	double LL=0;
	FOR(i,200) {
		double MM=(LL+RR)/2;
		FOR(j,M) R[N+j]=MM;
		if(ok()) LL=MM;
		else RR=MM;
	}
	_P("%.12lf\n",LL);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
