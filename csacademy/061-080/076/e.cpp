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

int H,W,SX,SY;
int A[150][150];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 150*150*4;
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
			ITR(e,E[v]) if(e->cap>0 && lev[e->to]<0) lev[e->to]=lev[v]+1, q.push(e->to);
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

MaxFlow_dinic<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>SY>>SX;
	SY--,SX--;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		if(A[y][x]<0) A[y][x]=0;
		
		mf.add_edge(10+y*150+x,20+150*150+y*150+x,A[y][x]);
		
		
		if(y==0 || y==H-1 || x==0 || x==W-1) {
			mf.add_edge(20+150*150+y*150+x,1,1LL<<60);
		}
		else {
			for(int y2=max(0,y-1);y2<=min(H-1,y+1);y2++) {
				for(int x2=max(0,x-1);x2<=min(W-1,x+1);x2++) {
					if(x==x2 && y==y2) continue;
					mf.add_edge(20+150*150+y*150+x,10+y2*150+x2,1LL<<60);
				}
			}
		}
	}
	mf.add_edge(0,20+150*150+SY*150+SX,1LL<<60);
	cout<<mf.maxflow(0,1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
