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

int N,Q;
int H[202020];
const ll mo=998244353;
int A[202020],B[202020];

std::random_device rnd;
std::mt19937 mt(rnd());
std::uniform_int_distribution<int> dist(1, 998244352);

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> sumA,sumB;

template<class V, int ME> class BITm {
public:
	V bit[1<<ME];
	BITm(){ for(int i=0;i<1<<ME;i++) bit[i]=1;}
	V operator()(int e) {if(e<0) return 0;V s=1;e++;while(e) (s*=bit[e-1])%=mo,e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]*=v)%=mo,e+=e&-e;}
};
BITm<ll,20> mulA,mulB;



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	H[0]=1;
	for(i=1;i<=200000;i++) {
		H[i]=dist(mt);
	}
	
	cin>>N>>Q;
	FOR(i,N) {
		cin>>A[i];
		sumA.add(i+1,H[A[i]]);
		mulA.add(i+1,H[A[i]]);
	}
	FOR(i,N) {
		cin>>B[i];
		sumB.add(i+1,H[B[i]]);
		mulB.add(i+1,H[B[i]]);
	}
	
	while(Q--) {
		int LA,LB,RA,RB;
		cin>>LA>>RA>>LB>>RB;
		LA--,LB--;
		if(RA-LA!=RB-LB) {
			cout<<"No"<<endl;
			continue;
		}
		ll sa=sumA(RA)-sumA(LA);
		ll sb=sumB(RB)-sumB(LB);
		ll ma=mulA(RA)*modpow(mulA(LA))%mo;
		ll mb=mulB(RB)*modpow(mulB(LB))%mo;
		
		if(sa==sb&&ma==mb) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
