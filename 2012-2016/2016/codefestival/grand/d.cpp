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

double P[6],Q[6];

double sc(double x) {
	double ret=0;
	int i;
	FOR(i,6) ret += max(P[i]*x,Q[i]*(1-x));
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,6) cin>>P[i], P[i]/=100;
	FOR(i,6) cin>>Q[i], Q[i]/=100;
	
	double L=0,R=1;
	FOR(i,200) {
		double M1=(L*2+R)/3;
		double M2=(L+R*2)/3;
		double V1=sc(M1);
		double V2=sc(M2);
		if(V1>=V2) L=M1;
		if(V1<=V2) R=M2;
	}
	_P("%.12lf\n",sc(L));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
