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

int N,K;
const ll mo=998244353;
ll F[202];

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

ll from[205][405];
ll to[205][405];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	from[0][0]=1;
	FOR(i,N) {
		ZERO(to);
		
		for(x=0;2*x<=i*2;x++) {
			for(y=0;2*x+y<=i*2;y++) {
				// add 2 box
				(to[x+1][y]+=from[x][y])%=mo;
				// add 1 box
				(to[x][y+1]+=from[x][y])%=mo;
				// new and add
				if(x) (to[x-1][y+3]+=x*from[x][y])%=mo;
				if(y) (to[x][y+1]+=y*from[x][y])%=mo;
				// select dup x 2 
				if(x>=2) (to[x-2][y+4]+=comb(x,2)*from[x][y])%=mo;
				if(x>=1) {
					// split
					(to[x-1][y+2]+=x*from[x][y])%=mo;
					// same
					(to[x][y]+=x*from[x][y])%=mo;
				}
				// select one single
				(to[x][y]+=y*from[x][y])%=mo;
				// select two single
				(to[x][y]+=comb(y,2)*from[x][y])%=mo;
				
				// select dup and single
				if(x&&y) (to[x-1][y+2]+=x*y*from[x][y])%=mo;

			}
		}
		swap(from,to);
		//FOR(x,N+1) FOR(y,2*N+1) if(from[x][y]) cout<<i<<" "<<x<<" "<<y<<" "<<from[x][y]<<endl;
	}
	ll ret=0;
	FOR(x,N+1) FOR(y,2*N+1) if(2*x+y==K) ret+=from[x][y];
	cout<<ret%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
