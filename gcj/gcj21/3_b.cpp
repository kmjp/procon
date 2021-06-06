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

int T;
int H,W;
int R[20],C[20];

string ret[20];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
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


int check() {
	int y,y2,y3,x;
	FOR(y,H) FOR(x,W-1) if(ret[y][x]=='/'&&ret[y][x+1]=='\\') {
		for(y2=y+1;y2<H;y2+=2) if(ret[y2][x]=='\\'&&ret[y2][x+1]=='/') {
			int ng=1;
			for(y3=y+1;y3<y2;y3++) {
				if(y3-y<y2-y3) {
					if(x-(y3-y)<0||ret[y3][x-(y3-y)]=='\\') ng=0;
					if(x+1+(y3-y)>=W||ret[y3][x+1+(y3-y)]=='/') ng=0;
				}
				else {
					if(x-(y2-y3)<0||ret[y3][x-(y2-y3)]=='/') ng=0;
					if(x+1+(y2-y3)>=W||ret[y3][x+1+(y2-y3)]=='\\') ng=0;
				}
			}
			if(ng) {
				swap(ret[y][x],ret[y][x+1]);
				swap(ret[y2][x],ret[y2][x+1]);
				return 0;
			}
		}
	}
	return 1;
}

void solve(int _loop) {
	int f,i,j,k,l,x,y;
	MaxFlow_dinic<int> mf;
	
	cin>>H>>W;
	int sum=0,sumc=0;
	FOR(y,H) {
		cin>>R[y];
		mf.add_edge(100,y,R[y]);
		sum+=R[y];
	}
	FOR(x,W) {
		cin>>C[x];
		sumc+=C[x];
		mf.add_edge(20+x,101,C[x]);
		
	}
	FOR(y,H) FOR(x,W) mf.add_edge(y,20+x,1);
	i=mf.maxflow(100,101);
	
	if(sum!=i||sum!=sumc) {
		_P("Case #%d: IMPOSSIBLE\n",_loop);
		return;
	}
	FOR(y,H) {
		ret[y]=string(W,'\\');
		FORR(e,mf.E[y]) if(e.to>=20&&e.to<40&&e.cap==0) ret[y][e.to-20]='/';
	}
	while(check()==0);
	_P("Case #%d: POSSIBLE\n",_loop);
	FOR(y,H) _P("%s\n",ret[y].c_str());
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


