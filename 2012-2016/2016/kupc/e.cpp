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

int H,W;
string S[202];

template<class V> class MaxFlow_Ford {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 30000;
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

MaxFlow_Ford<int> mf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) if(S[y][0]=='X' || S[y][W-1]=='X') return _P("-1\n");
	FOR(x,W) if(S[0][x]=='X' || S[H-1][x]=='X') return _P("-1\n");
	
	FOR(y,H) FOR(x,W) {
		mf.add_edge(y*100+x,10000+y*100+x,(S[y][x]=='X')?101010:1);
		if(S[y][x]=='X') mf.add_edge(20010,y*100+x,101010);
		if(y==0 || x==0 || y==H-1 || x==W-1) mf.add_edge(10000+y*100+x,20011,101010);
		if(y) mf.add_edge(10000+y*100+x,(y-1)*100+x,101010);
		if(x) mf.add_edge(10000+y*100+x,y*100+(x-1),101010);
		if(y<H-1) mf.add_edge(10000+y*100+x,(y+1)*100+x,101010);
		if(x<W-1) mf.add_edge(10000+y*100+x,y*100+(x+1),101010);
	}
	cout<<mf.maxflow(20010,20011)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}
