#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,B;

int okok(ll X,ll Y) {
	if(A>X) return false;
	if(B<=Y) return true;
	double diag = sqrt(A*A+B*B)/2;
	double rad=2*atan2(A,B);
	double x=X/2.0,y=sqrt(diag*diag-x*x);
	double ny=y*cos(rad)+x*sin(rad);
	return 2*ny-0.000001<=Y;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B;
	if(A>B) swap(A,B);
	cin>>j;
	while(j--) {
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(okok(x,y)) _P("YES\n");
		else _P("NO\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
