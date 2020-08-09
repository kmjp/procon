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
	static const int MV = 50;
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

int H,W;
string S[16];
int M[16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	int num=0;
	FOR(y,H) {
		cin>>S[y];
		num+=count(ALL(S[y]),'#');
		FOR(x,W) if(S[y][x]=='#') M[y] |= 1<<x;
		
	}
	if(num==0) return _P("0\n");
	if(num==H*W) return _P("-1\n");
	
	int mi=3030;
	
	int mask;
	for(mask=1;mask<1<<H;mask++) {
		int lef=0;
		FOR(y,H) if((mask&(1<<y))==0) lef |= M[y];
		MaxFlow_dinic<int> mf;
		FOR(y,H) if(mask&(1<<y)) mf.add_edge(32,y,1);
		FOR(x,W) if(lef&(1<<x)) mf.add_edge(16+x,33,1);
		FOR(y,H) FOR(x,W) if((mask&(1<<y))&&(lef&(1<<x))&&S[y][x]=='.') mf.add_edge(y,16+x,1);
		int f=mf.maxflow(32,33);
		
		int NV=__builtin_popcount(mask);
		int NH=__builtin_popcount(lef);
		
		if(f==0) {
			int ok=0;
			FOR(y,H) FOR(x,W) if(((mask&(1<<y)) || (lef&(1<<x)))&&S[y][x]=='.') ok=1;
			if(ok) {
				mi=min(mi,NV+NH);
			}
			else {
				mi=min(mi,NV+NH+1);
			}
			
			mi=min(mi,__builtin_popcount(mask)+__builtin_popcount(lef)+1);
		}
		else {
			mi=min(mi,NV+NH-f);
		}
		
	}
	
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
