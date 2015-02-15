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


class FixedDiceGameDiv1 {
	public:
	double dp[2][2602];
	double getExpectation(int a, int b, int c, int d) {
		int x,y,z,i;
		if(a*b<=c) return -1.0f;
		ZERO(dp);
		
		dp[0][0]=dp[1][0]=1;
		FOR(x,a) {
			for(y=a*b;y>=0;y--) if(dp[0][y]) {
				FOR(z,b) dp[0][y+z+1]+=dp[0][y]/(double)(b);
				dp[0][y]=0;
			}
		}
		FOR(x,c) {
			for(y=c*d;y>=0;y--) if(dp[1][y]) {
				FOR(z,d) dp[1][y+z+1]+=dp[1][y]/(double)(d);
				dp[1][y]=0;
			}
		}
		
		double ret=0,ho=0;
		FOR(i,2501) {
			double tt=0;
			FOR(x,i) tt+=dp[1][x];
			ret+=i*dp[0][i]*tt;
			ho+=dp[0][i]*tt;
		}
		if(ho==0) return -1.0f;
		return ret/ho;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; int Arg2 = 1; int Arg3 = 5; double Arg4 = 2.0; verify_case(0, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 1; int Arg3 = 3; double Arg4 = 3.0; verify_case(1, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; double Arg4 = 3.4999999999999996; verify_case(2, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 6; int Arg2 = 50; int Arg3 = 30; double Arg4 = -1.0; verify_case(3, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	//void test_case_4() { int Arg0 = 50; int Arg1 = 11; int Arg2 = 50; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 25; int Arg1 = 2; int Arg2 = 49; int Arg3 = 50; double Arg4 = 369.8865999182022; verify_case(4, Arg4, getExpectation(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
// BEGIN CUT HERE 
int main(int argc,char** argv) {
  FixedDiceGameDiv1 ___test;
  if(argc==1)  ___test.run_test(-1);
  else  ___test.run_test(atoi(argv[1]));
}
