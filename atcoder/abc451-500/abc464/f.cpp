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
ll X;
ll A[40];
const ll mo=998244353;
ll R[41];

const int NUM_=2000003;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];


vector<ll> AA[21],BB[21];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>X;
	FOR(i,N) cin>>A[i];
	
	
	int L=N/2;
	int R=N-L;
	int mask;
	FOR(mask,1<<L) {
		ll sum=0;
		FOR(i,L) if(mask&(1<<i)) sum+=A[i];
		AA[__builtin_popcount(mask)].push_back(sum);
	}
	FOR(i,L+1) sort(ALL(AA[i]));
	ll ret=0;
	FOR(mask,1<<R) {
		ll sum=0;
		ll lef=0;
		x=__builtin_popcount(mask);
		FOR(i,R) {
			if(mask&(1<<i)) sum+=A[L+i];
			else lef+=A[L+i];
		}
		lef%=mo;
		if(sum<X) {
			FOR(j,L+1) {
				y=lower_bound(ALL(AA[j]),X-sum)-AA[j].begin();
				(ret+=fact[x+j]*y%mo*fact[N-(x+1+j)]%mo*lef)%=mo;
			}
		}
		BB[x].push_back(sum);
	}
	FOR(i,R+1) sort(ALL(BB[i]));
	FOR(mask,1<<L) {
		ll sum=0;
		ll lef=0;
		FOR(i,L) {
			if(mask&(1<<i)) sum+=A[i];
			else lef+=A[i];
		}
		lef%=mo;
		x=__builtin_popcount(mask);
		if(sum<X) {
			FOR(j,R+1) {
				y=lower_bound(ALL(BB[j]),X-sum)-BB[j].begin();
				(ret+=fact[x+j]*y%mo*fact[N-(x+1+j)]%mo*lef)%=mo;
			}
		}
	}
	cout<<ret*factr[N]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
