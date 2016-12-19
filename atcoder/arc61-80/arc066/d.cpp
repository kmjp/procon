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

ll N;
ll memo[77][5][5];
ll mo=1000000007;

ll dfs(int d,int xm,int am) {
	if(d<0) return 1;
	if(memo[d][xm][am]>=0) return memo[d][xm][am];
	
	ll ret=0;
	// 0 0
	if(N&(1LL<<d)) {
		ret += dfs(d-1,1,min(2,am*2+1));
	}
	else {
		ret += dfs(d-1,xm,min(2,am*2));
	}
	// 1 0
	if(N&(1LL<<d)) {
		ret += dfs(d-1,xm,min(2,am*2));
	}
	else {
		if(am && xm) ret += dfs(d-1,xm,min(2,am*2-1));
	}
	// 1 1
	if(am) {
		if(N&(1LL<<d)) {
			ret += dfs(d-1,1,min(2,am*2-1));
		}
		else {
			ret += dfs(d-1,xm,min(2,am*2-2));
		}
	}
	
	return memo[d][xm][am]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(memo);
	cout<<dfs(60,0,0)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
