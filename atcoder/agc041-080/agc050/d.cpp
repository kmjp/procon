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
const ll mo=998244353;
ll dp[41][41][41][41];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll hoge(int turn,int pre,int suf,int cur) {
	//cout<<turn<<" "<<pre<<" "<<suf<<" "<<cur<<" "<<endl;
	if(dp[turn][pre][suf][cur]>=0) return dp[turn][pre][suf][cur];
	ll ret=0;

	int ball=K-(N-(1+pre+suf));
	int cand=K-turn;
	
	if(ball<=0) return 0;
	
	ll ok=ball*modpow(cand)%mo;
	ll ng=(mo+1-ok)%mo;
	
	if(ball>=cand) ok=1,ng=0;
	
	if(cur==pre) {
		ret=ok;
		if(ng) ret+=ng*hoge(turn,pre,suf,cur+1)%mo;
	}
	else if(cur==pre+1+suf) {
		ret=hoge(turn+1,pre,suf,0);
	}
	else if(cur<pre) {
		// pre or suf
		ret=ok*hoge(turn,pre-1,suf,cur);
		if(ng) ret+=ng*hoge(turn,pre,suf,cur+1)%mo;
	}
	else {
		ret=ok*hoge(turn,pre,suf-1,cur);
		if(ng) ret+=ng*hoge(turn,pre,suf,cur+1)%mo;
	}
	
	
	
	return dp[turn][pre][suf][cur]=(ret%mo+mo)%mo;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	MINUS(dp);
	
	FOR(i,N) {
		cout<<hoge(0,i,N-(i+1),0)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
