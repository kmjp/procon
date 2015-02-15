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


class AlternateColors2 {
	public:
	long long countWays(int n, int k) {
		ll res=0;
		int r,g,b,gb;
		ll l;
		
		// g‚àh‚à‚ ‚Ü‚é
		if((k%3)==1) {
			r=k/3+1;
			g=k/3;
			b=k/3;
			l = n-k;
			// lŒÂ‚ğr‚Æg‚Æh‚ÅŠ„‚é (l+2)_C_2
			if(l==0) res += 1;
			else res += (l+2)*(l+1)/2;
			//_P("1 %d %lld\n",b,res);
		}
		
		// g‚ª[‘«Ab‚ª•s‘« (‚¨‚æ‚Ñ‚»‚Ì‹t)
		for(b=0;b<k;b++) {
			if((k-b)%2==0) continue;
			r = ((k-b)+1)/2;
			g = ((k-b)-1)/2;
			if(b>=r-1) continue;
			l = n-k;
			// lŒÂ‚ğr‚Æg‚ÅŠ„‚é 2*((l+1)_C_1)
			res += 2*(l+1);
			//_P("2 %d %d %d %lld\n",r,g,b,res);
		}
		
		// g‚àh‚à•s‘«
		for(r=0;r<=k;r++) {
			if(r+(r-1)+(r-1)<k) continue;
			if(k-r<=r-2) {
				//k-rŒÂ‚ğ•ª‚¯‚é
				res += k-r+1;
				//_P("3 %d %lld\n",r,res);
			}
			else {
				// k-rŒÂ‚ğ•ª‚¯‚é‚ªãŒÀ‚Ír-2
				int mx=min(k-r,r-2);
				int mn=k-r-mx;
				if(mx>=mn) res += (mx-mn)+1;
				//_P("4 %d %d %d %lld\n",r,mx,mn,res);
			}
		}
		
		return res;
		
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; long long Arg2 = 1LL; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; long long Arg2 = 3LL; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 6; int Arg1 = 4; long long Arg2 = 9LL; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6; int Arg1 = 1; long long Arg2 = 21LL; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 1000; int Arg1 = 2; long long Arg2 = 1LL; verify_case(4, Arg2, countWays(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 100000; int Arg1 = 100000; long long Arg2 = 1666700000LL; verify_case(5, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(int argc, char** argv) {
  AlternateColors2 ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
// END CUT HERE
