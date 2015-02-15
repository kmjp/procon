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
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


class Egalitarianism {
	public:
	int N;
	int dist[51][51];
	int maxDifference(vector <string> F, int d) {
		int N=F.size();
		int i,j,k;
		
		FOR(i,N) FOR(j,N) dist[i][j]=(F[i][j]=='Y')?1:1000;
		FOR(i,N) dist[i][i]=0;
		FOR(i,N) FOR(j,N) FOR(k,N) dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
		
		int ma=0;
		FOR(i,N) FOR(j,N) ma=max(ma,dist[i][j]);
		if(ma>=1000) return -1;
		return ma*d;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 20; verify_case(0, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"NN",
 "NN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = -1; verify_case(1, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 3000; verify_case(2, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 584; int Arg2 = -1; verify_case(3, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 20; verify_case(4, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 747; int Arg2 = 2988; verify_case(5, Arg2, maxDifference(Arg0, Arg1)); }
	void test_case_6() { string Arr0[] = {"NY",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 0; verify_case(6, Arg2, maxDifference(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  Egalitarianism ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
