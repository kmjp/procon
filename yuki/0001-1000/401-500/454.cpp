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


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	double X;
	cin>>X;
	double ret=0;
	
	/*
	i=1200000000;
	X+=i;
	for(;i>=100;i-=3) {
		double a=(X*X);
		double b=(X-1)*(X-1);
		double c=(X-2)*(X-2);
		double ab=a*b;
		ret += (ab+c*(a+b))/(ab*c);
		X-=3;
	}
	for(;i>=1;i--) {
		ret += 1.0/(X*X);
		X--;
	}
	*/
	for(i=1;i<1000000;i++) {
		ret += 1/((X+i)*(X+i));
	}
	ret += 1/(X+i);
	
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
