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


int N;
ll CX[1010],CY[1010];
ll DX[1010],DY[1010];
ll D[1010][1010];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 2100;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

int op[1010],rev[1010];
int sm[1010];
int didA[1010],didB[1010];
vector<pair<ll,int>> cand[1010];

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	MaxFlow_dinic<int> mf;
	
	cin>>N;
	FOR(i,N) cin>>CX[i]>>CY[i];
	FOR(i,N+1) cin>>DX[i]>>DY[i];
	FOR(x,N) {
		mf.add_edge(2010,x,1);
		mf.add_edge(1001+x,2011,1);
		cand[x].clear();
		FOR(y,N+1) {
			D[x][y]=(CX[x]-DX[y])*(CX[x]-DX[y])+(CY[x]-DY[y])*(CY[x]-DY[y]);
			if(y) cand[x].push_back({-D[x][y],y});
		}
		sort(ALL(cand[x]));
		FOR(y,N+1) if(D[x][y]<=D[x][0]) mf.add_edge(x,1000+y,1);
	}
	
	x=mf.maxflow(2010,2011);
	if(x<N) {
		cout<<"Case #"<<_loop<<": IMPOSSIBLE"<<endl;
		return;
	}
	
	ZERO(sm);
	FOR(x,N) FORR(e,mf.E[x]) if(e.to<2001&&e.cap==0) {
		op[x]=e.to-1000;
		rev[op[x]]=x;
	}
	
	ZERO(didA);
	ZERO(didB);
	vector<pair<int,int>> V;
	while(1) {
		queue<int> Q;
		ZERO(sm);
		FOR(x,N) if(didA[x]==0) {
			FOR(y,N+1) if(didB[y]==0&&D[x][y]<D[x][op[x]]) sm[x]++;
			if(sm[x]==0) Q.push(x);
		}
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			V.push_back({x+1,op[x]+1});
			didA[x]=didB[op[x]]=1;
			FOR(y,N) if(D[y][op[y]]>D[y][op[x]]) {
				sm[y]--;
				if(sm[y]==0) Q.push(y);
			}
		}
		FOR(i,N) if(didA[i]==0) break;
		if(i==N) break;
		
		vector<int> S;
		int cur=i;
		FOR(j,N+5) {
			S.push_back(cur);
			while(1) {
				x=cand[cur].back().second;
				if(didB[x]==0) break;
				cand[cur].pop_back();
			}
			cur=rev[x];
		}
		for(i=S.size()-2;i>=0;i--) if(S[i]==S.back()) break;
		for(j=i+1;j<S.size();j++) {
			x=S[j];
			y=cand[S[j]].back().second;
			op[x]=y;
			rev[y]=x;
		}
	}
	cout<<"Case #"<<_loop<<": POSSIBLE"<<endl;
	FORR2(a,b,V) cout<<a<<" "<<b<<endl;
	
	
	//_P("Case #%d:\n",_loop);
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


