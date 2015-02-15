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

ll mo=1000000007;
ll dp[102][256][256];

class DengklekPaintingSquares {
	public:
	int numSolutions(int H, int W) {
		int y,mask,par,x,nmask;
		ZERO(dp);
		dp[0][0][0]=1;
		FOR(y,H) {
			FOR(mask,1<<W) FOR(par,mask+1)  {
				if((mask|par)!=mask) continue;
				if(dp[y][mask][par]==0) continue;
				FOR(nmask,1<<W) {
					if(mask & (nmask^par)) continue;
					int np=0;
					FOR(x,W) {
						if(!(nmask&(1<<x))) continue;
						int b=!!(mask&(1<<x));
						if(x>0) b^=!!(nmask & (1<<(x-1)));
						if(x<W-1) b^=!!(nmask & (1<<(x+1)));
						np |= b<<x;
					}
					dp[y+1][nmask][np] = (dp[y+1][nmask][np] + dp[y][mask][par])%mo;
				}
			}
		}
		
		ll ret=0;
		FOR(mask,1<<W) ret += dp[H][mask][0];
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 8; verify_case(1, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; verify_case(2, Arg2, numSolutions(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 47; int Arg1 = 7; int Arg2 = 944149920; verify_case(3, Arg2, numSolutions(Arg0, Arg1)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DengklekPaintingSquares ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}

