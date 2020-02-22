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

int N,K,M;
int A[252525];
int cnt[404];
ll mo=1000000007;

ll dp[25205][2][404], dp2[2][404];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	FOR(i,M) cin>>A[i], A[i]--;
	
	ll tot=(N-M+1);
	FOR(i,N-M) (tot*=K)%=mo;
	
	for(i=0;i+K<=M;i++) {
		ZERO(cnt);
		int ok=0;
		for(j=i;j<i+K;j++) if(++cnt[A[j]]==2) ok++;
		if(ok==0) {
			cout<<tot<<endl;
			return;
		}
	}
	
	
	dp[1][0][1]=K;
	dp[1][M==1][1]=K;
	for(i=2;i<=N;i++) {
		ZERO(dp2);
		for(j=1;j<K;j++) {
			(dp[i][0][j+1]+=(K-j)*dp[i-1][0][j])%=mo;
			(dp[i][1][j+1]+=(K-j)*dp[i-1][1][j])%=mo;
			dp2[0][1]+=dp[i-1][0][j];
			dp2[0][j+1]+=mo-dp[i-1][0][j];
			dp2[1][1]+=dp[i-1][1][j];
			dp2[1][j+1]+=mo-dp[i-1][1][j];
		}
		
		for(j=1;j<K;j++) {
			dp2[0][j]+=dp2[0][j-1];
			(dp[i][0][j]+=dp2[0][j])%=mo;
			dp2[1][j]+=dp2[1][j-1];
			(dp[i][1][j]+=dp2[1][j])%=mo;
			if(j>=M) (dp[i][1][j]+=dp[i][0][j])%=mo;
		}
	}
	ZERO(cnt);
	FOR(i,M) cnt[A[i]]++;
	FOR(i,K) if(cnt[i]>1) break;
	
	ll ret=0;
	if(i<K) {
		int F,B;
		set<int> S;
		FOR(F,M) {
			if(S.count(A[F])) break;
			S.insert(A[F]);
		}
		S.clear();
		FOR(B,M) {
			if(S.count(A[M-1-B])) break;
			S.insert(A[M-1-B]);
		}
		for(int L=0;L<=N-M;L++) {
			int R=N-M-L;
			ll LP=0,RP=0;
			for(j=F;j<K;j++) LP+=dp[L+F][0][j];
			for(j=B;j<K;j++) RP+=dp[R+B][0][j];
			LP%=mo;
			RP%=mo;
			ll LM=1,RM=1;
			for(i=K-F+1;i<=K;i++) LM=LM*i%mo;
			for(i=K-B+1;i<=K;i++) RM=RM*i%mo;
			(ret += (LP*modpow(LM))%mo*(RP*modpow(RM)%mo))%=mo;
		}
		
	}
	else {
		// no same
		for(j=1;j<K;j++) ret+=dp[N][1][j];
		ret%=mo;
		ll di=1;
		for(i=K-M+1;i<=K;i++) di=di*i%mo;
		ret=ret*modpow(di)%mo;
		
		
		
	}
		cout<<(tot-ret+mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
