#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll N,X;
const ll mo=998244353;

ll dp[21][301010];

int check(int a,int b,int k) {
	ll v=X;
	for(int i=k-1;i>=1;i--) {
		ll x=dp[i][a]-dp[i][b];
		ll w=min({9LL,v/x,b-1LL});
		if(i==k-1&&w==0) return 0;
		v-=x*w;
	}
	if(v==0) return min(10,b);
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	ll ret=0;
	
	for(i=1;i<=300000;i++) {
		dp[0][i]=1;
		FOR(j,19) dp[j+1][i]=dp[j][i]*i;
	}
	
	// k=2;
	for(i=1;i<=9;i++) FOR(j,10) if(X%i==0) {
		ll d=X/i;
		int mi=max(i+1,j+1)+d;
		if(mi<=N) (ret+=N-mi+1)%=mo;
	}
	
	ll num=0;
	for(k=3;k<=20;k++) {
		for(ll a=2;a<=N;a++) {
			if(dp[k-1][a]-dp[k-1][a-1]>X) break;
			for(ll b=a-1;b>=2;b--) {
				if(dp[k-1][a]-dp[k-1][b]>X) break;
				if(X%(a-b)==0) ret+=check(a,b,k);
			}
		}
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
