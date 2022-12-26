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
int H,W;
string S[75];
int C[2];

MaxFlow_Ford<int> mf;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int tot=0;
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='.') {
			tot++;
			if((y+x)&1) {
				mf.add_edge(0,y*40+x+5,1);
				if(y) mf.add_edge(y*40+x+5,2000+(y-1)*40+x+5,50000);
				if(y<H-1) mf.add_edge(y*40+x+5,2000+(y+1)*40+x+5,50000);
				if(x) mf.add_edge(y*40+x+5,2000+y*40+x-1+5,50000);
				if(x<W-1) mf.add_edge(y*40+x+5,2000+y*40+x+1+5,50000);
			}
			else {
				mf.add_edge(2000+y*40+x+5,1,1);
			}
		}
	}
	cout<<tot-mf.maxflow(0,1)<<endl;
	

}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}
