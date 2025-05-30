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
int A[202020];
const ll mo=998244353;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
ll hcomb(ll P_,ll Q_) { return (P_==0&&Q_==0)?1:comb(P_+Q_-1,Q_);}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i+1];
		}
		
		int ng=0;
		if(A[N]==-1) A[N]=N;
		if(A[N]!=N) ng=1;
		
		FOR(i,N+1) if(A[i]>i) ng=1;
		if(ng) {
			cout<<0<<endl;
			continue;
		}
		int pre=0;
		ll ret=1;
		for(i=1;i<=N;i++) if(A[i]!=-1) {
			if(A[pre]>A[i]) {
				ret=0;
				break;
			}
			if(A[pre]+2*(i-pre)<A[i]) {
				ret=0;
				break;
			}
			
			int fr=pre-A[pre];
			int add=A[i]-A[pre];
			ll pat=0;
			for(j=0;j<=i-pre;j++) {
				if(j>add) continue;
				int lef=add-j;
				ll a=comb(i-pre,lef)*comb(fr,lef)%mo*fact[lef]%mo;
				a*=comb(i-pre+fr-lef,j)*comb(i-pre,j)%mo*fact[j]%mo;
				(pat+=a)%=mo;
			}
			ret=ret*(pat%mo)%mo;
			
			pre=i;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
