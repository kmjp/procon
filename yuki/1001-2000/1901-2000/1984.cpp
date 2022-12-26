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

int N,M,K,P;
int E[55],F[55],V[55];
int L[55];
vector<int> A[55];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 1100;
	vector<edge> E[MV];
	int itr[MV],lev[MV],mincut[MV]; //1ならsource側
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
		//最小カット復元
		ZERO(mincut);
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
MaxFlow_dinic<ll> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>P;
	ll ret=0;
	FOR(i,N) {
		cin>>x;
		ret+=x;
		mf.add_edge(200,i,x); //実行すると得
	}
	FOR(i,M) {
		cin>>x;
		ret+=x;
		mf.add_edge(N+i,201,x); //反転しておき、実行をやめると損
	}
	FOR(i,K) {
		cin>>x;
		mf.add_edge(N+M+i,201,x); //実行すると損
	}
	FOR(i,N) {
		cin>>k;
		FOR(j,k) {
			cin>>x;
			x--;
			mf.add_edge(i,N+M+x,1LL<<50);
		}
	}
	FOR(i,P) {
		cin>>x>>y;
		x--,y--;
		mf.add_edge(x,N+y,1LL<<50);
	}
	cout<<ret-mf.maxflow(200,201)<<endl;
	vector<int> V;
	FOR(i,K) if(mf.mincut[N+M+i]) V.push_back(N+M+i);
	FOR(i,N) if(mf.mincut[i]) V.push_back(i);
	FOR(i,M) if(!mf.mincut[N+i]) V.push_back(N+i);
	
	cout<<V.size()<<endl;
	FORR(v,V) {
		if(v<N) cout<<"Goal "<<v+1<<endl;
		else if(v<N+M) cout<<"Action "<<v-N+1<<endl;
		else cout<<"Preparation "<<v-N-M+1<<endl;
	}

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
