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

ll N,P;
int mask;
ll p10[11];

ll dp[11][2][2][100];


ll hoge(int d,int le,int po,int m) {
	if(d==-1) {
		return m==0 && po;
	}
	if(dp[d][le][po][m]>=0) return dp[d][le][po][m];
	ll pat=0;
	int x=N/p10[d]%10;
	if(mask&(1<<d)) {
		if(po) pat=hoge(d-1,le | (x>0),po,m*10%P);
	}
	else {
		int i;
		for(i=1;i<=9;i++) {
			if(le==0 && i>x) continue;
			pat+=hoge(d-1,le | (i<x),1,(m*10+i)%P);
		}
		if(po==0) {
			pat+=hoge(d-1,le | (0<x),po,(m*10+0)%P);
		}
	}
	
	return dp[d][le][po][m]=pat;
}

int hoge(ll v) {
	int ret=0;
	while(v) {
		ret+=v%10==0;
		v/=10;
	}
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	
	p10[0]=1;
	FOR(i,10) p10[i+1]=p10[i]*10;
	ll ret=0;
	if(N/P<=100000000LL) {
		for(ll a=P;a<=N;a+=P) ret+=hoge(a);
	}
	else {
		for(mask=1;mask<1<<10;mask++) {
			MINUS(dp);
			ret+=__builtin_popcount(mask)*hoge(10,0,0,0);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
