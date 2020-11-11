#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[51];
ll X;
ll ret;
map<ll,ll> memo[55];

ll dfs(int cur,ll lef) {
	if(cur==N-1) {
		return 1;
	}
	
	if(memo[cur].count(lef)) return memo[cur][lef];
	ll ret=0;
	
	ll step=A[cur+1]/A[cur];
	ll a=lef%step;
	
	if(a==0) {
		ret+=dfs(cur+1,lef/step);
	}
	else {
		ret+=dfs(cur+1,lef/step);
		ret+=dfs(cur+1,lef/step+1);
	}
	return memo[cur][lef]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	
	cout<<dfs(0,X)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
