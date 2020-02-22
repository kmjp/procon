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

double P;

double tim(double x) {
	return x+P/pow(2,x/1.5);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P;
	double L=1e-10,R=1e20;
	FOR(i,300) {
		double m1=(L*2+R)/3;
		double m2=(R*2+L)/3;
		double v1=tim(m1);
		double v2=tim(m2);
		if(v1<v2) R=m2;
		if(v1>v2) L=m1;
		if(v1==v2) L=m1,R=m2;
		
	}
	_P("%.12lf\n",tim(L));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
