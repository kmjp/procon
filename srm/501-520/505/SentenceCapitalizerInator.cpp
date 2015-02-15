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

class SentenceCapitalizerInator {
	public:
	string fixCaps(string paragraph) {
		int fir=1,i;
		FOR(i,paragraph.size()) {
			if(paragraph[i]=='.') fir=1;
			else if(paragraph[i]>='a' && paragraph[i]<='z' && fir) {
				fir=0;
				paragraph[i]+='A'-'a';
			}
		}
		return paragraph;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "hello programmer. welcome to topcoder."; string Arg1 = "Hello programmer. Welcome to topcoder."; verify_case(0, Arg1, fixCaps(Arg0)); }
	void test_case_1() { string Arg0 = "one."; string Arg1 = "One."; verify_case(1, Arg1, fixCaps(Arg0)); }
	void test_case_2() { string Arg0 = "not really. english. qwertyuio. a. xyz."; string Arg1 = "Not really. English. Qwertyuio. A. Xyz."; verify_case(2, Arg1, fixCaps(Arg0)); }
	void test_case_3() { string Arg0 = "example four. the long fourth example. a. b. c. d."; string Arg1 = "Example four. The long fourth example. A. B. C. D."; verify_case(3, Arg1, fixCaps(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SentenceCapitalizerInator ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

