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

#define DEBUG
#ifdef DEBUG
#define DBG(...) cerr << #__VA_ARGS__ << ": " << __VA_ARGS__ << endl
#define DV(...) cerr << __VA_ARGS__ << endl
#else
#define DBG(...)
#define DV(...)
#endif

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
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
			if(vis[e.to]==0 && e.capacity>0) {
				if((tf = dfs(e.to,to,min(cf,e.capacity)))>0) {
					e.capacity -= tf;
					E[e.to][e.reve].capacity += tf;
					return tf;
				}
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


class GearsDiv1 {
	public:
	int N;
	int sp[3];
	int C[51];
	vector<string> G;
	int van[51];
	int mi;
	
	int testtest() {
		MaxFlow mf;
		int i,j;
		FOR(i,N) {
			if(sp[C[i]]==0) mf.add_edge(0,100+i,1);
			if(sp[C[i]]==1) mf.add_edge(200+i,300,1);
			FOR(j,N) {
				if(sp[C[i]]==0 && sp[C[j]]==1 && G[i][j]=='Y') mf.add_edge(100+i,200+j,1);
			}
		}
		
		return mf.maxflow(0,300);
	}
	
	
	int getmin(string color, vector <string> graph) {
		N=color.size();
		
		int i;
		G=graph;
		FOR(i,N) {
			if(color[i]=='R') C[i]=0;
			if(color[i]=='G') C[i]=1;
			if(color[i]=='B') C[i]=2;
		}
		
		int mi=100;
		sp[0]=0; sp[1]=1; sp[2]=2; mi=min(mi,testtest());
		sp[0]=0; sp[1]=2; sp[2]=1; mi=min(mi,testtest());
		sp[0]=2; sp[1]=0; sp[2]=1; mi=min(mi,testtest());
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RGB"; string Arr1[] = {"NYY","YNY","YYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "RGBR"; string Arr1[] = {"NNNN","NNNN","NNNN","NNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "RGBR"; string Arr1[] = {"NYNN","YNYN","NYNY","NNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_32() { string Arg0 = "RRRRRGRRBGRRGBBGGGBRRRGBRGRRGG"; string Arr1[] = {"NNNNNYNNNYNNYNNNYNNNNNNNNYNNYY",
 "NNNNNNNNYNNNYNYNNYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNNNNYNNNNNNYNNNY",
 "NNNNNNNNNYNNYNNYYYNNNNYNNYNNNN",
 "NNNNNNNNNYNNYNNYYYNNNNYNNNNNNN",
 "YNYNNNYYYNNYNYYNNNNNYYNYNNYYNN",
 "NNNNNYNNNNNNNNNYYYNNNNYNNYNNYY",
 "NNNNNYNNNNNNNNNYNNNNNNNNNNNNYN",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "YNNYYNNNYNNNNYYNNNYNYYNYNNNNNN",
 "NNNNNNNNNNNNYNNYNYNNNNYNNNNNNY",
 "NNNNNYNNNNNNYNNYYYNNNNNNNNNNYN",
 "YYNYYNNNYNYYNYYNNNYNYNNYNNNNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNYNYYY",
 "NYNNNYNNNYNNYNNYYYNNNNYNNYNNYY",
 "NNNYYNYYYNYYNYYNNNYNYNNYYNYYNN",
 "YNNYYNYNYNNYNYYNNNYNNNNYYNNYNN",
 "NYNYYNYNYNYYNYYNNNNYYNNYYNYNNN",
 "NNYNNNNNNYNNYNNYYNNNNNYNNYNNNY",
 "NNNNNNNNNNNNNNNNNYNNNNYNNYNNNY",
 "NNNNNYNNNYNNYNNYNYNNNNYNNNNNYY",
 "NNNNNYNNNYNNNNNNNNNNNNYNNNNNNN",
 "NYNYYNYNYNYNNYYNNNYYYYNYYNYNNN",
 "NNNNNYNNNYNNYNNYYYNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNNYYYNNNNYNNYNNYY",
 "YYYYNNYNYNNNNYYNNNYYNNNNYNYYNN",
 "NNNNNYNNNNNNNNNYNYNNNNYNNYNNYN",
 "NNNNNYNNNNNNNYNYYNNNNNNNNYNNYY",
 "YYNNNNYYYNNYNYYNNNNNYNNNYNYYNN",
 "YYYNNNYNYNYNNYYNNNYYYNNYYNNYNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "BRRGBGBGGGBBBRBBBGGBBBGGRRRRRGBRRGRGBBRRGGRGRRGB"; string Arr1[] = {"NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNYNN", "NNNNYNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNYNNNYNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNYNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNN", "NNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNYNY", "NNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNN", "NNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNYNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNYYNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNYNNNNNY", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNY", "NNNNNNNNNNNYNNNNNNNYNNYNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNYNNYNNNNNNNNNNNNNNNN", "NNNNYNNYNNNYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNY", "YNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNN", "YNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNNNNNNNNNNNNNNNNN", "NYNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNN", "NNNNNNNNNNNNNNNNNNNNNNNYNNNNNNNNYYNNNNNNNYNNNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(3, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  GearsDiv1 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
