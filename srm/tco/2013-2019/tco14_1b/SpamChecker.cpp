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

class SpamChecker {
	public:
	string spamCheck(string judgeLog, int good, int bad) {
		int sc=0;
		ITR(it,judgeLog) {
			if(*it=='o') sc+=good;
			else sc-=bad;
			if(sc<0) return "SPAM";
		}
		return "NOT SPAM";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ooooxxxo"; int Arg1 = 2; int Arg2 = 3; string Arg3 = "SPAM"; verify_case(0, Arg3, spamCheck(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "ooooxxxo"; int Arg1 = 3; int Arg2 = 4; string Arg3 = "NOT SPAM"; verify_case(1, Arg3, spamCheck(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "xooooooooooooooooooooooooooo"; int Arg1 = 1000; int Arg2 = 1; string Arg3 = "SPAM"; verify_case(2, Arg3, spamCheck(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "oxxxxxxxxxxxxxxxxxxxxxxxxxxxx"; int Arg1 = 1000; int Arg2 = 1; string Arg3 = "NOT SPAM"; verify_case(3, Arg3, spamCheck(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "ooxoxoxooxoxxoxoxooxoxoxoxxoxx"; int Arg1 = 15; int Arg2 = 17; string Arg3 = "SPAM"; verify_case(4, Arg3, spamCheck(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "oooxoxoxoxoxoxooxooxoxooxo"; int Arg1 = 16; int Arg2 = 18; string Arg3 = "NOT SPAM"; verify_case(5, Arg3, spamCheck(Arg0, Arg1, Arg2)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SpamChecker ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

