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

map<pair<int,int>,int> F;
int nex;

int N,M;
vector<int> E[505];
int NE[505050];

void dfs(int from,int to) {
	if(F.count({from,to})) return;
	F[{from,to}]=nex;
	NE[nex]++;
	int n=lower_bound(ALL(E[to]),from+N)-E[to].begin()-1;
	dfs(to,E[to][n]%N);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		E[i].push_back((i+1)%N);
		E[(i+1)%N].push_back(i);
	}
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) {
		x=E[i].size()*2;
		FOR(j,x) E[i].push_back(E[i][j]+N);
		sort(ALL(E[i]));
	}
	
	FOR(i,N) FORR(e,E[i]) if(e<N&&F.count({i,e})==0) {
		dfs(i,e);
		nex++;
	}
	
	FOR(i,N) FORR(e,E[i]) if(e<N) {
		x=F[{i,e}];
		y=F[{e,i}];
		uf(2*x,2*y+1);
		uf(2*y,2*x+1);
	}
	if(uf[0]==uf[1]) {
		cout<<5<<endl;
	}
	else {
		int ma=0,c=0;
		FOR(i,nex) if(NE[i]>ma) {
			ma=NE[i];
			c=uf[i*2];
		}
		FOR(i,nex) if(NE[i]%2==1) {
			if(uf[i*2]!=c) {
				cout<<5<<endl;
				return;
			}
		}
		
		cout<<4<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
