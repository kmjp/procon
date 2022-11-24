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

int N,M,Q;
class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x);}
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
	void init(int NV) { this->NV=NV; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV)%(2*NV),y%(2*NV));
		sc.add_edge((y+NV)%(2*NV),x%(2*NV));
	}
	void add_impl(int x,int xt,int y,int yt) { // xがxtならyがyt
		//sc.add_edge(x+(xt?0:NV),y+(yt?0:NV)); <-これでやってしまうと、トポロジカルソートによる値の設定に失敗する
		add_or(x,!xt,y,yt);
	}
	void add_or(int x,int xt,int y,int yt) { // xt=1: x must be true
		add_edge(x+((!xt)?NV:0),y+((!yt)?NV:0));
	}
	void add_and(int x,int xt,int y,int yt) { // and条件
		add_or(x,xt,y,yt);
		add_or(x,!xt,y,yt);
		add_or(x,xt,y,!yt);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV;i++) if(sc.GR[i]==sc.GR[i+NV]) return false;
		for(int i=0;i<NV;i++) val[i]=sc.GR[i]>sc.GR[i+NV];
		return true;
	}
};

TwoSat ts;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	ts.init(N*M);
	FOR(i,N) {
		FOR(j,M-1) {
			ts.add_impl(i*M+j+1,1,i*M+j,1);
		}
	}
	FOR(i,Q) {
		int A,B,L,R;
		cin>>A>>B>>L>>R;
		A--,B--;
		for(x=1;x<=M;x++) {
			y=L-x+1;
			if(y>M) {
				ts.add_or(A*M+x-1,1,A*M+x-1,1);
				ts.add_or(B*M+x-1,1,B*M+x-1,1);
			}
			else if(y>0) {
				ts.add_or(A*M+x-1,1,B*M+y-1,1);
				ts.add_or(B*M+x-1,1,A*M+y-1,1);
			}
			y=R-x+1;
			if(y<=0) {
				ts.add_or(A*M+x-1,0,A*M+x-1,0);
				ts.add_or(B*M+x-1,0,B*M+x-1,0);
			}
			else if(y<=M) {
				ts.add_or(A*M+x-1,0,B*M+y-1,0);
				ts.add_or(B*M+x-1,0,A*M+y-1,0);
			}
			
			
		}
	}
	if(ts.sat()) {
		
		FOR(i,N) {
			int sum=0;
			FOR(j,M) if(ts.val[i*M+j]) sum++;
			cout<<sum<<" ";
		}
	}
	else {
		cout<<"-1"<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
