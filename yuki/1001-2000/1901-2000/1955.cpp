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

int N;
string A[505],B[505];

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV*2; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV/2)%NV,y%NV);
		sc.add_edge((y+NV/2)%NV,x%NV);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};

TwoSat ts;

int ok(string a,string b) {
	a+=b;
	int v=atoi(a.c_str());
	for(ll i=2;i*i<=v;i++) if(v%i==0) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ts.init(N);
	FOR(i,N) {
		cin>>A[i]>>B[i];
		if(!ok(A[i],B[i])) ts.add_edge(N+i,N+i);
		if(!ok(B[i],A[i])) ts.add_edge(i,i);
		FOR(j,i) {
			if(!ok(A[i],B[j])||!ok(A[i],B[i])||!ok(A[j],B[i])||!ok(A[j],B[j])) ts.add_edge(N+i,N+j);
			if(!ok(B[i],B[j])||!ok(B[i],A[i])||!ok(A[j],A[i])||!ok(A[j],B[j])) ts.add_edge(i,N+j);
			if(!ok(A[i],A[j])||!ok(A[i],B[i])||!ok(B[j],B[i])||!ok(B[j],A[j])) ts.add_edge(N+i,j);
			if(!ok(B[i],A[j])||!ok(B[i],A[i])||!ok(B[j],A[i])||!ok(B[j],A[j])) ts.add_edge(i,j);
		}
	}
	if(ts.sat()) {
		cout<<"Yes"<<endl;
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
