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

int N;
int A[20][20];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 202020;
	int NV=MV;
	vector<edge> E[MV];
	int itr[MV],lev[MV],mincut[MV]; //1ならsource側
	void init(int NV_) { int i; FOR(i,NV_) E[i].clear(); NV=NV_;}
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		int i;
		FOR(i,NV) lev[i]=-1;
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
			if(lev[to]<0) break;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
		//最小カット復元
		int i;
		FOR(i,NV) mincut[i]=0;
		queue<int> Q;
		mincut[from]=1;
		Q.push(from);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(e.cap>0&&mincut[e.to]==0) mincut[e.to]=1, Q.push(e.to);
		}
		return fl;
	}
};
MaxFlow_dinic<int> mf;

int id(int y,int x,int v) {
	assert(v>=1&&v<=4);
	return (y*20+x)*4+v-1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) {
		cin>>A[y][x];
		
		if(A[y][x]) {
			if(A[y][x]!=5) mf.add_edge(id(y,x,A[y][x]),20*20*4+1,1<<30);
			if(A[y][x]!=1) mf.add_edge(20*20*4,id(y,x,A[y][x]-1),1<<30);
		}
		FOR(i,3) {
			mf.add_edge(id(y,x,i+2),id(y,x,i+1),1<<30);
		}
	}
	FOR(y,N) FOR(x,N-1) {
		for(i=1;i<=4;i++) {
			mf.add_edge(id(y,x,i),id(y,x+1,i),1);
			mf.add_edge(id(y,x+1,i),id(y,x,i),1);
			mf.add_edge(id(x,y,i),id(x+1,y,i),1);
			mf.add_edge(id(x+1,y,i),id(x,y,i),1);
			for(j=1;j<i;j++) {
				mf.add_edge(id(y,x,i),id(y,x+1,j),2);
				mf.add_edge(id(y,x+1,i),id(y,x,j),2);
				mf.add_edge(id(x,y,i),id(x+1,y,j),2);
				mf.add_edge(id(x+1,y,i),id(x,y,j),2);
			}
		}
	}
	
	mf.maxflow(20*20*4,20*20*4+1);
	
	FOR(y,N) {
		FOR(x,N) {
			int ret=1;
			FOR(i,4) if(mf.mincut[id(y,x,i+1)]) ret++;
			cout<<ret<<" ";
		}
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
