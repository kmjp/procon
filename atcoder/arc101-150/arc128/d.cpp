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
int A[202020];
const ll mo=998244353;
int fix[202020];
int nex[202020];
int V[202020];


template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<int,20> bt;

ll dp[202020];
int repeat[202020];

ll hoge(int L,int R) {
	if(L+1>=R) return 1;
	
	dp[L]=1;
	bt.add(L,1);
	bt.add(L+1,mo-1);
	for(int i=L;i<R;i++) {
		dp[i]=bt(i);
		
		if(repeat[i]>=2) {
			bt.add(i+1,dp[i]);
			bt.add(R+1,mo-dp[i]);
			bt.add(i+3,mo-dp[i]);
			bt.add(min(i+1+repeat[i]+1,R+1),dp[i]);
		}
		else {
			bt.add(i+1,dp[i]);
			bt.add(R+1,mo-dp[i]);
		}
	}
	//cout<<L<<R<<bt(R)<<endl;
	return bt(R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	
	FOR(i,N+1) V[i]=N;
	for(i=N-1;i>=0;i--) {
		nex[i]=V[A[i]];
		V[A[i]]=i;
	}
	
	for(i=N-2;i>=0;i--) {
		if(A[i]==A[i+2]) {
			repeat[i]=repeat[i+1]+1;
		}
	}
	
	
	FOR(i,N) {
		if(i==0||i==N-1) fix[i]=1;
		else if(A[i]==A[i-1]||A[i]==A[i+1]) fix[i]=1;
	}
	int pre=-1;
	ll ret=1;
	FOR(i,N) {
		if(fix[i]==1) {
			if(pre!=-1) ret=ret*hoge(pre,i)%mo;
			pre=i;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
