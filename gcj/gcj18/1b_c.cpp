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

int T,testcase;
int M;
int R[101][2];
ll G[101];
ll A[101];
ll lp[101];

int dfs(int cur,ll need) {
	if(lp[cur]) return 0;
	
	if(A[cur]>=need) {
		A[cur]-=need;
		return 1;
	}
	
	need-=A[cur];
	A[cur]=0;
	lp[cur]=1;
	
	if(dfs(R[cur][0],need) && dfs(R[cur][1],need)) {
		lp[cur]=0;
		return 1;
	}
	return 0;
	
}


int ok(ll v) {
	int i;
	FOR(i,M) A[i]=G[i];
	ZERO(lp);
	
	return dfs(0,v);
}

void solve(int TC) {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) {
		cin>>R[i][0]>>R[i][1];
		R[i][0]--;
		R[i][1]--;
	}
	FOR(i,M) cin>>G[i];
	
	ll ret=0;
	for(int i=40;i>=0;i--) if(ok(ret+(1LL<<i))) ret+=1LL<<i;
	
	_P("Case #%d: %lld\n",TC, ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0);
	
	cin>>T;
	for(testcase=1;testcase<=T;testcase++) solve(testcase);
	return 0;
}
