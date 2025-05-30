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

int T,N,Q;
ll A[202020],B[202020],CA[202020],CB[202020];
const ll mo=998244353;

template<class V, int ME> class BITm {
public:
	V bit[1<<ME];
	BITm(){ for(int i=0;i<1<<ME;i++) bit[i]=1;}
	V operator()(int e) {if(e<0) return 0;V s=1;e++;while(e) (s*=bit[e-1])%=mo,e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) (bit[e-1]*=v)%=mo,e+=e&-e;}
};
BITm<ll,20> bit;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>Q;
		FOR(i,N) {
			bit.add(i,modpow(bit(i)));
			cin>>A[i];
			CA[i]=A[i];
		}
		FOR(i,N) {
			cin>>B[i];
			CB[i]=B[i];
		}
		sort(CA,CA+N);
		sort(CB,CB+N);
		FOR(i,N) {
			bit.add(i,min(CA[i],CB[i]));
		}
		
		cout<<bit(N-1);
		while(Q--) {
			cin>>x>>y;
			y--;
			if(x==1) {
				i=lower_bound(CA,CA+N,A[y]+1)-CA;
				i--;
				bit.add(i,modpow(min(CA[i],CB[i])));
				CA[i]++;
				A[y]++;
				bit.add(i,min(CA[i],CB[i]));
			}
			else {
				i=lower_bound(CB,CB+N,B[y]+1)-CB;
				i--;
				bit.add(i,modpow(min(CA[i],CB[i])));
				CB[i]++;
				B[y]++;
				bit.add(i,min(CA[i],CB[i]));
			}
			cout<<" "<<bit(N-1);
		}
		cout<<"\n";
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
