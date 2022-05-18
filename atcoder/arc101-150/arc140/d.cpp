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


int N,A[2020];
const ll mo=998244353;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<2020> uf;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

ll dp[2020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int unf=0;
	FOR(i,N) {
		cin>>A[i];
		if(A[i]>0) {
			A[i]--;
			uf(i,A[i]);
		}
		else {
			unf++;
		}
	}
	ll ret=0;

	dp[0]=1;
	FOR(i,N) if(uf[i]==i) {
		int fix=1;
		FOR(j,N) if(uf[j]==i) {
			if(A[j]==-1) fix=0;
		}
		
		if(fix) {
			ret+=modpow(N,unf);
		}
		else {
			for(x=unf;x>=0;x--) if(dp[x]) {
				(dp[x+1]+=dp[x]*uf.count(i))%=mo;
			}
		}
	}
	
	ll f=1;
	for(i=1;i<=unf;i++) if(dp[i]) {
		if(i>1) f=f*(i-1)%mo;
		ret+=f*dp[i]%mo*modpow(N,unf-i)%mo;
	}
	
	
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
