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

int T;
int N,K;
int A[2020202];
int C[2020202];
vector<int> cand[1<<20];

const int prime_max = 1000010;
vector<int> prime;
int NP,divp[prime_max];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt,G[um];
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
UF<2020202> uf;


void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

map<int,int> enumpr(int n) {
	map<int,int> V;
	
	while(divp[n]>1) {
		V[divp[n]]++;
		n/=divp[n];
	}
	if(n>1) V[n]++;
	return V;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>T;
	while(T--) {
		vector<int> candp;
		cin>>N>>K;
		FOR(i,N) {
			cin>>x;
			if(i==0) {
				A[N-1]=x;
				C[N-1]=N;
			}
			else {
				A[N-1+i]=A[i-1]=x;
				C[N-1+i]=N-i;
				C[i-1]=i;
			}
		}
		uf.reinit(2*N-1);
		FOR(i,2*N-1) {
			auto p=enumpr(A[i]);
			if(p.size()) {
				FORR2(a,b,p) {
					cand[a].push_back(i);
					candp.push_back(a);
				}
				C[i]=1;
			}
		}
		sort(ALL(candp));
		FORR(p,candp) if(cand[p].size()) {
			FOR(i,cand[p].size()-1) if(cand[p][i+1]-cand[p][i]<=K) uf(cand[p][i],cand[p][i+1]);
			cand[p].clear();
		}
		ll ret=0;
		FOR(i,2*N-1) if(uf[i]==i) ret+=C[i];
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
