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


class ThreeColorabilityEasy {
	public:
	int col[52][52];
	string isColorable(vector <string> cells) {
		int H=cells.size();
		int W=cells[0].size();
		int x,y;
		ZERO(col);
		
		col[0][0]=1;
		if(cells[0][0]=='N') {
			col[1][0]=2;
			col[0][1]=2;
			col[1][1]=3;
		}
		else {
			col[1][0]=2;
			col[0][1]=3;
			col[1][1]=1;
		}
		
		
		FOR(y,H) FOR(x,W) {
			if(x==0 && y==0) continue;
			if(col[x][y]==col[x][y+1]) return "No";
			if(col[x][y]==col[x+1][y]) return "No";
			if(cells[y][x]=='N') {
				if(col[x+1][y]==0) col[x+1][y]=col[x][y+1];
				else if(col[x][y+1]==0) col[x][y+1]=col[x+1][y];
				col[x+1][y+1]=6-col[x][y]-col[x][y+1];
			}
			else {
				if(col[x+1][y]==col[x][y+1]) return "No";
				if(col[x+1][y]==0) col[x+1][y]=6-col[x][y]-col[x][y+1];
				if(col[x][y+1]==0) col[x][y+1]=6-col[x][y]-col[x+1][y];
				col[x+1][y+1]=col[x][y];
			}
		}
		FOR(y,H) if(col[W][y]==col[W][y+1]) return "No";
		FOR(x,W) if(col[x][H]==col[x+1][H]) return "No";
		
		return "Yes";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"Z"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(0, Arg1, isColorable(Arg0)); }
	void test_case_1() { string Arr0[] = {"NZ"
,"NZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(1, Arg1, isColorable(Arg0)); }
	void test_case_2() { string Arr0[] = {"ZZZ"
,"ZNZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(2, Arg1, isColorable(Arg0)); }
	void test_case_3() { string Arr0[] = {"NZNZNNN"
,"NNZNNNZ"
,"NNNNZZZ"
,"ZZZNZZN"
,"ZZNZNNN"
,"NZZZZNN"
,"ZZZNZNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "No"; verify_case(3, Arg1, isColorable(Arg0)); }
	void test_case_4() { string Arr0[] = {"ZZZZ"
,"ZZZZ"
,"ZZZZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Yes"; verify_case(4, Arg1, isColorable(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  ThreeColorabilityEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
