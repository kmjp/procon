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

ll L=1000000,R=100000;

int ask(double x,double y,bool round=false) {
	char result[10];
	if(round) {
		printf("%lld %lld\n", (ll)(0.1+x), (ll)(0.1+y));
	}
	else {
		printf("%.9f %.9f\n", x, y);
	}
	fflush(stdout);
	scanf("%s", result);
	
	if(strcmp(result,"found")==0) exit(0);
	return strcmp(result,"close")==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll S=R*5/4, D=S/2;
	
	ll X,Y;
	for(X=D;X<L;X+=S) for(Y=D;Y<L;Y+=S) if(ask(X,Y,true)) goto out;
	assert(0);
	out:
	double XL=X,XR=X;
	double d=1e6;
	FOR(i,60) {
		if(ask(XR+d,Y)) XR+=d;
		if(ask(XL-d,Y)) XL-=d;
		d/=2;
	}
	double XC=(XL+XR)/2;
	double DY=sqrt(R*R-(XC-XL)*(XC-XL));
	ask(XC,Y-DY,true);
	ask(XC,Y+DY,true);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
