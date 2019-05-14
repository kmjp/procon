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

int N,M;
int A[400],B[400];
vector<int> E[20];
vector<int> path[20][20];
int rev[20][20];
int ne[1<<20];
ll C[1<<20],S[1<<20];
ll mo=1000000007;


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
	
	MINUS(rev);
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		if(i<N-1) {
			E[A[i]].push_back(B[i]);
			E[B[i]].push_back(A[i]);
		}
		rev[A[i]][B[i]]=rev[B[i]][A[i]]=i;
	}
	
	FOR(i,N) {
		path[i][i].push_back(i);
		queue<int> Q;
		Q.push(i);
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			FORR(e,E[x]) if(path[i][e].empty()) {
				path[i][e]=path[i][x];
				path[i][e].push_back(e);
				Q.push(e);
			}
		}
	}
	FOR(i,M) {
		int mask=0;
		FOR(j,path[A[i]][B[i]].size()-1) mask |= 1<<(rev[path[A[i]][B[i]][j]][path[A[i]][B[i]][j+1]]);
		ne[mask]++;
	}
	FOR(i,N-1) FOR(j,1<<(N-1)) if(j&(1<<i)) ne[j]+=ne[j^(1<<i)];
	C[(1<<(N-1))-1]=1;
	
	int mask;
	for(int mask=(1<<(N-1))-1;mask>0;mask--) {
		int num=(N-1)-__builtin_popcount(mask);
		FOR(j,N-1) if((mask&(1<<j))) {
			int CN=M-ne[mask];
			int W=ne[mask]-ne[mask^(1<<j)]-1;
			ll wc=C[mask]*fact[CN+W]%mo*factr[CN]%mo;
			ll ws=S[mask]*fact[CN+W+1]%mo*factr[CN+1]%mo;
			(C[mask^(1<<j)]+=wc)%=mo;
			(S[mask^(1<<j)]+=ws+(num+1)*wc)%=mo;
		}
	}
	
	cout<<S[0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
