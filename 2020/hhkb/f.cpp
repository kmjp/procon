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
int L[1010],R[1010];
const ll mo=1000000007;
vector<ll> V;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[2020][1010];
ll sum[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	V.push_back(0);
	FOR(i,N) {
		cin>>L[i]>>R[i];
		V.push_back(L[i]);
		V.push_back(R[i]);
	}
	
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	dp[0][1]=1;
	sum[0]=1;
	
	FOR(i,N) {
		L[i]=lower_bound(ALL(V),L[i])-V.begin();
		R[i]=lower_bound(ALL(V),R[i])-V.begin();
		ll tsum=0;
		FOR(x,V.size()) {
			ll pt=tsum;
			(tsum+=sum[x])%=mo;
			if(x>=L[i]&&x<R[i]) {
				ll le=V[x]-V[L[i]];
				ll m=V[x+1]-V[x];
				sum[x]=0;
				for(j=i;j>=1;j--) if(dp[x][j]) {
					(sum[x]+=dp[x][j]*(m+le))%=mo;
					(dp[x][j+1]+=dp[x][j]*m)%=mo;
					dp[x][j]=dp[x][j]*le%mo;
				}
				(dp[x][1]+=pt*m)%=mo;
				(sum[x]+=pt*m)%=mo;
			}
			else if(x<L[i] && sum[x]) {
				FOR(j,i+2) dp[x][j]=0;
				sum[x]=0;
			}
			else if(sum[x]) {
				FOR(j,i+2) if(dp[x][j]) (dp[x][j]*=V[R[i]]-V[L[i]])%=mo;
				(sum[x]*=V[R[i]]-V[L[i]])%=mo;
			}
		}
		
	}
	
	ll ret=0;
	FOR(i,V.size()-1) {
		FOR(x,N+1) if(dp[i][x]) {
			ll p=(V[i]+(V[i+1]-V[i])*x%mo*modpow(x+1))%mo;
			(ret+=p*dp[i][x])%=mo;
		}
	}
	for(i=1;i<=N+1;i++) ret=ret*i%mo;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
