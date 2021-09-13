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

int K;
ll N,M;
ll A[201010];
ll L[201010],R[201010];

pair<ll,ll> hoge(ll v) {
	ll LS=0,RS=0;
	int i;
	FOR(i,K) {
		R[i]=(A[i]*M+v)/N;
		L[i]=(A[i]*M-v+N-1)/N;
		if(L[i]>R[i]) return {0,0};
		LS+=L[i];
		RS+=R[i];
	}
	
	return {LS,RS};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N>>M;
	FOR(i,K) cin>>A[i];
	
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) {
		auto p=hoge(ret-(1LL<<i));
		if(p.first<=M&&M<=p.second) ret-=1LL<<i;
	}
	
	auto p=hoge(ret);
	assert(p.first<=M&&M<=p.second);
	ll rem=M;
	FOR(i,K) {
		A[i]=L[i];
		rem-=A[i];
	}
	FOR(i,K) {
		ll lef=min(rem,R[i]-L[i]);
		A[i]+=lef;
		rem-=lef;
	}
	
	FOR(i,K) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
