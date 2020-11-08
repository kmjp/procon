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

int N;
ll X[101010],Y[101010];
ll TX=(1LL<<58);
map<pair<ll,ll>,int> memo[1<<20];

int lucas(ll N,ll K) { // C(N,K)‚Ì‹ôŠï
	if(K<0 || K>N) return 0;
	return ((~N)&K)==0;
}


ll black(ll BY) {
	int b=0;
	int i;
	FOR(i,N) b^=lucas(TX-X[i]-Y[i],BY-Y[i]);
	return b;
}

int hoge2(ll P,ll Q) {
	if(P==0||Q<=0) return 0;
	if(memo[(P^Q)&(0xFFFFF)].count({P,Q})) return memo[(P^Q)&(0xFFFFF)][{P,Q}];
	ll v=1;
	while(v*2<=P) v*=2;
	
	if(P==v) {
		int a=(Q/3+(Q%3>=1))%2;
		int b=(Q/3+(Q%3>=2))%2;
		int c=(Q/3)%2;
		return a|(b<<1)|(c<<2);
	}
	
	ll R=P-v;
	int ret=hoge2(R,min(Q,R));
	if(Q>v) {
		int ret2=hoge2(R,Q-v);
		int slide=v%3;
		ret2=((ret2<<slide)|(ret2>>(3-slide)))&7;
		ret^=ret2;
	}
	return memo[(P^Q)&(0xFFFFF)][{P,Q}]=ret;
}

int hoge(int tar,ll upY) {
	ll cx=TX-X[tar]-Y[tar];
	ll cy=upY-Y[tar];
	if(cy<0) return 0;
	cy=min(cy,cx);
	int ret=hoge2(cx+1,cy+1);
	int slide=(Y[tar]%3+3)%3;
	ret=((ret<<slide)|(ret>>(3-slide)))&7;
	return ret;
	
}

int num(ll upY) {
	static map<ll,int> memo;
	if(memo.count(upY)) return memo[upY];
	int ret=0;
	int i;
	FOR(i,N) ret^=hoge(i,upY);
	return memo[upY]=ret;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	x=num(1LL<<59);
	assert(x);
	FOR(i,3) if(x&(1<<i)) y=1<<i;
	ll L=-1LL<<57,R=1LL<<59;
	while(L+1<R) {
		ll M=(L+R)/2;
		if((num(L)^num(M))&y) {
			R=M;
		}
		else {
			L=M;
		}
	}
	L=R;
	assert(black(L));
	for(i=60;i>=0;i--) {
		if(black(R+(1LL<<i))) R+=1LL<<i;
		if(black(L-(1LL<<i))) L-=1LL<<i;
	}
	cout<<(TX-R)<<" "<<L<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
