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

typedef signed long long s64;
typedef unsigned long long u64;

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


class FoxAndFlowerShopDivTwo {
	public:
	char str[20][20];
	int W,H;
	int fl[40][40];
	
	int rect(int x1,int y1,int x2,int y2) {
		return fl[y2][x2]-fl[y1][x2]-fl[y2][x1]+fl[y1][x1];
	}

	int theMaxFlowers(vector <string> flowers, int r, int c) {
		H = flowers.size();
		W = strlen(flowers[0].c_str());
		int i;
		FOR(i,H) strcpy(str[i],flowers[i].c_str());
		
		int x,y,tx,ty,l,p,best;
		best=0;
		l=p=0;
		ZERO(fl);
		FOR(y,H+1) FOR(x,W+1) {
			FOR(ty,y) FOR(tx,x) {
				if(str[ty][tx]=='F') fl[y][x]++;
			}
		}
		
		FOR(y,H) FOR(x,W) {
			for(ty=y+1;ty<H+1;ty++) {
				for(tx=x+1;tx<W+1;tx++) {
					if(y<=r && r<ty && x<=c && c<tx) continue;
					l = rect(x,y,tx,ty);
					if(l>best) best=l;
				}
			}
		}
		return best;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"F.F",
 ".F.",
 ".F."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"F..",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; verify_case(1, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {".FF.F.F",
 "FF...F.",
 "..FF.FF"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; int Arg3 = 6; verify_case(2, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"F",
 ".",
 "F",
 "F",
 "F",
 ".",
 "F",
 "F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 0; int Arg3 = 3; verify_case(3, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {".FFF..F...",
 "FFF...FF.F",
 "..F.F.F.FF",
 "FF..F.FFF.",
 "..FFFFF...",
 "F....FF...",
 ".FF.FF..FF",
 "..F.F.FFF.",
 ".FF..F.F.F",
 "F.FFF.FF.F"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 3; int Arg3 = 32; verify_case(4, Arg3, theMaxFlowers(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
  FoxAndFlowerShopDivTwo ___test;
  ___test.run_test(-1);
}
// END CUT HERE
