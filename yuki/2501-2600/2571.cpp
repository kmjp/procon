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

int N,M,K,Q;
ll A[202020];
ll P[202020];

const ll mo=998244353;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BIT_mod {
public:
	V bit[1<<ME];
	BIT_mod(){ZERO(bit);};
	V operator()(int e) { if(e<0) return 0; ll s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s%mo;}
	void add(int e,V v) { e++; v=(v%mo+mo)%mo; while(e<=1<<ME) { bit[e-1]+=v; bit[e-1] -= (bit[e-1]>=mo)?mo:0; e+=e&-e;}}
};
BIT_mod<ll,20> bt,bt2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>Q;
	P[0]=1;
	FOR(i,201010) P[i+1]=P[i]*M%mo;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		bt.add(i+1,A[i]*P[N-1-i]%mo);
		bt2.add(i+1,A[i]);
	}
	while(Q--) {
		cin>>i;
		if(i==1) {
			int L,R;
			cin>>L>>R;
			
			if(M==1) {
				cout<<R+L-1<<endl;
			}
			else {
				ll a=mo+bt(R)-bt(L-1);
				a=a*modpow(M,K-N+L)%mo;
				a+=mo-(bt2(R)-bt2(L-1));
				a=a%mo*modpow(M-1)%mo;
				a+=(R-L+1);
				cout<<a%mo<<endl;
			}
		}
		else {
			cin>>x>>y;
			x--;
			bt.add(x+1,mo-A[x]*P[N-1-x]%mo);
			bt2.add(x+1,mo-A[x]);
			A[x]=y-1;
			bt.add(x+1,A[x]*P[N-1-x]%mo);
			bt2.add(x+1,A[x]);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
