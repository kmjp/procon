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

class RotatedClock {
	public:
	string getEarliest(int hourHand, int minuteHand) {
		int i,s=1000;
		FOR(i,12) {
			int hh=(hourHand+i*30)%360;
			int mh=(minuteHand+i*30)%360;
			
			if(hh%30*12==mh) s=min(s,hh*2);
		}
		if(s==1000) return "";
		char tmp[10];
		sprintf(tmp,"%02d:%02d",s/60,s%60);
		return tmp;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 70; int Arg1 = 300; string Arg2 = "08:20"; verify_case(0, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 90; int Arg1 = 120; string Arg2 = "11:00"; verify_case(1, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 240; int Arg1 = 36; string Arg2 = ""; verify_case(2, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 19; int Arg1 = 19; string Arg2 = ""; verify_case(3, Arg2, getEarliest(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 12; string Arg2 = "00:02"; verify_case(4, Arg2, getEarliest(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RotatedClock ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

