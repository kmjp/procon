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

int N,M;
ll mo=998244353;

template<class V> V floor_sum(V N,V M,V A,V B) {
	// sum(i=0...N-1) floor((A*i+B)/M)
	if(A<0) return floor_sum(N,M,-A,B+(N-1)*A); //A‚ª•‰‚Ìê‡ŒX‚«‚ð‹t‚É‚·‚é
	
	V ret=0;
	if(B>=M) ret+=N*(B/M), B%=M;
	if(A>=M) ret+=N*(N-1)/2*(A/M), A%=M;
	
	V Y=(A*N+B)/M;
	if(Y==0) return ret;
	//floor(Y/M)‚É’B‚·‚éX
	V X=Y*M-B;
	//X‚Ì‰E‘¤‚ÍYŒÂ‚¸‚Â
	ret+=(N-(X+A-1)/A)*Y;
	// 90“x‰ñ“]AY=N‚Ìƒ‰ƒCƒ“‚Í–³Ž‹‚·‚é
	ret+=floor_sum(Y,A,M,(A-X%A)%A);
	return ret;
}

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
BIT_mod<ll,20> bt;

ll table[50505][105];
ll num[50505];
ll sum[101];
ll rev[50505];

ll hoge(int i,int j) {
	return floor_sum<ll>(M/i,j,i,i-1)*rev[i]%mo*rev[j]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=M;i++) rev[i]=modpow(M/i);
	
	
	for(i=1;i<=M;i++) {
		for(j=1;j<=100;j++) {
			table[i][j]=hoge(i,j);
		}
	}
	ll ret=0;
	ll S=1;
	FOR(i,N) {
		cin>>x;
		S=S*(M/x)%mo;
		if(x<=100) {
			(ret+=sum[x])%=mo;
		}
		else {
			
			for(j=1;j<=100;j++) (ret+=1LL*num[j]*hoge(j,x))%=mo;
			ll a=modpow(M/x);
			for(j=x;j<=M;j+=x) {
				(ret+=a*(bt(M)-bt(j)+mo))%=mo;
				bt.add(j,a);
			}
		}
		num[x]++;
		for(j=1;j<=100;j++) (sum[j]+=table[x][j])%=mo;
		ret%=mo;
	}
	ret=ret*S%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
