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
int T[101010];
int X[101010];


double ok(double V) {
	int i,j;
	if(T[0]*V < abs(X[0])) return 0;
	
	set<pair<double,double>> S;
	S.insert({max(-1e8,-T[0]*V),min(1e8,T[0]*V)});
	
	for(i=1;i<N;i++) {
		double ma=-1e11;
		set<pair<double,double>> S2;
		FORR(r,S) {
			if(r.second<=ma) continue;
			
			double lp = r.first - (T[i]-T[i-1])*V;
			double rp = r.second + (T[i]-T[i-1])*V;
			if(lp<=X[i] && X[i]<=rp) {
				double lq = X[i-1] - (T[i]-T[i-1])*V;
				double rq = X[i-1] + (T[i]-T[i-1])*V;
				
				S2.insert({max(-1e8,lq),min(1e8,rq)});
			}
			if(abs(X[i]-X[i-1])<=(T[i]-T[i-1])*V) {
				S2.insert({max(-1e8,lp),min(1e8,rp)});
			}
			ma=max(ma,r.second);
		}
		swap(S,S2);
		if(S.empty()) return 0;
	}
	
	return 1;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i]>>X[i];
	double L=1e-10,R=1e10;
	FOR(i,70) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	_P("%.9lf\n",L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
