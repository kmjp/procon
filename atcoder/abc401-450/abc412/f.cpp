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

int N,C;
int A[303030];
int S[3030];
const ll mo=998244353;
ll dp[3030];
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	ll NS=0;
	FOR(i,N) {
		cin>>A[i];
		NS+=A[i];
		S[A[i]]++;
	}
	C=A[C-1];
	S[C]--;
	S[C+1]++;
	
	for(i=3000;i>=C;i--) if(S[i+1]) {
		S[i+1]--;
		S[i]++;
		//•Ï‚¦‚Ä‚àˆÓ–¡‚ª‚È‚¢Šm—¦
		ll s=0;
		FOR(j,i+2) s+=j*S[j];
		s-=i;
		
		//ˆÓ–¡‚ª‚ ‚é‚Ü‚Å‚Éo‚é‰ñ”
		ll p=NS*modpow(NS-s)%mo;
		ll sum=i;
		dp[i]=p;
		for(j=i+2;j<=3001;j++) if(S[j]) {
			sum+=j*S[j];
			(dp[i]+=dp[j-1]*(j*S[j])%mo*modpow(NS-s))%=mo;
		}
		S[i+1]++;
		S[i]--;
	}
	cout<<dp[C]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
