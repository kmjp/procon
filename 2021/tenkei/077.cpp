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

// O(V^2 E)Ç»ÇÃÇ≈ÉtÉçÅ[Ç™è¨Ç≥Ç¢Ç∆Ç´ÇÕFord-FulkersonÇ…Ç∑Ç◊Ç´
template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 41100;
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

MaxFlow_dinic<int> mf;

int N,T;
int AX[202020],AY[202020];
int BX[202020],BY[202020];
map<pair<int,int>,int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>AX[i]>>AY[i];
		mf.add_edge(40000,i,1);
	}
	FOR(i,N) {
		cin>>BX[i]>>BY[i];
		M[{BX[i],BY[i]}]=i;
		mf.add_edge(20000+i,40001,1);
	}
	FOR(i,N) {
		int dy[8]={0,T,T,T,0,-T,-T,-T};
		int dx[8]={T,T,0,-T,-T,-T,0,T};
		FOR(j,8) {
			if(M.count({AX[i]+dx[j],AY[i]+dy[j]})) {
				mf.add_edge(i,M[{AX[i]+dx[j],AY[i]+dy[j]}]+20000,1);
			}
			else {
				mf.add_edge(i,40003,1);
			}
		}
	}
	if(mf.maxflow(40000,40001)==N) {
		cout<<"Yes"<<endl;
		FOR(i,N) {
			for(j=1;j<=8;j++) if(mf.E[i][j].cap==0) cout<<j<<" ";
		}
		cout<<endl;
		
	}
	else {
		cout<<"No"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
