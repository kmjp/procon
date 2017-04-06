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

const int prime_max = 1000000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	if(NP) return;
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>=i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int N;
int S[2020];
int vis[2020];


template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 10000;
	vector<edge> E[MV];
	int vis[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	V dfs(int from,int to,V cf) {
		V tf;
		if(from==to) return cf;
		vis[from]=1;
		FORR(e,E[from]) if(vis[e.to]==0 && e.cap>0 && (tf = dfs(e.to,to,min(cf,e.cap)))>0) {
			e.cap -= tf;
			E[e.to][e.reve].cap += tf;
			return tf;
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,numeric_limits<V>::max()))==0) return fl;
			fl+=tf;
		}
	}
};


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	
	MaxFlow_Ford<int> mf;
	FOR(i,N) {
		cin>>S[i];
		if(S[i]%2==0) mf.add_edge(0,i+1,1);
		else mf.add_edge(i+1,2002,1);
	}
	
	FOR(x,N) FOR(y,N) if(divp[S[x]+S[y]]==0 && S[x]%2==0 && S[y]%2==1) mf.add_edge(x+1,y+1,1);
	mf.maxflow(0,2002);
	
	set<int> V;
	
	vis[0]=1;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		
		V.insert(x);
		FORR(r,mf.E[x]) if(vis[r.to]==0 && r.cap>0) vis[r.to]=1, Q.push(r.to);
	}
	
	set<int> R;
	FOR(x,N) if(((S[x]%2==0) ^ (V.count(x+1)==0))==0) R.insert(S[x]);
	
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
