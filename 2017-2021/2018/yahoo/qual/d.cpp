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

int N,K,X,Y;
int A[1100][1100];
ll mo=1000000007;
int num[2049];

map<int,int> memo[2020][2020];

ll combi(ll N_, ll C_) {
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


ll hoge(int a,int b,int c) {
	if(a>b+c) return 0;
	if(b==0 || c==0 || a==0) return 1;
	if(memo[b][c].count(a)) return memo[b][c][a];
	ll ret=0;
	int i;
	FOR(i,a+1) if(i<=b && a-i<=c) ret+=combi(a,i);
	
	return memo[b][c][a]=ret%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X>>Y;
	FOR(i,N) cin>>x, num[x]++;
	
	FOR(y,K) FOR(x,K) {
		cin>>A[y][x];
		A[y][x]=min(A[y][x]^X,A[y][x]^Y);
	}
	X^=Y;
	
	FOR(y,K) {
		if(A[y][x]) return _P("0\n");
		FOR(x,K) {
			if(A[y][x]!=A[x][y]) return _P("0\n");
			if(((A[0][x]^A[0][y])!=A[x][y]) && ((A[0][x]^A[0][y]^X)!=A[x][y])) return _P("0\n");
		}
	}
	
	ll tot=0;
	FOR(i,2048) if(i<(i^X)) {
		int tmp[2048]={};
		tmp[i]++;
		for(j=1;j<K;j++) tmp[min(A[0][j]^i,A[0][j]^i^X)]++;
		ll ret=1;
		FOR(j,2048) if(j<(j^X)) (ret*=hoge(tmp[j],num[j],num[j^X]))%=mo;
		tot+=ret;
	}
	cout<<tot%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
