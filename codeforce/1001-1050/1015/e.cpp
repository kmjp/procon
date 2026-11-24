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
int A[5050];
const ll mo=1000000007;

int F[5050][5050];
int C[5050];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		ZERO(C);
		FOR(x,N) {
			k=0;
			for(y=x;y<N;y++) {
				if(A[y]==-1) k++;
				F[x][y]=k;
				C[k]++;
			}
		}
		int L=N,R=-1;
		ll ret=0;
		int all=F[0][N-1];
		int need=0;
		FOR(i,N) {
			k=-1;
			FOR(j,N) if(A[j]==i) k=j;
			if(k==-1) {
				need++;
			}
			else {
				if(L==N) {
					FOR(x,N) for(y=x;y<N;y++) if(y<k||x>k) C[F[x][y]]--;
					L=R=k;
				}
				else {
					if(k<L) {
						for(x=k+1;x<=L;x++) for(y=R;y<N;y++) C[F[x][y]]--;
					}
					if(k>R) {
						for(y=R;y<k;y++) FOR(x,L+1) C[F[x][y]]--;
					}
					L=min(L,k);
					R=max(R,k);
				}
			}
			FOR(j,N+1) if(C[j]) (ret+=C[j]*comb(j,need)%mo*modpow(comb(all,need))%mo)%=mo;
		}
		(ret*=fact[all])%=mo;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
