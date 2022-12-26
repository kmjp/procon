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


template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1000000;
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

MaxFlow_dinic<int> mf;
int N;
int vis[600020];
map<int,int> D;
vector<pair<int,int>> add[300030];
vector<pair<int,int>> del[300030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,300010) mf.add_edge(0,10+i,1);
	FOR(i,300010) mf.add_edge(500000+i,1,1);
	
	cin>>N;
	FOR(i,N) {
		int x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		add[x1].push_back({y1,y2});
		del[x2].push_back({y1,y2});
	}
	for(i=0;i<=300010;i++) {
		FORR(a,add[i]) {
			if(++D[a.first]==0) D.erase(a.first);
			if(--D[a.second+1]==0) D.erase(a.second+1);
		}
		
		int cur=0;
		y=-1;
		FORR(d,D) {
			if(cur) for(x=y;x<d.first;x++) mf.add_edge(10+i,500000+x,1);
			y=d.first;
			cur+=d.second;
		}
		
		
		FORR(e,del[i]) {
			if(--D[e.first]==0) D.erase(e.first);
			if(++D[e.second+1]==0) D.erase(e.second+1);
		}
	}
	
	mf.maxflow(0,1);
	
	queue<int> Q;
	FOR(i,300010) {
		int match=0;
		FORR(e,mf.E[10+i]) if(e.to==0 && e.cap==0) match=1;
		if(match) {
			vis[10+i]=1;
			Q.push(10+i);
		}
	}
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,mf.E[x]) if(e.cap && vis[e.to]==0) {
			vis[e.to]=1;
			Q.push(e.to);
		}
	}
	
	vector<int> Xs,Ys;
	FOR(i,300010) if(vis[i+10]==0 && mf.E[i+10].size()>1) Xs.push_back(i);
	FOR(i,300010) if(vis[500000+i] && mf.E[i+500000].size()>1) Ys.push_back(i);
	
	cout<<Xs.size()+Ys.size()<<endl;
	cout<<Xs.size()<<endl;
	FORR(x,Xs) cout<<x<<" ";
	cout<<endl<<Ys.size()<<endl;
	FORR(y,Ys) cout<<y<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
