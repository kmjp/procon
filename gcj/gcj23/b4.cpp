#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
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

int T,N,L;

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

class SCC_ART {
public:
	static const int MV = 1100000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> low,num,isart,gr;
	vector<pair<int,int>> ES;
	vector<vector<int> > SC; // out
	vector<int> ART; // out
	vector<set<pair<int,int>> > BE; // out, Edgeset
	UF<MV> uf;
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { E[x].push_back(y); E[y].push_back(x);}
	void dfs(int cur,int pre) {
		low[cur]=num[cur]=++time;
		FORR(e,E[cur]) {
			if(e!=pre && num[e]<num[cur]) ES.push_back({min(e,cur),max(e,cur)});
			if(num[e]) low[cur]=min(low[cur],num[e]);
			else {
				dfs(e,cur);
				low[cur]=min(low[cur],low[e]);
				if((num[cur]==1&&num[e]>2) || (num[cur]!=1&&low[e]>=num[cur])) isart[cur]=1;
				if(low[e]>=num[cur]) {
					BE.push_back(set<pair<int,int>>());
					while(1) {
						pair<int,int> te=ES.back();
						ES.pop_back();
						BE.back().insert(te);
						if(min(cur,e)==te.first && max(cur,e)==te.second) break;
					}
					
				}
			}
		}
		if(isart[cur]) ART.push_back(cur);
	}
	void scc() {
		ART.clear();uf.reinit(NV);SC.clear();BE.clear();ES.clear();
		low=num=isart=gr=vector<int>(NV,0);
		for(int i=0;i<NV;i++) if(!num[i]) time=0,dfs(i,-1);
		sort(ART.begin(),ART.end());
		for(int i=0;i<NV;i++) FORR(r,E[i]) if(isart[i]==0 && isart[r]==0) uf(i,r);
		for(int i=0;i<NV;i++) if(uf[i]==i) gr[i]=SC.size(), SC.push_back(vector<int>());
		for(int i=0;i<NV;i++) gr[i]=gr[uf[i]], SC[gr[uf[i]]].push_back(i);
	}
};
SCC_ART scc;

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	
	cin>>N>>L;
	scc.init(N+L);
	FOR(i,L) {
		cin>>x;
		while(x--) {
			cin>>y;
			scc.add_edge(y-1,N+i);
		}
	}
	scc.scc();
	int ret=0;
	FORR(a,scc.ART) if(a>=N) ret++;
	cout<<"Case #"<<_loop<<": "<<ret<<endl;
	
	
}

void init() {
}

int main(int argc,char** argv){
	int loop,loops;
	long long span;
	char tmpline[1000];
	struct timeval start,end,ts;
	
	if(argc>1) freopen(argv[1], "r", stdin);
	gettimeofday(&ts,NULL);
	cin>>loops;
	init();
	
	for(loop=1;loop<=loops;loop++) {
		gettimeofday(&start,NULL); solve(loop); gettimeofday(&end,NULL);
		span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
		fprintf(stderr,"Case : %d                                     time: %lld ms\n",loop,span/1000);
	}
	
	start = ts;
	span = (end.tv_sec - start.tv_sec)*1000000LL + (end.tv_usec - start.tv_usec);
	fprintf(stderr,"**Total time: %lld ms\n",span/1000);
	
	return 0;
}


