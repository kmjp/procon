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

int N;
int X[101],Y[101];
ll V[101];
int L[101],R[101],U[101],D[101];

int M;
string S[333];
int A[333],B[333];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost) {
						dist[e.to]=d+e.cost;
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			ll lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i]>>V[i];
	cin>>M;
	FOR(i,M) cin>>S[i]>>A[i]>>B[i];
	
	ll ret=0;
	for(int K=1;K<=N;K++) {
		MinCostFlow<450,ll> mcf;
		ZERO(L);
		ZERO(D);
		FOR(x,101) U[x]=R[x]=100;
		FOR(i,M) if(B[i]<K) {
			if(S[i]=="L") L[B[i]]=max(L[B[i]],A[i]+1);
			if(S[i]=="D") D[B[i]]=max(D[B[i]],A[i]+1);
			if(S[i]=="R") R[K-B[i]-1]=min(R[K-B[i]-1],A[i]-1);
			if(S[i]=="U") U[K-B[i]-1]=min(U[K-B[i]-1],A[i]-1);
		}
		for(i=1;i<K;i++) L[i]=max(L[i],L[i-1]), D[i]=max(D[i],D[i-1]);
		for(i=K-2;i>=0;i--) R[i]=min(R[i],R[i+1]), U[i]=min(U[i],U[i+1]);
		
		FOR(i,K) {
			mcf.add_edge(0,1+i,1,0);
			mcf.add_edge(101+i,100,1,0);
		}
		FOR(i,N) {
			mcf.add_edge(200+i,300+i,1,1000000000000000LL-V[i]);
			FOR(j,K) {
				if(L[j]<=X[i] && X[i]<=R[j]) mcf.add_edge(1+j,200+i,1,0);
				if(D[j]<=Y[i] && Y[i]<=U[j]) mcf.add_edge(300+i,101+j,1,0);
			}
		}
		ll v=mcf.mincost(0,100,K);
		if(v>=0) ret=max(ret,K*1000000000000000LL-v);
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
