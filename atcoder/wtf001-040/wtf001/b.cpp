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

int N,Q;
int L[20],R[20];
ll dp[10][1<<16];
const ll mo=1000000007;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<40> uf;

vector<pair<int,int>> C[40];
int ID[40];
ll mul[1<<20];
ll param(int len) {
	ll a=(modpow(10,len)+8);
	ll b=(modpow(10,len)-1);
	return a*modpow(b)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	vector<int> V;
	FOR(i,Q) {
		cin>>L[i]>>R[i];
		L[i]--;
		V.push_back(L[i]);
		V.push_back(R[i]);
	}
	V.push_back(0);
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,Q) {
		L[i]=lower_bound(ALL(V),L[i])-V.begin();
		R[i]=lower_bound(ALL(V),R[i])-V.begin();
		uf(L[i],R[i]);
	}
	
	Q=0;
	FOR(i,V.size()) {
		C[uf[i]].push_back({V[i],i});
		if(uf[i]==i) Q++;
	}
	sort(C,C+40);
	reverse(C,C+40);
	int lef=0;
	FOR(i,Q) {
		FORR(c,C[i]) {
			ID[c.second]=i;
			if(c.second==0) lef=1<<i;
		}
	}
	
	int mask;
	FOR(mask,1<<Q) {
		mul[mask]=1;
		FOR(j,V.size()-1) if((mask&(1<<ID[j]))&&(mask&(1<<ID[j+1]))) (mul[mask]*=param(V[j+1]-V[j]))%=mo;
	}
	
	
	dp[0][0]=1;
	FOR(i,9) {
		
		FOR(mask,1<<Q) {
			int cand=mask^((1<<Q)-1);
			for(int sm=cand; sm>=0; sm--) {
				sm&=cand;
				
				if(i==0 && ((sm&lef)==0)) continue;
				if(i && (sm&lef)) continue;
				
				(dp[i+1][mask^sm]+=dp[i][mask]*mul[sm])%=mo;
			}
		}
	}
	
	ll base=modpow(10,N-V.back());
	FOR(i,V.size()-1) base=base*(modpow(10,V[i+1]-V[i])-1)%mo*modpow(9)%mo;
	
	cout<<base*dp[9][(1<<Q)-1]%mo<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
