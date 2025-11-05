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
ll X;
int A[101];
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

const ll mo=998244353;
ll comb(ll N_, ll C_) {
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

ll from[101][6555];
ll to[101][6555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	cin>>N>>X;
	ll S=0,S2=0;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
	}
	sort(A,A+N);
	FOR(i,N) S2+=max(A[i]-i,0);
	if(S2>X) {
		cout<<0<<endl;
		return;
	}
	if(X>=S) {
		cout<<fact[N]<<endl;
		return;
	}
	int need=S-X;
	
	from[0][0]=1;
	int pre=N-1;
	FOR(i,N) {
		int v=min(N-1,A[N-1-i]);
		while(pre>v) {
			for(x=1;x<=i+1;x++) for(y=0;y<=1LL*N*(N+1)/2;y++) if(from[x][y]) (from[x-1][y+pre]+=from[x][y]*x)%=mo;
			pre--;
		}
		ZERO(to);
		// x–¢Žg—p
		// yŒ¸‚ç‚·—Ê
		for(x=0;x<=i;x++) for(y=0;y<=1LL*N*(N+1)/2;y++) if(from[x][y]) {
			//‚æ‚è¬‚³‚¢‚Æ‚±‚ë
			to[x+1][y]+=from[x][y];
			
			int unused=N-1-v-(i-x);
			if(unused>0) (to[x][y+v]+=from[x][y]*unused)%=mo;
		}
		swap(from,to);
	}
	while(pre>=0) {
		for(x=1;x<=N;x++) for(y=0;y<=1LL*N*(N+1)/2;y++) if(from[x][y]) (from[x-1][y+pre]+=from[x][y]*x)%=mo;
		pre--;
	}
	
	ll ret=0;
	for(i=S-X;i<=N*(N+1)/2;i++) ret+=from[0][i];
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
