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

int N,K;
ll T[202020],D[202020];
int NG[202020];
ll dp[202020];


int ok(int can) {
	int pre=-1<<30;
	int i;
	FOR(i,N) if(D[i]>can) {
		if(T[i]-pre<K) return 0;
		pre = T[i];
	}
	return 1;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>T[i]>>D[i];
	
	int ma=(1<<30)-1;
	for(int i=29;i>=0;i--) if(ok(ma-(1<<i))) ma-=1<<i;
	cout<<ma<<endl;
	
	ll pre=-1LL<<40;
	FOR(i,N) {
		if(D[i]>ma) pre = T[i];
		else if(T[i]-pre<K) NG[i]=1;
	}
	pre=1LL<<40;
	for(i=N-1;i>=0;i--) {
		if(D[i]>ma) pre = T[i];
		else if(pre-T[i]<K) NG[i]=1;
	}
	
	ll sum=0;
	FOR(i,N) {
		if(D[i]>ma) {
			D[i]=0;
		}
		else {
			sum+=D[i];
			if(NG[i]) D[i]=0;
		}
	}
	
	ll tma=0;
	x=0;
	FOR(i,N) {
		while(T[i]-T[x]>=K) tma=max(tma,dp[++x]);
		dp[i+1]=max(dp[i], tma+D[i]);
	}
	
	cout<<sum-dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
