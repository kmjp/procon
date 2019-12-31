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

int T;
double XA,YA,RA;
double XB,YB,RB;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>XA>>YA>>RA;
		cin>>XB>>YB>>RB;
		double D=hypot(XA-XB,YA-YB);
		
		double X=0.5/RA;
		double r1=X-1/(RA+D-RB);
		double r2=X-1/(RA+D+RB);
		
		double x = sqrt(r1*r2);
		double r3 = 0.5/x;
		double a = 0.5/(x-r1);
		double b = 0.5/(x-r2);
		double r4 = abs(a-b);
		
		double dif=(r4-r3)/2;
		double at = asin(dif/(r3+dif));
		_P("%d\n",(int)(atan(1)*4/at));
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
