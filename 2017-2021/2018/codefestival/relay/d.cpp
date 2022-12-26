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
int X[101010],W[101010];

pair<double,double> ok(double x) {
	double L=-1e9,R=1e9;
	int i;
	FOR(i,N) {
		L=max(L,X[i]-x/W[i]);
		R=min(R,X[i]+x/W[i]);
	}
	
	return {L,R};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>W[i];
	double L=0,R=1e15;
	FOR(i,100) {
		double M=(L+R)/2;
		auto v=ok(M);
		if(v.first<=v.second) R=M;
		else L=M;
	}
	auto v=ok(L);
	_P("%.12lf\n",v.first);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
