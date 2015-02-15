#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
double X[6],Y[6];
double x,y;

void solve() {
	int i,j,k,l,r; string s;
	cin>>T;

	while(T--) {
		double pi=M_PI;
		FOR(i,6) {
			cin>>X[i]>>Y[i];
			if(Y[i]>=-1e-9 && X[i]>cos(50*pi/180)-(1e-9)) _P("%.12lf\n",atan2(Y[i],X[i])*180/pi);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
