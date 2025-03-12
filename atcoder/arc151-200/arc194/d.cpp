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
string S;
const ll mo=998244353;
const int NUM_=2000003;

static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

const int prime_max = 1010101;
vector<int> prime;
int NP,divp[prime_max];
int src;
void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

pair<ll,ll> hoge(int L,int R) {
	ll mul=1;
	map<ll,int> M;
	int tot=0;
	vector<ll> cand;
	if(L==R) {
		return {1,1};
	}
	int pre=L;
	int cur=0;
	int i;
	for(i=L;i<R;i++) {
		if(S[i]=='(') cur++;
		else if(S[i]==')') cur--;
		if(cur==0) {
			auto p=hoge(pre+1,i);
			pre=i+1;
			mul=mul*p.first%mo;
			M[p.second]++;
			tot++;
			cand.push_back(p.second);
		}
	}
	
	
	sort(ALL(cand));
	ll hash=1;
	FOR(i,cand.size()) hash=hash*(cand[i]+prime[i]+src)%mo;
	(mul*=fact[tot])%=mo;
	FORR2(a,b,M) (mul*=factr[b])%=mo;
	
	return {mul,hash};
	
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	src=rand()%101010+101;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>S;
	auto p=hoge(0,N);
	cout<<p.first<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
