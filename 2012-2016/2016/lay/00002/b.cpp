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
int N;
double dp[301];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0]=1;
	for(i=1;i<=200;i++) {
		if(i>=100) dp[i]=1+dp[i-10];
		else {
			dp[i]=1+i*dp[max(0,i-10)]/100.0;
		}
		
	}
	
	
	cin>>T;
	while(T--) {
		cin>>N;
		if(N<=200) {
			_P("%.12lf\n",dp[N]);
		}
		else {
			int cnt=(N-150)/10;
			_P("%.12lf\n",cnt + dp[N-cnt*10]);
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
