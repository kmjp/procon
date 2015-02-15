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

class TwoLLogo {
	public:
	ll wid[31][31];
	ll hei[31][31];
	vector<pair<int,int> > OK;
	
	ll cross(int a,int b) {
		int ax=OK[a].first;
		int ay=OK[a].second;
		int bx=OK[b].first;
		int by=OK[b].second;
		ll aw=wid[ay][ax];
		ll ah=hei[ay][ax];
		ll bw=wid[by][bx];
		ll bh=hei[by][bx];
		
		if(ax==bx && by-bh<ay) return aw*bw*ah*(bh-(by-ay)+1);
		if(ay==by && ax+aw>=bx) return ah*bh*bw*(aw-(bx-ax)+1);
		if(ax<bx && ay<by && ax+aw>=bx && by-bh<=ay) return ah*bw*(aw-(bx-ax)+1)*(bh-(by-ay)+1);
		
		return 0;
	}
	
	long long countWays(vector <string> grid) {
		int H,W,x,y,z;
		H=grid.size();
		W=grid[0].size();
		OK.clear();
		
		MINUS(wid);
		MINUS(hei);
		FOR(y,H) for(x=W-1;x>=0;x--) if(grid[y][x]!='#') wid[y][x]=wid[y][x+1]+1;
		FOR(x,W) FOR(y,H) if(grid[y][x]!='#') hei[y][x]=((y>0)?hei[y-1][x]:-1)+1;
		FOR(y,H) FOR(x,W) if(wid[y][x]>0 && hei[y][x]>0) OK.push_back(make_pair(x,y));
		
		ll ret=0;
		FOR(x,OK.size()) for(y=x+1;y<OK.size();y++) {
			
			ret+=wid[OK[x].second][OK[x].first]*hei[OK[x].second][OK[x].first]*
			wid[OK[y].second][OK[y].first]*hei[OK[y].second][OK[y].first];
			ret-=cross(x,y);
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"....",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(0, Arg1, countWays(Arg0)); }
	void test_case_1() { string Arr0[] = {".##..",
 "...#.",
 ".#.#.",
 "#...#"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 3LL; verify_case(1, Arg1, countWays(Arg0)); }
	void test_case_2() { string Arr0[] = {"..#.",
 "#.#.",
 "....",
 "..#."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 4LL; verify_case(2, Arg1, countWays(Arg0)); }
	void test_case_3() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 0LL; verify_case(3, Arg1, countWays(Arg0)); }
	void test_case_4() { string Arr0[] = {".#.#",
 "....",
 ".#.#",
 "...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 34LL; verify_case(4, Arg1, countWays(Arg0)); }
	void test_case_5() { string Arr0[] = {"##############",
 "##############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.############",
 "#.#####.######",
 "#.#####.######",
 "#.#####.######",
 "#....##.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######.######",
 "#######......#",
 "##############"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1350LL; verify_case(5, Arg1, countWays(Arg0)); }
	void test_case_6() { string Arr0[] = {"#......",
 ".#....#",
 ".#.#...",
 "#....#.",
 ".##..#.",
 ".#.....",
 ".....#.",
 ".#.#...",
 ".#...#.",
 "..##..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2386LL; verify_case(6, Arg1, countWays(Arg0)); }
	void test_case_7() { string Arr0[] = {"...#..........................",
 "..............................",
 "..............................",
 "..................#...#.......",
 "..................#...........",
 "..............................",
 "...........#..................",
 "..............................",
 ".....#..#.....................",
 ".......................#......",
 "..................#.....#.....",
 "..............................",
 "..............................",
 "..............................",
 "..............................",
 "..#...........................",
 "..............................",
 "..............................",
 "..............................",
 "#............................#",
 "..............................",
 ".....#.........#............#.",
 "..............................",
 ".........................#....",
 ".#............................",
 ".............#................",
 "..............................",
 "..............................",
 ".......................#......",
 ".............#................"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5020791386LL; verify_case(7, Arg1, countWays(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoLLogo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

