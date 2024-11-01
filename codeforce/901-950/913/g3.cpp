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
string S;
int A[202020];
vector<int> E[202020];
int inloop[202020],vis[202020];
vector<int> R;

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
SCC scc;

void num(int x,int y,vector<int>& R) {
	if(A[x]==y) {
		R.push_back(x+1);
	}
	else if(A[y]==x) {
		R.push_back(y+1);
	}
	else {
		cout<<"#"<<x<<" "<<y<<endl;
		R.push_back(-1);
	}
}

void dfs(int cur,int pre) {
	FORR(e,E[cur]) if(inloop[e]==0&&e!=pre) {
		dfs(e,cur);
		if(S[e]) {
			num(e,cur,R);
			S[e]^=1;
			S[cur]^=1;
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		FOR(i,N) {
			S[i]-='0';
			cin>>A[i];
			A[i]--;
			E[i].clear();
		}
		scc.init(N);
		R.clear();
		FOR(i,N) {
			E[i].push_back(A[i]);
			E[A[i]].push_back(i);
			scc.add_edge(i,A[i]);
			vis[i]=0;
		}
		scc.scc();
		FOR(i,N) inloop[i]=(scc.SC[scc.GR[i]].size()>1);
		FOR(i,N) if(inloop[i]) {
			dfs(i,i);
		}
		
		FOR(i,N) if(inloop[i]&&vis[i]==0) {
			vector<int> V,X;
			int cur=i;
			while(1) {
				if(S[cur]) X.push_back(V.size());
				V.push_back(cur);
				vis[cur]=1;
				x=0;
				FORR(e,E[cur]) if(inloop[e]&&vis[e]==0) {
					cur=e;
					x=1;
					break;
				}
				if(x==0) break;
			}
			if(X.empty()) continue;
			if(X.size()%2) {
				R.push_back(-1);
				break;
			}
			vector<int> AA[2];
			X.push_back(X[0]+V.size());
			for(j=0;j<(int)X.size()-1;j++) {
				x=X[j];
				y=X[j+1];
				while(x!=y) {
					num(V[x%V.size()],V[(x+1)%V.size()],AA[j%2]);
					x++;
				}
			}
			
			if(AA[0].size()>AA[1].size()) swap(AA[0],AA[1]);
			FORR(a,AA[0]) R.push_back(a);
			
		}
		sort(ALL(R));
		if(R.size()&&R[0]==-1) {
			cout<<-1<<endl;
		}
		else {
			cout<<R.size()<<endl;
			FORR(r,R) cout<<r<<" ";
			cout<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
