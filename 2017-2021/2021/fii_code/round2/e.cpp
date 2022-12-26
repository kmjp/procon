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

int N,K,X;
int A[101010];
vector<int> V[101010];
const int prime_max = 1000000;
vector<int> prime;
int NP,divp[prime_max];

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime.push_back(i); NP++;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) if(divp[j]==0) divp[j]=i;
	}
}

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 2020202;
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

map<int,int> P,Q;
MaxFlow_dinic<int> mf;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N>>K>>X;
	FOR(i,N) {
		cin>>A[i];
		for(j=0;prime[j]*prime[j]<=A[i];j++) if(A[i]%prime[j]==0) {
			V[i].push_back(prime[j]);
			P[prime[j]]++;
			while(A[i]%prime[j]==0) A[i]/=prime[j];
		}
		if(A[i]>1) {
			V[i].push_back(A[i]);
			P[A[i]]++;
		}
	}
	x=0;
	y=-1;
	vector<int> QQ;
	FORR2(p,q,P) {
		QQ.push_back(p);
		Q[p]=x++;
		if(q>=X) y=p;
	}
	if(y==-1) {
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}
	FOR(i,N) {
		mf.add_edge(0,i+1,1);
		FORR(v,V[i]) mf.add_edge(i+1,(N+1)+Q[v],1);
	}
	FORR2(p,q,Q) {
		if(p==y) {
			mf.add_edge((N+1)+q,1500000,X);
		}
		else {
			mf.add_edge((N+1)+q,1500001,X);
		}
	}
	mf.add_edge(1500001,1500000,K-X);
	x=mf.maxflow(0,1500000);
	
	if(x<K) {
		cout<<"IMPOSSIBLE"<<endl;
	}
	else {
		FOR(i,N) {
			int tar=-1;
			FORR(e,mf.E[i+1]) if(e.to>0&&e.cap==0) {
				
				tar=QQ[e.to-(N+1)];
			}
			cout<<tar<<" ";
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
