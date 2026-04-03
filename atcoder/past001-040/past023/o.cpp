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

int H,W,D;
int A[15][15];

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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>D;
	ll pen=0;
	FOR(y,H) {
		FOR(x,W) {
			cin>>A[y][x];
			
			if((y+x)%2==0) {
				// v以上であるなら赤
				
				//青だと1ペナルティ
				pen+=9;
				for(i=1;i<=9;i++) mf.add_edge(10000,(y*W+x)*10+i,1);
				//vが赤ならv-1も赤
				for(i=1;i<=9;i++) mf.add_edge((y*W+x)*10+i,(y*W+x)*10+i-1,10000);
				
				if(A[y][x]!=-1) {
					//A[y][x]以下は赤確定→青でペナルティ
					FOR(i,A[y][x]+1) mf.add_edge(10000,(y*W+x)*10+i,10000);
					// A[y][x]より大きいところは青確定→赤でペナルティ
					for(i=A[y][x]+1;i<=9;i++) mf.add_edge((y*W+x)*10+i,10001,10000);
				}
				FOR(i,10) FOR(j,10) if(i+j+1>D) {
					int d[]={1,0,-1,0};
					FOR(k,4) {
						int ty=y+d[k];
						int tx=x+d[k^1];
						if(ty<0||ty>=H||tx<0||tx>=W) continue;
						mf.add_edge((y*W+x)*10+i,(ty*W+tx)*10+j,10000);
						if(i>D) mf.add_edge((y*W+x)*10+i,10001,10000);
						if(j+1>D) mf.add_edge(10000,(ty*W+tx)*10+j,10000);
					}
				}
			}
			else {
				// v以下なら赤
				
				//青だと報酬→赤だとペナルティ1
				pen+=9;
				for(i=0;i<=8;i++) mf.add_edge((y*W+x)*10+i,10001,1);
				
				//vが赤ならv+1も赤
				for(i=1;i<=9;i++) mf.add_edge((y*W+x)*10+i-1,(y*W+x)*10+i,10000);
				if(A[y][x]!=-1) {
					//A[y][x]未満は青確定
					FOR(i,A[y][x]) mf.add_edge((y*W+x)*10+i,10001,10000);
					// A[y][x]より大きいところは赤確定
					for(i=A[y][x];i<=9;i++) mf.add_edge(10000,(y*W+x)*10+i,10000);
				}
			}
			
		}
	}
	ll ret=pen-mf.maxflow(10000,10001);
	FOR(y,H) FOR(x,W) if(A[y][x]!=-1) ret-=A[y][x];
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
