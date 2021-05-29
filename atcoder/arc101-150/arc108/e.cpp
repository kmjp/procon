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
int A[2020],B[2020];
ll dp[2020][2020];
const ll mo=1000000007;


template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) {ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,12> S[2020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	FOR(i,N) {
		cin>>A[i+1];
		B[A[i+1]]=i+1;
	}
	A[N+1]=B[N+1]=N+1;
	FOR(i,N+2) {
		k=B[i];
		BIT_mod<ll,12> num;
		for(j=i-1;j>=0;j--) {
			
			x=B[j];
			int n=num(k-1)-num(x);
			if(n>0) {
				dp[x][k]+=(2*mo+S[x](k-1)-S[x](x)+S[k](k-1)-S[k](x))%mo;
				dp[x][k]=(dp[x][k]*modpow(n)+1)%mo;
				S[x].add(k,dp[x][k]);
				S[k].add(x,dp[x][k]);
			}
			num.add(x,1);
		}
	}
	cout<<dp[0][N+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
