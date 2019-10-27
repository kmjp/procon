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

double A,B,X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>A>>B>>X;
	
	X/=A;
	
	if(X<=B*A/2) {
		double C=2*X/B;
		double d=atan2(B,C);
		d=d/pi*180;
		_P("%.12lf\n",d);
	}
	else {
		double d=atan2(2*(B-X/A),A);
		d=d/pi*180;
		_P("%.12lf\n",d);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
