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

int T;
ll N,M;
ll X[202020],S[202020];
int NZ[202020];
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		int nm=0;
		cin>>N>>M;
		ll sum=0;
		FOR(i,N) {
			cin>>X[i];
			S[i+1]=S[i]+X[i];
			NZ[i+1]=NZ[i];
			if(X[i]==-1) NZ[i+1]++;
		}
		if(NZ[N]==0) {
			int ret=0;
			if(S[N]%M==0) {
				FOR(i,N) {
					if(S[i+1]%M) ret++;
				}
			}
			cout<<ret<<endl;
			continue;
		}
		sum=0;
		ll ret=0;
		for(i=1;i<N;i++) {
			if(NZ[i]==0) {
				if(S[i]%M) ret+=modpow(M,NZ[N]-1);
			}
			else if(NZ[N]-NZ[i]==0) {
				if((S[N]-S[i])%M) ret+=modpow(M,NZ[N]-1);
			}
			else {
				(ret+=(M-1)*modpow(M,NZ[N]-2))%=mo;
			}
		}
		
		
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
