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


int N,M,K;
int A[202020],B[202020],C[202020];
vector<pair<int,int>> E[202020];
ll D[202020];

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
UF<202020> uf;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>A[i]>>B[i]>>C[i];
		A[i]--,B[i]--;
		E[A[i]].push_back({B[i],C[i]});
		E[B[i]].push_back({A[i],C[i]});
	}
	FOR(i,N) D[i]=1LL<<60;
	priority_queue<pair<ll,int>> Q;
	FOR(i,K) D[i]=0, Q.push({0,i});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=D[cur]) continue;
		FORR2(e,c,E[cur]) if(D[e]>co+c) {
			D[e]=co+c;
			Q.push({-D[e],e});
		}
	}
	vector<pair<ll,int>> Es;
	FOR(i,M) Es.push_back({C[i]+D[A[i]]+D[B[i]],i});
	sort(ALL(Es));
	reverse(ALL(Es));
	
	int L;
	cin>>L;
	while(L--) {
		ll X,Y,T;
		cin>>X>>Y>>T;
		X--,Y--;
		while(Es.size()&&Es.back().first<=T) {
			uf(A[Es.back().second],B[Es.back().second]);
			Es.pop_back();
		}
		if(uf[X]==uf[Y]) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
