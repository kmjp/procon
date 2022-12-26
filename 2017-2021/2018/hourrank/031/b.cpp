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
ll A[10100];

int ok(double v) {
	int lef=N;
	int k=K;
	int i;
	while(k&&A[k-1]>=v) {
		k--,lef--;
	}
	if(lef==0) return 1;
	double sum=0;
	FOR(i,k) sum+=A[i];
	return (sum>=lef*v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) cin>>A[i];
	sort(A,A+K);
	
	double L=0,R=1e10;
	FOR(i,100) {
		double M=(L+R)/2;
		if(ok(M)) L=M;
		else R=M;
	}
	
	_P("%.12lf\n",L);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
