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


int T,N;
int L;
int D[202020];
const ll mo=998244353;
ll dp[3][202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>L;
		set<int> S;
		FOR(i,N) {
			cin>>D[i];
			S.insert(D[i]);
		}
		int p=0,q=N;
		FOR(i,N) if(L%2==0&&S.count(D[i]+L/2)) {
			p++;
			q-=2;
		}
		
		ll ret=0;
		if(p<2) {
			for(i=1;i<=N;i++) {
				(ret+=N*modpow(i))%=mo;
			}
		}
		else {
			for(i=1;i>=0;i--) {
				for(j=N;j>=0;j--) {
					if(2*p-i-j>0) dp[i][j]=(1+2*(p-j)*dp[i][j+1]%mo*modpow(N)+(j-i)*dp[i+1][j]%mo*modpow(N))%mo*N%mo*modpow(2*p-i-j)%mo;
				}
			}
			ret=dp[0][0];
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
