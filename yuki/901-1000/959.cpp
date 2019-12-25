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

ll H,W;
long double P;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>P;
	
	if(H>W) swap(H,W);
	
	if(W==1) {
		_P("%.12Lf\n",P);
	}
	else if(H==1) {
		long double A=2*P*P;
		long double B=(W-2)*P*P*P;
		_P("%.12Lf\n",A+B);
	}
	else {
		long double A=4*P*P*P;
		long double B=(2*(H-2)+2*(W-2))*P*P*P*P;
		long double C=(H-2)*(W-2)*P*P*P*P*P;
		_P("%.12Lf\n",A+B+C);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
