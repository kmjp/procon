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

int N,K;
ll W[1010],P[1010];

int ok(double v) {
	int i;
	vector<pair<double,int>> V;
	FOR(i,N) V.push_back({(P[i]-v)*W[i],i});
	sort(V.begin(),V.end());
	reverse(V.begin(),V.end());
	ll t0=0,t1=0;
	FOR(i,K) {
		t0+=W[V[i].second];
		t1+=P[V[i].second]*W[V[i].second];
	}
	
	return t1>=t0*v;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>W[i]>>P[i];
	
	double L=0,R=100;
	FOR(i,200) {
		double M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
		
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
