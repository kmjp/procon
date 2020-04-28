#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


long double dp[21][21];

class ProbabilisticAlice {
	public:
	double computeExpectation(vector <string> grid, int pnum, int pden) {
		long double p=1.0*pnum/pden;
		int H=grid.size();
		int W=grid[0].size();
		int y,x;
		
		ZERO(dp);
		dp[0][0]=1;
		FOR(y,H) FOR(x,W) if(grid[y][x]!='T') {
			if(y==H-1 && x==W-1) break;
			if(y==H-1) {
				dp[y][x+1]+=dp[y][x];
			}
			else if(x==W-1) {
				dp[y+1][x]+=dp[y][x];
			}
			else {
				dp[y+1][x]+=dp[y][x]*p;
				dp[y][x+1]+=dp[y][x]*(1-p);
			}
		}
		
		long double A=dp[H-1][W-1], B=1-A;
		if(A==0) return -1;
		if(A==1) return 0;
		return 1/A-1;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.0; verify_case(0, Arg3, computeExpectation(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {".T",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; double Arg3 = 1.0; verify_case(1, Arg3, computeExpectation(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {".T",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; int Arg2 = 47; double Arg3 = 0.021739130434782705; verify_case(2, Arg3, computeExpectation(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {".....T.",
 "....T..",
 "T..T..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; double Arg3 = -1.0; verify_case(3, Arg3, computeExpectation(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"....T.",
 "...TT.",
 ".T....",
 "...T..",
 "......"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 7; double Arg3 = 5.417334860633832; verify_case(4, Arg3, computeExpectation(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ProbabilisticAlice ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

