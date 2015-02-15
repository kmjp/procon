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


int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

class FoxAndGo {
	public:
	vector<string> V;
	int W,H;
	int ID[51][51];
	int num[2501];
	set<int> E[2501];
	
	void dfs(int y,int x,int id) {
		int i,tx,ty;
		
		ID[y][x]=id;
		num[id]++;
		FOR(i,4) {
			tx=x+dx[i];
			ty=y+dy[i];
			if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
			if(V[ty][tx]=='o' && ID[ty][tx]==-1) dfs(ty,tx,id);
		}
	}
	
	int maxKill(vector <string> board) {
		int i,j,x,y,tx,ty,ret=0;
		V=board;
		H=V.size();
		W=V[0].size();
		
		MINUS(ID);
		ZERO(num);
		int id=0;
		FOR(y,H) FOR(x,W) if(board[y][x]=='o' && ID[y][x]==-1) {
			E[id].clear();
			dfs(y,x,id++);
		}
		
		FOR(y,H) FOR(x,W) if(board[y][x]=='.') {
			FOR(i,4) {
				tx=x+dx[i];
				ty=y+dy[i];
				if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
				if(V[ty][tx]=='o') E[ID[ty][tx]].insert(y*100+x);
			}
		}
		
		FOR(y,H) FOR(x,W) if(board[y][x]=='.') {
			int i,tx,ty;
			set<int> IDs;
			FOR(i,4) {
				tx=x+dx[i];
				ty=y+dy[i];
				if(tx<0 || tx>=W || ty<0 || ty>=H) continue;
				if(V[ty][tx]=='o') IDs.insert(ID[ty][tx]);
			}
			j=0;
			ITR(it,IDs) if(E[*it].size()==1) j+=num[*it];
			ret=max(j,ret);
		}
		FOR(i,id) if(E[i].empty()) ret += num[i];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".....",
 "..x..",
 ".xox.",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, maxKill(Arg0)); }
	void test_case_1() { string Arr0[] = {"ooooo",
 "xxxxo",
 "xxxx.",
 "xxxx.",
 "ooooo"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, maxKill(Arg0)); }
	void test_case_2() { string Arr0[] = {".xoxo",
 "ooxox",
 "oooxx",
 "xoxox",
 "oxoox"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(2, Arg1, maxKill(Arg0)); }
	void test_case_3() { string Arr0[] = {".......",
 ".......",
 ".......",
 "xxxx...",
 "ooox...",
 "ooox...",
 "ooox..."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(3, Arg1, maxKill(Arg0)); }
	void test_case_4() { string Arr0[] = {".......",
 ".xxxxx.",
 ".xooox.",
 ".xo.ox.",
 ".xooox.",
 ".xxxxx.",
 "......."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(4, Arg1, maxKill(Arg0)); }
	void test_case_5() { string Arr0[] = {"o.xox.o",
 "..xox..",
 "xxxoxxx",
 "ooo.ooo",
 "xxxoxxx",
 "..xox..",
 "o.xox.o"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 12; verify_case(5, Arg1, maxKill(Arg0)); }
	void test_case_6() { string Arr0[] = {".......",
 "..xx...",
 ".xooox.",
 ".oxxox.",
 ".oxxxo.",
 "...oo..",
 "......."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, maxKill(Arg0)); }
	void test_case_7() { string Arr0[] = {".ox....",
 "xxox...",
 "..xoox.",
 "..xoox.",
 "...xx..",
 ".......",
 "......."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(7, Arg1, maxKill(Arg0)); }
	void test_case_8() { string Arr0[] = {"...................",
 "...................",
 "...o..........o....",
 "................x..",
 "...............x...",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "...................",
 "................o..",
 "..x................",
 "...............x...",
 "...................",
 "..................."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(8, Arg1, maxKill(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  FoxAndGo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
