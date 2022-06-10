#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V> class MaxFlow_dinic {
public:
	struct edge { int to,reve;V cap;};
	static const int MV = 3000;
	vector<edge> E[MV];
	int itr[MV],lev[MV];
	void add_edge(int x,int y,V cap,bool undir=false) {
		E[x].push_back((edge){y,(int)E[y].size(),cap});
		E[y].push_back((edge){x,(int)E[x].size()-1,undir?cap:0});
	}
	void bfs(int cur) {
		MINUS(lev);
		queue<int> q;
		lev[cur]=0;
		q.push(cur);
		while(q.size()) {
			int v=q.front(); q.pop();
			FORR(e,E[v]) if(e.cap>0 && lev[e.to]<0) lev[e.to]=lev[v]+1, q.push(e.to);
		}
	}
	V dfs(int from,int to,V cf) {
		if(from==to) return cf;
		for(;itr[from]<E[from].size();itr[from]++) {
			edge* e=&E[from][itr[from]];
			if(e->cap>0 && lev[from]<lev[e->to]) {
				V f=dfs(e->to,to,min(cf,e->cap));
				if(f>0) {
					e->cap-=f;
					E[e->to][e->reve].cap += f;
					return f;
				}
			}
		}
		return 0;
	}
	V maxflow(int from, int to) {
		V fl=0,tf;
		while(1) {
			bfs(from);
			if(lev[to]<0) return fl;
			ZERO(itr);
			while((tf=dfs(from,to,numeric_limits<V>::max()))>0) fl+=tf;
		}
	}
};

int vis[2500];

class Potatoes {
	public:
	vector <string> plant(vector <string> F, int N) {
		MaxFlow_dinic<int> mf;
		
		int H=F.size();
		int W=F[0].size();
		int y,x;
		FOR(y,H) FOR(x,W) if(F[y][x]=='.') {
			if((y+x)%2==0) {
				mf.add_edge(2500,y*50+x,1);
				int i;
				int d[4]={0,1,0,-1};
				FOR(i,4) {
					int ty=y+d[i];
					int tx=x+d[i^1];
					if(ty>=0&&ty<H&&tx>=0&&tx<W) mf.add_edge(y*50+x,ty*50+tx,1);
				}
			}
			else {
				mf.add_edge(y*50+x,2501,1);
			}
		}
		int tar=mf.maxflow(2500,2501);
		
		ZERO(vis);
		queue<int> Q;
		FOR(y,H) FOR(x,W) if(F[y][x]=='.') {
			if((y+x)%2==0) {
				FORR(e,mf.E[y*50+x]) if(e.to==2500&&e.cap==0) {
					vis[y*50+x]=1;
					Q.push(y*50+x);
				}
			}
		}
		while(Q.size()) {
			int cur=Q.front();
			Q.pop();
			
			FORR(e,mf.E[cur]) if(e.to<2500&&e.cap==1&&vis[e.to]==0&&F[e.to/50][e.to%50]=='.') {
				vis[e.to]=1;
				Q.push(e.to);
			}
		}
		
		cout<<N<<" "<<tar<<endl;
		FOR(y,H) FOR(x,W) if(N&&F[y][x]=='.') {
			if((y+x)%2==0) {
				if(vis[y*50+x]==1) F[y][x]='P', N--;
			}
			else {
				if(vis[y*50+x]==0) F[y][x]='P', N--;
			}
		}
		cout<<N<<endl;
		if(N) return {};
		return F;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"........",
 "........",
 "........",
 "........"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"P.P.P...", "........", "........", "........" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, plant(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"####.###",
 "##.#####",
 "######.#",
 "###.####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; string Arr2[] = {"####P###", "##P#####", "######P#", "###.####" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, plant(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"####.###",
 "##.#####",
 "######.#",
 "##..####"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, plant(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {".........",
 ".........",
 ".........",
 ".........",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 23; string Arr2[] = {"P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P", ".P.P.P.P.", "P.P.P.P.P" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(3, Arg2, plant(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {".........",
 ".........",
 ".........",
 ".........",
 "........."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; string Arr2[] = { }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(4, Arg2, plant(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {".........",
 "#########",
 ".#......#",
 ".########",
 ".#.....##"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; string Arr2[] = {"P.P.P.P.P", "#########", "P#P.P.P.#", ".########", "P#P.P.P##" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(5, Arg2, plant(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Potatoes ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

