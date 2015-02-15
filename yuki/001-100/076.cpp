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
double DP[1000057];
double S[7];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	S[1]=1.0/12;
	S[2]=2.0/12;
	S[3]=3.0/12;
	S[4]=1.0/12;
	S[5]=3.0/12;
	S[6]=2.0/12;
	
	for(i=1;i<=1000006;i++) {
		DP[i+10]=1+(DP[i+10-1]*S[1]+DP[i+10-2]*S[2]+DP[i+10-3]*S[3]+DP[i+10-4]*S[4]+DP[i+10-5]*S[5]+DP[i+10-6]*S[6]);
	}
	
	cin>>T;
	FOR(i,T) {
		cin>>x;
		_P("%.12lf\n",DP[x+10]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
