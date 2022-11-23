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
int R[5555],C[5555];
const ll mo=998244353;


const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

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
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

ll memo[5050];
ll hoge(int v) {
	if(v==0) return 1;
	if(memo[v]>=0) return memo[v];
	ll ret=0;
	int i;
	for(i=2;i<=v;i++) {
		ll a=comb(v-1,i-1)*comb(v,i)%mo*fact[i]%mo*fact[i-1]%mo*hoge(v-i)%mo;
		ret+=a;
	}
	ret=ret%mo*(mo+1)/2%mo;
	ret+=v*hoge(v-1)%mo;
	return memo[v]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	MINUS(memo);
	
	cin>>N;
	int sum=0;
	int CC[2][3]={};
	FOR(i,N) {
		cin>>R[i];
		sum+=R[i];
		CC[0][R[i]]++;
	}
	FOR(i,N) {
		cin>>C[i];
		sum-=C[i];
		CC[1][C[i]]++;
	}
	if(sum) {
		cout<<0<<endl;
		return;
	}
	
	ll ret=0;
	for(int p=0;p<=min(CC[0][1],CC[1][1]);p++) {
		ll a=comb(CC[0][1],p)*comb(CC[1][1],p)%mo*fact[p]%mo;
		if((CC[0][1]-p)%2) continue;
		if((CC[1][1]-p)%2) continue;
		int L2=CC[0][2];
		int R2=CC[1][2];
		for(j=CC[0][1]-p;j>0;j-=2) {
			a=a*(j-1)%mo*R2%mo;
			R2--;
		}
		for(j=CC[1][1]-p;j>0;j-=2) {
			a=a*(j-1)%mo*L2%mo;
			L2--;
		}
		assert(L2==R2);
		for(int ins=0;ins<=L2;ins++) {
			ll b=comb(L2,ins)*comb(L2,ins)%mo*fact[ins]%mo*fact[ins]%mo;
			ret+=a*b%mo*hoge(L2-ins)%mo*hcomb((CC[0][1]+CC[1][1])/2,ins)%mo;
		}
		ret%=mo;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
