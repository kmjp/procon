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
	static const int MV = 10101;
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
string S[101];
MaxFlow_dinic<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if((y+x)%2==0) {
			mf.add_edge(10000,y*100+x,1);
			if(y) mf.add_edge(y*100+x,(y-1)*100+x,1);
			if(y+1<H) mf.add_edge(y*100+x,(y+1)*100+x,1);
			if(x) mf.add_edge(y*100+x,y*100+x-1,1);
			if(x+1<W) mf.add_edge(y*100+x,y*100+x+1,1);
		}
		else {
			mf.add_edge(y*100+x,10001,1);
		}
	}
	
	int num=mf.maxflow(10000,10001);
	
	FOR(y,H) FOR(x,W) if(S[y][x]=='.' && (y+x)%2==0) {
		FORR(e,mf.E[y*100+x]) if(e.cap==0 && e.to<10000) {
			if(e.to-1==y*100+x) S[y][x]='>',S[y][x+1]='<';
			if(e.to+1==y*100+x) S[y][x]='<',S[y][x-1]='>';
			if(e.to-100==y*100+x) S[y][x]='v',S[y+1][x]='^';
			if(e.to+100==y*100+x) S[y][x]='^',S[y-1][x]='v';
		}
	}
	cout<<num<<endl;
	FOR(y,H) cout<<S[y]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
