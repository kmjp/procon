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

class SCC {
public:
	static const int MV = 101000;
	vector<vector<int> > SC; int NV,GR[MV],rev[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu); rev[cu]=ind;
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0; SC.clear(); SC.resize(MV); NUM.clear();
		ZERO(vis); for(int i=0;i<NV;i++) if(!vis[i]) dfs(i);
		ZERO(vis); for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

ll mo=1000000007;

ll combi(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}
int N;
int A[101010];
vector<int> E[101010];
SCC sc;
int nloop[101010];
ll efact[101010];
ll P[101010][3];

ll getloop(int p,int n) {
	int pat = (p>=3 && p%2)?2:1;
	ll pp=1;
	
	ll ret=0;
	for(int e=0;e<=n;e+=2) {
		ret += combi(n,e)*efact[e]%mo*pp%mo*P[n-e][pat]%mo;
		pp = pp*p % mo;
	}
	return ret%mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	efact[0]=1;
	for(i=2;i<=101000;i+=2) efact[i]=efact[i-2]*(i-1)%mo;
	FOR(i,3) {
		P[0][i]=1;
		FOR(j,101000) P[j+1][i]=P[j][i]*i%mo;
	}
	
	cin>>N;
	sc.init(N);
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		sc.add_edge(i,A[i]);
		E[A[i]].push_back(i);
	}
	sc.scc();
	ll ret=1;
	FOR(i,sc.SC.size()) if(sc.SC[i].size()==1) {
		x = sc.SC[i][0];
		if(A[x]!=x && E[x].size()>1) return _P("0\n");
	}

	FOR(i,sc.SC.size()) {
		if(sc.SC[i].size()==1 && A[sc.SC[i][0]]!=sc.SC[i][0]) continue;
		
		int type4=-1;
		vector<int> V;
		r = sc.SC[i][0];
		while(1) {
			if(E[r].size()>2) return _P("0\n");
			V.push_back(0);
			if(E[r].size()==2) {
				type4=V.size()-1;
				x = (sc.GR[r]==sc.GR[E[r][0]])?E[r][1]:E[r][0];
				V.back()++;
				while(E[x].size()) {
					x = E[x][0];
					V.back()++;
				}
			}
			r = A[r];
			if(r==sc.SC[i][0]) break;
		}
		
		if(type4>=0) {
			rotate(V.begin(),V.begin()+type4,V.end());
			reverse(V.begin()+1,V.end());
			j=0;
			while(j<V.size()) {
				x=j+1;
				while(x<V.size() && V[x]==0) x++;
				if(x-j<V[j]) return _P("0\n");
				if(x-j>V[j]) ret=ret*2%mo;
				j = x;
			}
		}
		else {
			nloop[sc.SC[i].size()]++;
		}
	}
	
	FOR(i,N+1) if(nloop[i]) ret=ret*getloop(i,nloop[i])%mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
