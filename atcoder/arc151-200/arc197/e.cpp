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
ll N,H,W;
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;
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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>H>>W;
		
		if(H<2*N||W<2*N) {
			cout<<0<<endl;
			continue;
		}
		ll ret=0;
		ll spW=W-2*N;
		ll spH=H-2*N;
		
		ll sw2=comb(spW+2,2);
		ll sh2=comb(spH+2,2);
		//—×“¯Žm‚ªd‚È‚ç‚È‚¢ðŒ
		(ret+=sw2*sw2%mo*sh2%mo*sh2%mo)%=mo;
		//—×“¯Žm‚ªd‚È‚ç‚È‚¢‚ªŽÎ‚ß“¯Žm‚ªd‚È‚éƒP[ƒX
		ll sw4=comb(spW+3,4);
		ll sh4=comb(spH+3,4);
		(ret-=sw4*sh4*2)%=mo;
		ret=(ret%mo+mo)%mo;
		
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
