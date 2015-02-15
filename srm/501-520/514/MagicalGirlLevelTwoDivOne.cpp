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

ll mo=1000000007;
ll p[2][2501];
ll rowdp[11][1<<11];
ll rowdp2[11][1<<11];

class MagicalGirlLevelTwoDivOne {
	public:
	int W,H;
	int num[51][51];
	int ms[51][51];
	
	int theCount(vector <string> palette, int n, int m) {
		int x,y,i,mask,mask2;
		H=palette.size();
		W=palette[0].size();
		
		p[0][0]=p[1][0]=1;
		FOR(i,2500) p[0][i+1]=p[0][i]*4%mo,p[1][i+1]=p[1][i]*5%mo;
		
		ZERO(num);
		ZERO(ms);
		
		FOR(y,H) FOR(x,W) {
			if(palette[y][x] == '.') num[y%n][x%m]++;
			if(isdigit(palette[y][x])) ms[y%n][x%m] |= 1<<(palette[y][x]%2);
		}
		
		ZERO(rowdp);
		ZERO(rowdp2);
		rowdp2[0][0]=1;
		
		FOR(y,n) FOR(mask,1<<m) if(__builtin_popcount(mask)%2) {
			rowdp[y][mask]=1;
			FOR(x,m) {
				if(mask & (1<<x)) {
					if(ms[y][x]&1) rowdp[y][mask]=0;
					else rowdp[y][mask]=rowdp[y][mask]*p[1][num[y][x]]%mo;
				}
				else {
					if(ms[y][x]&2) rowdp[y][mask]=0;
					else rowdp[y][mask]=rowdp[y][mask]*p[0][num[y][x]]%mo;
				}
			}
			FOR(mask2,1<<m) rowdp2[y+1][mask^mask2] = (rowdp2[y+1][mask^mask2] + rowdp2[y][mask2]*rowdp[y][mask])%mo;
		}
		
		return rowdp2[n][(1<<m)-1];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12",
 "2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"21",
 "1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1953125; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"..58..",
 "..47.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 0; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"...1.2.3",
 "4.5.6...",
 "...7.8.9",
 "1.2.3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; int Arg3 = 886073030; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "....................",
 "...................."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 10; int Arg3 = 240076532; verify_case(5, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MagicalGirlLevelTwoDivOne ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

