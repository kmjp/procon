#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class SCC {
public:
	static const int MV = 100;
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
		sc.add_edge((x+NV/2)%NV,y);
		sc.add_edge((y+NV/2)%NV,x);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV/2;i++) if(sc.GR[i]==sc.GR[i+NV/2]) return false;
		for(int i=0;i<NV/2;i++) val[i]=sc.GR[i]>sc.GR[i+NV/2];
		return true;
	}
};

int N;
int A[101],B[101];

vector<int> P[100],Q[100],C[100],T[100][2];
string U[100][2];

int ok(int L,int R) {
	int i,j,x,y,i2,j2;
	int pat[303];
	FOR(i,N) {
		C[i].clear();
		FORR(q,Q[i]) {
			if(q<L) C[i].push_back(0);
			else if(q>=3*N-R) C[i].push_back(2);
			else C[i].push_back(1);
		}
		pat[i]=-1;
		if(C[i]==vector<int>({0,1,2})) {
			pat[i]=0;
			U[i][0]="MRL";
			T[i][0]={Q[i][1],Q[i][2],Q[i][0]};
			U[i][1]="RLM";
			T[i][1]={Q[i][2],Q[i][0],Q[i][1]};
		}
		else {
			if(C[i]==vector<int>({0,0,2})) pat[i]=1, T[i][0]={Q[i][0],Q[i][2],Q[i][1]}, U[i][0]="LRL";
			if(C[i]==vector<int>({0,2,2})) pat[i]=2, T[i][0]={Q[i][1],Q[i][0],Q[i][2]}, U[i][0]="RLR";
			if(C[i]==vector<int>({1,2,2})) pat[i]=3, T[i][0]=Q[i], U[i][0]="MRR";
			if(C[i]==vector<int>({0,0,1})) pat[i]=3, T[i][0]=Q[i], U[i][0]="LLM";
			if(C[i]==vector<int>({1,1,1})) pat[i]=3, T[i][0]=Q[i], U[i][0]="MMM";
			if(C[i]==vector<int>({0,1,1})) pat[i]=3, T[i][0]={Q[i][1],Q[i][0],Q[i][2]}, U[i][0]="MLM";
			if(C[i]==vector<int>({1,1,2})) pat[i]=3, T[i][0]={Q[i][0],Q[i][2],Q[i][1]}, U[i][0]="MRM";
			T[i][1]=T[i][0];
			U[i][1]=U[i][0];
		}
		
		if(pat[i]==-1) return 0;
	}
	
	TwoSat ts;
	ts.init(N);
	FOR(y,N) FOR(x,N) if(x!=y) {
		FOR(i,2) FOR(j,2) {
			int ng=0;
			FOR(i2,3) FOR(j2,3) if(U[x][i][i2]=='M'&&U[y][j][j2]=='M') {
				if(P[x][i2]<P[y][j2]&&T[x][i][i2]>T[y][j][j2]) ng=1;
				if(P[x][i2]>P[y][j2]&&T[x][i][i2]<T[y][j][j2]) ng=1;
			}
			if(ng) ts.add_edge((1-i)*N+x,(1-j)*N+y);
		}
		if(Q[y][0]<Q[x][0]&&Q[y][2]<Q[x][2]) {
			// x shoud be 1 or y should be 0
			if(pat[x]==0&&pat[y]==0) ts.add_edge(N+x,y);
			// x should be 1
			if(pat[x]==0&&pat[y]==2) ts.add_edge(N+x,N+x);
			// y should be 0
			if(pat[x]==1&&pat[y]==0) ts.add_edge(y,y);
			if(pat[x]==1&&pat[y]==2) return 0;
			
		}
	}
	return ts.sat();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,3*N) {
		cin>>A[i];
		A[i]--;
		P[A[i]].push_back(i);
	}
	FOR(i,3*N) {
		cin>>B[i];
		B[i]--;
		Q[B[i]].push_back(i);
	}
	
	int ret=1010;
	int L,R;
	FOR(L,3*N) FOR(R,3*N) if(L+R<=3*N&&ok(L,R)) ret=min(ret,L+R);
	
	if(ret>1000) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
