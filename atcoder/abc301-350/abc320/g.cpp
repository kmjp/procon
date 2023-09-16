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

int N,M;
vector<int> P[10][101];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 202004;
	vector<edge> E[MV];
	int itr[MV],lev[MV],mincut[MV]; //1Ç»ÇÁsourceë§
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
			if(lev[to]<0) break;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
		/*
		//ç≈è¨ÉJÉbÉgïúå≥
		ZERO(mincut);
		queue<int> Q;
		mincut[from]=1;
		Q.push(from);
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			FORR(e,E[cur]) if(e.cap>0&&mincut[e.to]==0) mincut[e.to]=1, Q.push(e.to);
		}
		*/
		return fl;
	}
};

int hoge(int v) {
	int i;
	FOR(i,N) if(P[v][i].empty()) return 1<<30;
	vector<int> C;
	map<int,vector<int>> re;
	
	FOR(i,N) FORR(a,P[v][i]) C.push_back(a);
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	FOR(i,N) {
		FORR(a,P[v][i]) {
			a=lower_bound(ALL(C),a)-C.begin();
			re[a].push_back(i);
		}
	}
	
	MaxFlow_dinic<int> mf;
	int sum=0;
	FOR(i,N) {
		mf.add_edge(202000,i,1);
	}
	FOR(i,C.size()) {
		mf.add_edge(100+i,202001,1);
		FORR(v,re[i]) mf.add_edge(v,100+i,1);
		sum+=mf.maxflow(202000,202001);
		if(sum>=N) return C[i];
	}
	return 1<<30;
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>s;
		FOR(j,M) P[s[j]-'0'][i].push_back(j);
		FOR(j,10) if(P[j][i].size()) {
			for(x=0;P[j][i].size()<N;x++) P[j][i].push_back(P[j][i][x]+M);
			if(P[j][i].size()>N) P[j][i].resize(N);
		}
	}
	
	int mi=1<<30;
	FOR(i,10) mi=min(mi,hoge(i));
	if(mi==1<<30) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
