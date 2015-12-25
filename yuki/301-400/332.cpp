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

ll N,X;
pair<int,int> P[101];
ll A[101];

int dp[220000];
char ok[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) cin>>P[i].first, P[i].second=i, ok[i]='x';
	sort(P,P+N);
	FOR(i,N) A[i]=P[i].first;
	
	ll sum=0;
	MINUS(dp);
	dp[0]=0;
	
	FOR(i,N) {
		if(sum+A[i]>=200000) break;
		for(j=sum;j>=0;j--) if(dp[j]>=0 && dp[j+A[i]]==-1) dp[j+A[i]]=i;
		sum+=A[i];
	}
	
	assert(N-i<=25);
	int low=i;
	for(int mask=0;mask<1<<(N-low);mask++) {
		ll t=0;
		FOR(i,N-low) if(mask&(1<<i)) t+=A[i+low];
		if(X-t<0 || X-t>200000) continue;
		
		if(dp[X-t]>=0) { 
			FOR(i,N-low) if(mask&(1<<i)) ok[P[i+low].second]='o';
			x=X-t;
			while(x) ok[P[dp[x]].second]='o', x-=A[dp[x]];
			return _P("%s\n",ok);
		}
	}
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
