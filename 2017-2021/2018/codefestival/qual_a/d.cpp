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

ll D,T,F;
int N;
ll X[101010];
ll dp[101010];
ll p2[101010];
ll mo=1000000007;
template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	V add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>F>>T>>N;
	for(i=1;i<=N;i++) cin>>X[i];
	X[N+1]=D;
	X[N+2]=1LL<<60;
	dp[N+1]=1;
	bt.add(N+1,1);
	
	p2[0]=1;
	FOR(i,101000) p2[i+1]=p2[i]*2%mo;
	
	for(i=N;i>=0;i--) {
		ll L=X[i]+F-T+1;
		ll R=X[i]+F;
		x=lower_bound(X+i+1,X+N+2,L)-X;
		y=lower_bound(X+i+1,X+N+2,R+1)-X;
		if(x==N+2) x=N+1;
		y--;
		if(y<x) continue;
		dp[i]=((bt(y)-bt(x-1))%mo+mo)*p2[x-i-1]%mo;
		bt.add(i,dp[i]);
	}
	cout<<(bt(0)%mo)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
