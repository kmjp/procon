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

int N,M;
int A,B;
ll mo=1000000007;

map<int,ll> dpA[501];
map<int,ll> dpB[501];
map<int,ll> dp;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	cin>>A>>B;
	
	dpA[1][A]=1;
	for(y=1;y<=N/2;y++) {
		FORR(v,dpA[y]) {
			int x=v.first;
			if(x>1) (dpA[y+1][x-1]+=v.second)%=mo;
			(dpA[y+1][x]+=v.second)%=mo;
			if(x<M) (dpA[y+1][x+1]+=v.second)%=mo;
		}
	}
	
	
	dpB[N][B]=1;
	for(y=N;y>N/2+1;y--) {
		FORR(v,dpB[y]) {
			int x=v.first;
			if(y==N/2+2) {
				if(x>1) (dp[x-1]+=dpB[y][x]*dpA[y-1][x-1])%=mo;
				(dp[x]+=dpB[y][x]*dpA[y-1][x])%=mo;
				if(x<M) (dp[x+1]+=dpB[y][x]*dpA[y-1][x+1])%=mo;
			}
			else {
				if(x>1) (dpB[y-1][x-1]+=v.second)%=mo;
				(dpB[y-1][x]+=v.second)%=mo;
				if(x<M) (dpB[y-1][x+1]+=v.second)%=mo;
			}
		}
	}
	
	ll ret=0;
	FORR(a,dp) FORR(b,dp) if(a.first!=b.first) (ret+=a.second*b.second)%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
