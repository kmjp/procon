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

class PikachuEasy {
	public:
	string check(string word) {
		int i=0;
		while(i<word.size()) {
			int oi=i;
			if(i+2<=word.size() && word[i]=='p' && word[i+1]=='i') i+=2;
			if(i+2<=word.size() && word[i]=='k' && word[i+1]=='a') i+=2;
			if(i+3<=word.size() && word[i]=='c' && word[i+1]=='h' && word[i+2]=='u') i+=3;
			if(oi==i) return "NO";
		}
		return "YES";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "pikapi"; string Arg1 = "YES"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "pipikachu"; string Arg1 = "YES"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "pikaqiu"; string Arg1 = "NO"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "NO"; verify_case(3, Arg1, check(Arg0)); }
	void test_case_4() { string Arg0 = "piika"; string Arg1 = "NO"; verify_case(4, Arg1, check(Arg0)); }
	void test_case_5() { string Arg0 = "chupikachupipichu"; string Arg1 = "YES"; verify_case(5, Arg1, check(Arg0)); }
	void test_case_6() { string Arg0 = "pikapipachu"; string Arg1 = "NO"; verify_case(6, Arg1, check(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PikachuEasy ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

