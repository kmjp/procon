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
const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll P_,ll Q_) {
	if(P_<0 || Q_<0 || Q_>P_) return 0;
	ll p=1,q=1;
	Q_=min(Q_,P_-Q_);
	P_%=mo;
	for(int i=1;i<=Q_;i++) p=p*P_%mo, q=q*i%mo,P_--;
	
	return p*modpow(q,mo-2)%mo;
}

ll cand[8][17];

void solve() {
	int i,j,k,l,r,x,y; string s;

	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		
		ll p4=modpow(4,N-1);
		ll p3=modpow(3,N-1);
		ll p2=modpow(2,N-1);
		
		
		// popcount‚ª2‚Ì‚à‚Ì‚ª‚È‚¢
		ll ret=modpow(M+1,N-1);
		// popcount‚ª2‚Ì‚à‚Ì‚ª1‚Â
		(ret+=comb(M,2)*(p4-p3))%=mo;
		// popcount‚ª2‚Ì‚à‚Ì‚ª2ŒÂˆÈã‚ ‚èA‹¤’Ê•”•ª‚ª‚È‚¢
		(ret+=comb(M,3)*(p4-3*p3+3*p2-1))%=mo;
		// popcount‚ª2‚Ì‚à‚Ì‚ª2ŒÂˆÈã‚ ‚èA‹¤’Ê•”•ª‚ª‚ ‚é
		(ret+=M*(modpow(M+1,N-1)-p2-(M-1)*(p3-p2)%mo))%=mo;
		
		ret=(ret*modpow(2,M)%mo+mo)%mo;
		cout<<ret<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
