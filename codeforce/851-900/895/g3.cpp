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

int T,N;
ll A[202020];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

const ll mo=1000000007;
ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

template<class V, int ME> class BITm {
public:
	V bit[1<<ME];
	BITm(){ for(int i=0;i<1<<ME;i++) bit[i]=1;}
	V operator()(int e) {if(e<0) return 0;V s=1;e++;while(e) (s*=bit[e-1])%=mo,e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]*=v)%=mo,e+=e&-e;}
};
BITm<ll,20> bt2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			bt.add(i+1,-bt(i+1));
		}
		FOR(i,N) {
			bt2.add(i+1,modpow(bt2(i+1)));
		}
		FOR(i,N) {
			cin>>A[i];
			bt.add(i+1,A[i]);
			bt2.add(i+1,A[i]);
		}
		int L=0,R=N-1;
		while(L<N&&A[L]==1) L++;
		while(R>=0&&A[R]==1) R--;
		if(L>R) {
			cout<<"1 1"<<endl;
			continue;
		}
		ll a=1;
		vector<int> C;
		for(i=L;i<=R;i++) if(A[i]>1) {
			C.push_back(i);
			a*=A[i];
			a=min(a,1LL<<25);
		}
		if(a>=1<<25) {
			cout<<(L+1)<<" "<<(R+1)<<endl;
			continue;
		}
		ll ma=bt(N);
		int TL=1,TR=1;
		FORR(x,C) FORR(y,C) if(x<=y) {
			ll lef=bt(x)+bt(N)-bt(y+1)+bt2(y+1)*modpow(bt2(x))%mo;
			if(lef>ma) ma=lef,TL=x+1,TR=y+1;
		}
		cout<<TL<<" "<<TR<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
