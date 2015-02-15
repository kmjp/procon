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

int H,A,D;
double memo[10010];

double dp(int C) {
	if(C<=0) return 0;
	if(memo[C]>=0) return memo[C];
	return memo[C]=min(1+dp(C-A),1.5+dp(C-D));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>H>>A>>D;
	
	FOR(i,H+1) memo[i]=-1;
	_P("%.12lf\n",dp(H));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
