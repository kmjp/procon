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

int T,N;
int C[2020];
vector<int> E[2020];
int D[2020];
int U[2020],V[2020];
int CF[2020],CT[2020];

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 202020;
	int NV=MV;
	vector<edge> E[MV];
	int itr[MV],lev[MV],mincut[MV]; //1Ç»ÇÁsourceë§
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
		//ç≈è¨ÉJÉbÉgïúå≥
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

void dfs(int cur,int pre,int c) {
	D[cur]=c;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,c^1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>s;
		FOR(i,N) {
			if(s[i]=='R') C[i]=0;
			if(s[i]=='G') C[i]=1;
			if(s[i]=='B') C[i]=2;
			E[i].clear();
		}
		FOR(i,N-1) {
			cin>>U[i]>>V[i];
			U[i]--;
			V[i]--;
			E[U[i]].push_back(V[i]);
			E[V[i]].push_back(U[i]);
		}
		dfs(0,0,0);
		mf.init(3*N+2);
		FOR(i,N) {
			int F[3]={};
			FOR(j,E[i].size()) F[(C[i]+j)%3]++;
			if(D[i]==0) {
				FOR(j,3) mf.add_edge(3*N,3*i+j,F[j]);
			}
			else {
				FOR(j,3) mf.add_edge(3*i+j,3*N+1,F[j]);
			}
		}
		map<pair<int,int>,int> M;
		FOR(i,N-1) {
			if(D[U[i]]==1) swap(U[i],V[i]);
			M[{U[i],V[i]}]=i;
			mf.add_edge(3*U[i]+0,3*V[i]+1,1);
			mf.add_edge(3*U[i]+0,3*V[i]+2,1);
			mf.add_edge(3*U[i]+1,3*V[i]+0,1);
			mf.add_edge(3*U[i]+1,3*V[i]+2,1);
			mf.add_edge(3*U[i]+2,3*V[i]+0,1);
			mf.add_edge(3*U[i]+2,3*V[i]+1,1);
		}
		int ret=mf.maxflow(3*N,3*N+1);
		if(ret==N-1) {
			cout<<"Yes"<<endl;
			FOR(i,N) if(D[i]==0) {
				FOR(j,3) {
					FORR(e,mf.E[i*3+j]) if(e.to<3*N&&e.cap==0) {
						x=e.to/3;
						y=e.to%3;
						k=M[{i,x}];
						CF[k]=j;
						CT[k]=y;
					}
				}
			}
			vector<int> ret;
			FOR(i,N-1) {
				FOR(j,N-1) if(U[j]>=0&&C[U[j]]==CF[j]&&C[V[j]]==CT[j]) {
					cout<<j+1<<" ";
					(C[U[j]]=C[U[j]]+1)%=3;
					(C[V[j]]=C[V[j]]+1)%=3;
					U[j]=-1;
					break;
				}
			}
			cout<<endl;
			
			
		}
		else {
			cout<<"No"<<endl;
		}
			
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
