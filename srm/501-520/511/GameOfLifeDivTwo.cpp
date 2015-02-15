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

class GameOfLifeDivTwo {
	public:
	string theSimulation(string init, int T) {
		string t;
		int i,x;
		t=init;
		FOR(i,T) {
			FOR(x,init.size()) t[(x+1)%init.size()]='0' + (((init[x]-'0')+(init[(x+1)%init.size()]-'0')+(init[(x+2)%init.size()]-'0'))>=2);
			swap(init,t);
		}
		return init;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01010"; int Arg1 = 2; string Arg2 = "00000"; verify_case(0, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "010101"; int Arg1 = 5; string Arg2 = "101010"; verify_case(1, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "111010"; int Arg1 = 58; string Arg2 = "111111"; verify_case(2, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "111111111"; int Arg1 = 511; string Arg2 = "111111111"; verify_case(3, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "110010000010111110010100001001"; int Arg1 = 1000; string Arg2 = "110000000001111110000000000001"; verify_case(4, Arg2, theSimulation(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "00101110011"; int Arg1 = 0; string Arg2 = "00101110011"; verify_case(5, Arg2, theSimulation(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GameOfLifeDivTwo ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

