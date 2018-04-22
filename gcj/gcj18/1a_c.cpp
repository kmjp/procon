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

int T,testcase;
int N,P;
double ma[25050];

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	int tot=0;
	int W,H;
	FOR(i,25010) ma[i]=-1e10;
	ma[0]=0;
	FOR(i,N) {
		cin>>W>>H;
		tot+=2*W+2*H;
		int a=min(W,H);
		double b=hypot(W,H);
		for(j=25000-a;j>=0;j--) ma[j+a]=max(ma[j+a],ma[j]+b);
	}
	
	double best=tot;
	FOR(j,25001) if(tot+2*j<=P && ma[j]>=0) {
		double v=tot+2*ma[j];
		if(v>=P) best=P;
		else best=max(best,v);
	}
	
	return _P("Case #%d: %.12lf\n",TC,best);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
