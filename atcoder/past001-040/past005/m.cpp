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

int N;
ll L,A[202020],S[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;
int dp[202020];

int ok(ll v) {
	if(v>L) return 0;
	ZERO(bt.bit);
	ZERO(dp);
	dp[N]=1;
	bt.add(N,1);
	for(int i=N-1;i>=0;i--) {
		ll a=S[i]+v;
		ll b=S[i]+L+1;
		int x=lower_bound(S,S+N+1,a)-S;
		int y=lower_bound(S,S+N+1,b)-S;
		dp[i]=(bt(y-1)-bt(x-1))>0;
		bt.add(i,dp[i]);
	}
	return dp[0];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,N) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	ll cur=0;
	for(i=50;i>=0;i--) if(ok(cur+(1LL<<i))) cur+=1LL<<i;
	cout<<cur<<endl;
}



int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
