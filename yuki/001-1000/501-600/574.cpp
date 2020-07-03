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

int F,N,K;
double fact[102];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	fact[0]=1.0;
	FOR(i,101) fact[i+1]=fact[i]*(i+1);
	
	cin>>F>>N>>K;
	double ret=0;
	for(i=1;i<=F;i++) {
		double prob=0;
		double A=(i-1.0)/F;
		double B=1.0/F;
		double C=1.0*(F-i)/F;
		
		FOR(x,N-K+1) FOR(y,K) {
			prob += pow(A,x)*pow(B,N-x-y)*pow(C,y)*(fact[N]/fact[x]/fact[y]/fact[N-x-y]);
		}
		
		ret += i*prob;
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
