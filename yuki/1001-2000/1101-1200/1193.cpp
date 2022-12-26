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
int A[202020];
const ll mo=998244353;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(int P_,int Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==1) {
		cout<<0<<endl;
		return;
	}
	
	
	vector<int> V;
	FOR(i,N) {
		cin>>A[i];
		V.push_back(A[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	
	ll X=0,Y=0;
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		X+=bt(A[i]-1);
		Y+=bt(N)-bt(A[i]);
		bt.add(A[i],1);
	}
	
	ll pat=1;
	for(i=1;i<=N;i++) pat=pat*comb(N,i)%mo;
	//“¯ˆê‚È‚¢
	ll ret=0;
	for(i=2;i<=N;i++) {
		ll p=comb(N-2,i-2)*modpow(comb(N,i))%mo;
		(ret+=p*pat%mo*(Y%mo))%=mo;
	}
	for(i=1;i<=N;i++) {
		ll p=i*modpow(N)%mo;
		ll q=1LL*i*(i-1)/2%mo*modpow(N)%mo;
		(ret+=p*pat%mo*q%mo*((X+Y)%mo))%=mo;
	}
	
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
