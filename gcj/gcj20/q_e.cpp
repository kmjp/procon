#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 102;
	vector<edge> E[MV];
	vector<int> path;
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		path.push_back(from);
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		path.pop_back();
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			path.clear();
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};

int N,K;
int A[51][51];

int from[2551][51];
int num[2551][51];

void out(int _loop) {
	int y,x;
	_P("Case #%d: POSSIBLE\n",_loop);
	FOR(y,N) {
		FOR(x,N) {
			_P("%d",A[y][x]);
			if(x<N-1) _P(" ");
		}
		_P("\n");
	}
}

void solve(int _loop) {
	int f,i,j,k,l,x,y,z;
	ZERO(A);
	
	cin>>N>>K;
	
	if(N==2) {
		if(K==3) {
			_P("Case #%d: IMPOSSIBLE\n",_loop);
			return;
		}
		if(K==2) A[0][0]=A[1][1]=1,A[0][1]=A[1][0]=2;
		if(K==4) A[0][0]=A[1][1]=2,A[0][1]=A[1][0]=1;
		out(_loop);
		return;
	}
	
	int ox=0,oy=0,oz=0;
	for(x=1;x<=N;x++) {
		for(y=1;y<=N;y++) {
			for(z=1;z<=N;z++) {
				if(x==y&&x!=z) continue;
				if(x==z&&x!=y) continue;
				if(N==3&&y==z&&x!=y) continue;
				if(x*(N-2)+y+z==K) ox=x,oy=y,oz=z;
			}
		}
	}
	
	if(ox==0) return _P("Case #%d: IMPOSSIBLE\n",_loop);
	if(ox==oy&&oz==oy) {
		FOR(y,N) {
			FOR(x,N) {
				A[y][(y+x)%N]=ox+x;
				if(A[y][(y+x)%N]>N) A[y][(y+x)%N]-=N;
			}
		}
		out(_loop);
		return;
	}
	
	int ng[52][52]={};
	FOR(i,N-2) A[i][i]=ox;
	A[N-1][N-2]=A[N-2][N-1]=ox;
	if(oy==oz) {
		FOR(i,N-2) A[(i+1)%(N-2)][i]=oy;
		A[N-1][N-1]=A[N-2][N-2]=oy;
	}
	else {
		FOR(i,N-2) A[(N-1+i)%N][i]=oy;
		A[N-2][N-2]=A[N-3][N-1]=oy;
		FOR(i,N-2) A[i+1][i]=oz;
		A[N-1][N-1]=A[0][N-2]=oz;
	}
	ox--,oy--,oz--;
	
	
	while(1) {
		for(i=1;i<=N;i++) {
			FOR(x,N) if(A[0][x]==i) break;
			if(x==N) break;
		}
		if(i==N+1) break;
		MaxFlow_Ford<int> mf;
		FOR(y,N) {
			mf.add_edge(2*N,y,1);
			mf.add_edge(N+y,2*N+1,1);
			FOR(x,N) if(A[y][x]==0) mf.add_edge(y,x+N,1);
		}
		x=mf.maxflow(2*N,2*N+1);
		FOR(y,N) {
			FORR(e,mf.E[y]) {
				if(e.to>=N&&e.to<2*N&&e.cap==0) A[y][e.to-N]=i;
			}
		}
	}

	out(_loop);	
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


