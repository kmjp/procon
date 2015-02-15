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


class InsertZ {
	public:
	string canTransform(string init, string goal) {
		int i;
		string a;
		FOR(i,goal.size()) if(goal[i]!='z') a+=goal[i];
		return (a==init)?"Yes":"No";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "fox"; string Arg1 = "fozx"; string Arg2 = "Yes"; verify_case(0, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "fox"; string Arg1 = "zfzoxzz"; string Arg2 = "Yes"; verify_case(1, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "foon"; string Arg1 = "foon"; string Arg2 = "Yes"; verify_case(2, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "zopzoder"; string Arg2 = "No"; verify_case(3, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaaaaaaa"; string Arg1 = "a"; string Arg2 = "No"; verify_case(4, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "mvixrdnrpxowkasufnvxaq"; string Arg1 = "mvizzxzzzrdzznzrpxozzwzzkazzzszzuzzfnvxzzzazzq"; string Arg2 = "Yes"; verify_case(5, Arg2, canTransform(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "opdlfmvuicjsierjowdvnx"; string Arg1 = "zzopzdlfmvzuicjzzsizzeijzowvznxzz"; string Arg2 = "No"; verify_case(6, Arg2, canTransform(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  InsertZ ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
