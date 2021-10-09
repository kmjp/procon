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

int N,K;
int M;
int R[2020];
ll dp[1517][1517][2];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,K) R[i]=K+1;
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		R[x-1]=min(R[x-1],y);
	}
	vector<pair<int,int>> V;
	FOR(i,K) if(R[i]<K+1) {
		while(V.size()&&V.back().second>=R[i]) V.pop_back();
		V.push_back({i,R[i]});
	}
	dp[0][0][0]=1;
	FORR2(l,r,V) {
		FOR(x,r) FOR(y,x+1) {
			k=y+r-max(l,x);
			FOR(i,2) {
				(dp[r][k][i]+=dp[x][y][i^1])%=mo;
			}
		}
	}
	
	ll ret=0;
	FOR(y,K+1) {
		ll pat=0;
		FOR(x,1515) pat+=(dp[x][y][0]-dp[x][y][1]);
		(ret+=pat%mo*modpow(K-y,N))%=mo;
		
	}
	ret=(ret+mo)%mo;
	cout<<ret<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
