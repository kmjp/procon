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

int K;
double E[100];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K;
	for(i=1;i<=30;i++) {
		E[10+i]=(E[10+i-1]+E[10+i-2]+E[10+i-3]+E[10+i-4]+E[10+i-5]+E[10+i-6])/6.0+1;
	}
	_P("%.12lf\n",E[10+K]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
