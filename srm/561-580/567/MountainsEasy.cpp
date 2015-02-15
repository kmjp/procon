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
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

ll MO=1000000009;
ll tmemo[51][51];
ll pmemo[2501][51];
ll C[2501][51];

class MountainsEasy {
	int MN;
	int TP;
	int W,H;
	char str[51][51];
	public:
	
	ll calc2(int LP,int LN) {
		int i;
		ll& res = pmemo[LP][LN];
		if(res != -1) return res;
		if(LP==0 && LN>0) {
			res=0;
		}
		else if(LN==0) {
			res=1;
		}
		else {
			res = 0;
			for(i=0;i<=LN;i++) {
				ll co = C[LN][i];
				res = (res + co*calc2(LP-1,LN-i)) % MO;
			}
		}
		return res;
	} 
	
	ll calc(int LT, int LN) {
		int i;
		ll& res = tmemo[LT][LN];
		if(res != -1) return res;
		if(LT>LN) return 0;
		
		if(LT==0) {
			res = calc2(MN,LN);
		}
		else {
			res = 0;
			for(i=1;i<=LN-(LT-1);i++) {
				res = (res + C[LN][i]*calc(LT-1,LN-i)) % MO;
			}
		}
		return res;
	}
	
	int countPlacements(vector <string> picture, int N) {
		int x,y,ty,tx;
		H=picture.size();
		W=picture[0].size();
		
		TP=MN=0;
		FOR(y,H) strcpy(str[y],picture[y].c_str());
		FOR(y,H) FOR(x,W) if(str[y][x]=='X') MN++;
		FOR(y,H) FOR(x,W) {
			if(str[y][x]!='X') continue;
			TP++;
			for(ty=y;ty<H;ty++) {
				for(tx=x-abs(ty-y);tx<=x+abs(ty-y);tx++) {
					if(tx>=0 && tx<W) str[ty][tx]='.';
				}
			}
		}
		
		ZERO(C);
		for(x=0;x<2501;x++) C[x][0]=1;
		for(x=1;x<2501;x++) for(y=1;y<51;y++) C[x][y]=(C[x-1][y]+C[x-1][y-1])%MO;
		FOR(x,51) FOR(y,51) tmemo[x][y]=-1;
		FOR(x,2501) FOR(y,51) pmemo[x][y]=-1;
		
		MN-=TP;
		return calc(TP,N); 
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"X.",
 "XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; verify_case(0, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"X.",
 "XX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(1, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"X.X",
 "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; verify_case(2, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"X.X",
 "XXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 24; verify_case(3, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(4, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"......",
 "X..X..",
 "XXXXXX",
 "XXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 300; verify_case(5, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_7() { string Arr0[] = {"....X...X..",
 "...XXX.XXX.",
 "XXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 764632413; verify_case(6, Arg2, countPlacements(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {".....X....................", "....XXX............X......", "...XXXXX..........XXX.....", "..XXXXXXX........XXXXX....", ".XXXXXXXXX......XXXXXXX...", "XXXXXXXXXXX....XXXXXXXXX..", "XXXXXXXXXXXX..XXXXXXXXXXX.", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX", "XXXXXXXXXXXXXXXXXXXXXXXXXX"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 22; int Arg2 = 305782531; verify_case(6, Arg2, countPlacements(Arg0, Arg1)); }

// END CUT HERE

};
// BEGIN CUT HERE
int main(int argc, char** argv) {
  MountainsEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
