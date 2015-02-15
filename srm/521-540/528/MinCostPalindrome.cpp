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

class MinCostPalindrome {
	public:
	int getMinimum(string s, int oCost, int xCost) {
		int L=s.size(),i,c=0;
		
		FOR(i,L) if(s[i]=='o' && s[L-1-i]=='x') return -1;
		FOR(i,L) if(s[i]=='?') {
			if(s[L-1-i]=='?') c+=2*min(oCost,xCost),s[i]=s[L-1-i]='*';
			if(s[L-1-i]=='o') c+=oCost;
			if(s[L-1-i]=='x') c+=xCost;
		}
		return c;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "oxo?xox?"; int Arg1 = 3; int Arg2 = 5; int Arg3 = 8; verify_case(0, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "x??x"; int Arg1 = 9; int Arg2 = 4; int Arg3 = 8; verify_case(1, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "ooooxxxx"; int Arg1 = 12; int Arg2 = 34; int Arg3 = -1; verify_case(2, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "oxoxooxxxxooxoxo"; int Arg1 = 7; int Arg2 = 4; int Arg3 = 0; verify_case(3, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "?o"; int Arg1 = 6; int Arg2 = 2; int Arg3 = 6; verify_case(4, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "????????????????????"; int Arg1 = 50; int Arg2 = 49; int Arg3 = 980; verify_case(5, Arg3, getMinimum(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "o??oxxo?xoox?ox??x??" ; int Arg1 = 3; int Arg2 = 10; int Arg3 = 38; verify_case(6, Arg3, getMinimum(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MinCostPalindrome ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

