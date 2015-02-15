#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

typedef signed long long ll;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

//-------------------------------------------------------

class PairGameEasy {
	public:
	set<pair<int,int> > S[2];
	
	string able(int a, int b, int c, int d) {
		S[0].clear();
		S[1].clear();
		
		while(c>0 && d>0) {
			if(a==c && d==b) return "Able to generate";
			if(c<=d) d-=c;
			else c-=d;
		}
		
		return "Not able to generate";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 3; int Arg3 = 5; string Arg4 = "Able to generate"; verify_case(0, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1; string Arg4 = "Not able to generate"; verify_case(1, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 999; string Arg4 = "Not able to generate"; verify_case(2, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(3, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 47; int Arg1 = 58; int Arg2 = 384; int Arg3 = 221; string Arg4 = "Able to generate"; verify_case(4, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 1000; int Arg1 = 1000; int Arg2 = 1000; int Arg3 = 1000; string Arg4 = "Able to generate"; verify_case(5, Arg4, able(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PairGameEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
