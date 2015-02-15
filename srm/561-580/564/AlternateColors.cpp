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


class AlternateColors {
	public:
	string getColor(long long r, long long g, long long b, long long k) {
		
		long long m=min(min(r,g),b);
		
		if(k<=3*m) {
			if(k%3==1) return string("RED");
			if(k%3==2) return string("GREEN");
			if(k%3==0) return string("BLUE");
		}
		k-=3*m;
		r-=m;
		g-=m;
		b-=m;
		
		if(b==0) {
			if(k<=2*min(r,g)) return string((k%2)?"RED":"GREEN");
			return string((r>=g)?"RED":"GREEN");
		}
		if(g==0) {
			if(k<=2*min(r,b)) return string((k%2)?"RED":"BLUE");
			return string((r>=b)?"RED":"BLUE");
		}
		if(r==0) {
			if(k<=2*min(g,b)) return string((k%2)?"GREEN":"BLUE");
			return string((g>=b)?"GREEN":"BLUE");
		}
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 3LL; string Arg4 = "BLUE"; verify_case(0, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; long long Arg2 = 5LL; long long Arg3 = 4LL; string Arg4 = "RED"; verify_case(1, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 7LL; long long Arg1 = 7LL; long long Arg2 = 1LL; long long Arg3 = 7LL; string Arg4 = "GREEN"; verify_case(2, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1000000000000LL; long long Arg1 = 1LL; long long Arg2 = 1LL; long long Arg3 = 1000000000002LL; string Arg4 = "RED"; verify_case(3, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { long long Arg0 = 653LL; long long Arg1 = 32LL; long long Arg2 = 1230LL; long long Arg3 = 556LL; string Arg4 = "BLUE"; verify_case(4, Arg4, getColor(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  AlternateColors ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
