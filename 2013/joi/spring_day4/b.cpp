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
	static const int MV = 1015000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<MV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
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

SCC sb;
int N;
ll A[1010101],B[1010101],C[1010101],D[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	sb.init(N);
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
		A[i]--;
		sb.add_edge(i,A[i]);
	}
	sb.scc();
	ll ret=0;
	FORR(sc,sb.SC) {
		if(sc.size()==1) {
			x=sc[0];
			ret+=B[x]*max(C[A[x]],D[A[x]]);
		}
		else {
			ll from[2]={};
			vector<int> cand;
			x=sc[0];
			cand.push_back(x);
			FOR(i,sc.size()-1) cand.push_back(A[cand.back()]);
			
			for(i=cand.size()-2;i>=0;i--) {
				x=cand[i];
				y=cand[i+1];
				ll to[2]={};
				if(i==cand.size()-2) {
					to[0]=B[x]*C[y];
					to[1]=B[x]*D[y];
				}
				else {
					to[0]=max(from[0]+B[x]*C[y],from[1]+B[x]*D[y]);
					to[1]=max(from[1]+B[x]*C[y],from[0]+B[x]*D[y]);
				}
				swap(from,to);
			}
			y=cand[0];
			x=cand.back();
			ret += max(from[0]+B[x]*C[y],from[1]+B[x]*D[y]);
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
