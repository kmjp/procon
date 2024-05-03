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
int P[303030],R[303030];
const ll mo=998244353;

const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt,did,bt2;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	MINUS(R);
	cin>>N>>K;
	FOR(i,N) did.add(i,1);
	FOR(i,K) {
		cin>>P[i];
		P[i]--;
		R[P[i]]=i;
		did.add(P[i],-1);
		x=did(P[i]);
		//‰‰ñ‚Å“oê
		bt.add(i,fact[N-1-i]%mo*factr[N-K]%mo);
		//2‰ñ–ÚˆÈ~‚Å“oê
		if(i<K-1) {
			bt.add(i,1LL*(x-1)*(K-1-i)%mo*fact[N-2-i]%mo*factr[N-K]%mo);
		}
		bt2.add(i,x*fact[N-1-i]%mo*factr[N-K]%mo);
			
	}
	
	FOR(i,N) {
		if(R[i]==-1) {
			cout<<bt(K-1)%mo<<endl;
		}
		else {
			x=R[i];
			bt.add(x,mo-fact[N-1-x]%mo*factr[N-K]%mo);
			if(x<K-1) bt.add(x,(K-1-x)%mo*fact[N-2-x]%mo*factr[N-K]%mo);
			
			ll a=bt(x)+bt2(K)-bt2(x)+mo+1;
			cout<<a%mo<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
