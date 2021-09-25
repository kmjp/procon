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
UF<101010> uf;

int N;
int A[101010],B[101010];
vector<pair<int,int>> E[101010];
vector<int> lp;
int C[101010];
int ret[101010];

void dfs(int cur,int pre) {
	FORR2(e,i,E[cur]) {
		if(e==pre) {
			ret[i]=cur;
		}
		else {
			dfs(e,cur);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		
		if(uf[A[i]]==uf[B[i]]) {
			lp.push_back(i);
		}
		else {
			uf(A[i],B[i]);
			E[A[i]].push_back({B[i],i});
			E[B[i]].push_back({A[i],i});
		}
	}
	FOR(i,N) {
		C[uf[A[i]]]++;
		C[uf[B[i]]]++;
	}
	FOR(i,N) if(uf[i]==i && C[i]!=uf.count(i)*2) return _P("No\n");
	
	FORR(c,lp) {
		ret[c]=A[c];
		dfs(A[c],A[c]);
	}
	cout<<"Yes"<<endl;
	FOR(i,N) cout<<ret[i]+1<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
