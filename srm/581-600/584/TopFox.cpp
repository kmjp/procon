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


class TopFox {
	public:
	set<string> S;
	int possibleHandles(string familyName, string givenName) {
		int i,j;
		S.clear();
		FOR(i,familyName.size()) FOR(j,givenName.size()) S.insert(familyName.substr(0,i+1)+givenName.substr(0,j+1));
		return S.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "cd"; int Arg2 = 4; verify_case(0, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abb"; string Arg1 = "bbc"; int Arg2 = 7; verify_case(1, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "fox"; string Arg1 = "ciel"; int Arg2 = 12; verify_case(2, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbbb"; string Arg1 = "bbbbbbbc"; int Arg2 = 16; verify_case(3, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "abxy"; string Arg1 = "xyxyxc"; int Arg2 = 21; verify_case(4, Arg2, possibleHandles(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "ababababab"; string Arg1 = "bababababa"; int Arg2 = 68; verify_case(5, Arg2, possibleHandles(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  TopFox ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
