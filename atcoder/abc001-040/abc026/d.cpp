#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int A,B,C;

long double val(long double t) {
	return A*t+B*sin(C*t*atan(1)*4);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	
	double L,R;
	FOR(i,5000000) {
		if(val(i/10000.0)<=100 && val((i+1)/10000.0)>=100) {
			L=i/10000.0;
			R=(i+1)/10000.0;
			break;
		}
	}
	FOR(i,100) {
		double M=(L+R)/2;
		if(val(M)<100) L=M;
		else R=M;
	}
	_P("%.10lf\n",L);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
