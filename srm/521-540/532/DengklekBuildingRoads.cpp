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

ll mo=1000000007;
ll dpdp[31][31][1<<8];
ll dp1[9][31][1<<8];

class DengklekBuildingRoads {
	public:
	
	int numWays(int N, int M, int K) {
		int i,x,y,mask,mask2;
		
		ZERO(dp1);
		dp1[0][0][0]=1;
		FOR(i,K) {
			FOR(x,31) FOR(y,31) if(x+y<=M) {
				FOR(mask,1<<K) {
					dp1[i+1][x+y][mask ^ ((y%2)<<i)] += dp1[i][x][mask];
					dp1[i+1][x+y][mask ^ ((y%2)<<i)] %= mo;
				}
			}
		}
		
		ZERO(dpdp);
		dpdp[0][M][0]=1;
		
		FOR(i,N) {
			int l = min(K,N-i-1);
			FOR(mask,1<<K) FOR(y,M+1) if((mask%2)==(y%2)) {
				for(x=y;x<=M;x++) if(dpdp[i][x][mask]) {
					FOR(mask2,1<<l) if(dp1[l][y][mask2]) {
						dpdp[i+1][x-y][mask2 ^ (mask>>1)] += dpdp[i][x][mask] * dp1[l][y][mask2];
						dpdp[i+1][x-y][mask2 ^ (mask>>1)] %= mo;
					}
				}
			}
		}
		
		return dpdp[N][0][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 3; verify_case(0, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 3; int Arg3 = 4; verify_case(1, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; verify_case(2, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 0; int Arg2 = 3; int Arg3 = 1; verify_case(3, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_42() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 5; int Arg3 = 26964424; verify_case(4, Arg3, numWays(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 30; int Arg1 = 30; int Arg2 = 8; int Arg3 = 26964424; verify_case(4, Arg3, numWays(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DengklekBuildingRoads ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}
