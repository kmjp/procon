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

int N,M,S;
int A[151];
int E[151][151];
ll R[151][151];

ll mat[150][150];
const ll mo=998244353;

ll modpow(ll a, ll n=mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll det_mo(int N) {
	int x,y,z;
	ll ret=1;
	FOR(y,N) FOR(z,N) mat[y][z]=((mat[y][z]%mo)+mo)%mo;
	FOR(x,N) {
		if(mat[x][x]==0) {
			for(y=x+1;y<N;y++) if(mat[y][x]) break;
			if(y==N) return 0;
			FOR(z,N) swap(mat[x][z],mat[y][z]);
		}
		ret=ret*mat[x][x]%mo;
		ll rev=modpow(mat[x][x]);
		FOR(z,N) mat[x][z]=rev*mat[x][z]%mo;
		for(y=x+1;y<N;y++) if(mat[y][x]) {
			rev=mat[y][x];
			for(z=x;z<N;z++) mat[y][z]=((mat[y][z]-mat[x][z]*rev)%mo+mo)%mo;
		}
	}
	return ret;
}

//f(0)`f(N)‚©‚çANŽŸŽ®‚ðì‚éBO(N^2)
vector<ll> lagrange(vector<ll>& P) {
	int N=P.size()-1;
	vector<ll> dp(N+2),ret(N+1);
	dp[0]=1;
	int i,j;
	FOR(i,P.size()) {
		// x-p”{
		ll a=0;
		FOR(j,N+2) {
			ll b=dp[j];
			dp[j]=(b*(mo-i)+a)%mo;
			a=b;
		}
	}
	FOR(i,P.size()) {
		vector<ll> dp2=dp;
		ll q=1;
		FOR(j,P.size()) if(i!=j) (q*=mo+(i-j))%=mo;
		ll p=P[i]*modpow(q)%mo;
		// x-p‚ÅŠ„‚é
		for(j=dp2.size()-1;j>=1;j--) {
			(ret[j-1]+=p*dp2[j])%=mo;
			(dp2[j-1]+=dp2[j]*i)%=mo;
			dp2[j]=0;
		}
	}
	return ret;

}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	vector<int> C;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		FOR(j,A[i]) C.push_back(i);
		E[i][i]=1;
	}
	if(S%2) {
		cout<<-1<<endl;
		return;
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x-1][y-1]=E[y-1][x-1]=1;
	}
	
	FOR(x,S) for(y=x+1;y<S;y++) {
		R[y][x]=R[x][y]=rand()%mo;
	}
		
	vector<ll> V;
	FOR(i,S+1) {
		ZERO(mat);
		FOR(y,S) FOR(x,y) {
			if(C[x]==C[y]) {
				mat[y][x]=R[x][y];
			}
			else if(E[C[x]][C[y]]) {
				mat[y][x]=R[x][y]*i%mo;
			}
			mat[x][y]=(mo-mat[y][x])%mo;
		}
		V.push_back(det_mo(S));
	}
	
	auto P=lagrange(V);
	FOR(i,P.size()) if(P[i]) {
		cout<<i/2<<endl;
		return;
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
