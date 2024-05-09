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
vector<pair<int,int>> E;

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
	
	cin>>N>>K;
	if(N%2==0) {
		cout<<-1<<endl;
		return;
	}
	
	if(K*2>N) K=N-K;
	
	int cur=0;
	while(cur+2*K<N) {
		for(i=1;i<=K;i++) {
			E.push_back({cur,cur+i});
		}
		cur+=2*K;
	}
	
	set<int> S;
	for(i=cur+1;i<N;i++) S.insert(i);
	if(cur+K<N) {
		for(i=1;i<=K;i++) {
			if(cur+K+i<N) {
				E.push_back({cur,cur+i});
				S.erase(cur+i+K);
				S.erase(cur+i);
			}
		}
	}
	while(S.size()) {
		assert(S.size()%2==0);
		x=*S.begin();
		S.erase(x);
		y=*S.begin();
		S.erase(y);
		assert(x+1==y);
		E.push_back({x,y-K});
	}
	
	assert(E.size()*2==N-1);
	if(K*2>N) K=N-K;
	
	FORR2(a,b,E) {
		uf(a,b);
		uf((a+K)%N,(b+K)%N);
	}
	//assert(uf.count(0)==N);
	
	cout<<E.size()<<endl;
	FORR2(a,b,E) cout<<a<<" "<<b<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
