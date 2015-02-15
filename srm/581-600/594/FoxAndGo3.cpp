#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

class MaxFlow {
public:
	struct edge { int to, capacity, reve;};
	static const int MV = 10000;
	vector<edge> E[MV];
	int vis[MV];
	
	void init() { for(int i=0;i<MV;i++) E[i].clear();}
	MaxFlow() {init();}
	void add_edge(int x,int y, int cap) {
		E[x].push_back((edge){y,cap,E[y].size()});
		E[y].push_back((edge){x,0, E[x].size()-1}); /* rev edge */
	}
	
	int dfs(int from,int to,int cf) {
		int i,tf;
		if(from==to) return cf;
		vis[from]=1;
		FOR(i,E[from].size()) {
			edge& e=E[from][i];
			if(vis[e.to]==0 && e.capacity>0 && (tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
				e.capacity -= tf;
				E[e.to][e.reve].capacity += tf;
				return tf;
			}
		}
		return 0;
	}
	
	int maxflow(int from, int to) {
		int fl=0,tf;
		while(1) {
			ZERO(vis);
			if((tf = dfs(from,to,1<<29))==0) return fl;
			fl+=tf;
		}
	}
};

class FoxAndGo3 {
	public:
	int N;
	vector <string> B;
	
	int maxEmptyCells(vector <string> board) {
		B=board;
		N=B.size();
		
		MaxFlow mf;
		int x,y,i,tx,ty,b=0,e=0;
		int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
		FOR(x,N) FOR(y,N) {
			if(B[x][y]=='o') {
				b++;
				mf.add_edge(0,1+x*50+y,1);
				FOR(i,4) {
					tx=x+dx[i];ty=y+dy[i];
					if(tx<0 || ty<0 || tx>=N || ty>=N) continue;
					if(B[tx][ty]=='.') mf.add_edge(1+x*50+y,1+tx*50+ty,1);
				}
			}
			else if(B[x][y]=='.') {
				e++;
				mf.add_edge(1+x*50+y,3000,1);
			}
		}
		
		return b+e-mf.maxflow(0,3000);
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"o.o",
 ".o.",
 "o.o"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(0, Arg1, maxEmptyCells(Arg0)); }
	void test_case_1() { string Arr0[] = {"...",
 ".o.",
 "..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(1, Arg1, maxEmptyCells(Arg0)); }
	void test_case_2() { string Arr0[] = {"xxxxx",
 "xxoxx",
 "xo.ox",
 "xxoxx",
 "xxxxx"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, maxEmptyCells(Arg0)); }
	void test_case_3() { string Arr0[] = {".xox.",
 ".o.ox",
 "x.o.o",
 "ox.ox",
 ".ox.."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(3, Arg1, maxEmptyCells(Arg0)); }
	void test_case_4() { string Arr0[] = {"o.o.o",
 ".ox..",
 "oxxxo",
 "..x..",
 "o.o.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(4, Arg1, maxEmptyCells(Arg0)); }
	void test_case_5() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(5, Arg1, maxEmptyCells(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndGo3 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

