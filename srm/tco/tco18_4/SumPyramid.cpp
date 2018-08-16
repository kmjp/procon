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

int C[1010][1010];
ll dp[1010][1010];
ll mo=1000000007;

class SumPyramid {
	public:
	int countPyramids(int levels, int top) {
		int i,j;
		
		C[1][1]=1;
		for(i=2;i<=1000;i++) {
			for(j=1;j<=i;j++) C[i][j]=min(1010,C[i-1][j]+C[i-1][j-1]);
		}
		
		ZERO(dp);
		dp[0][top]=1;
		for(i=1;i<=levels;i++) {
			for(int x=top;x>=0;x--) {
				dp[i][x]=dp[i-1][x];
				if(x+C[levels][i]<=top) (dp[i][x]+=dp[i][x+C[levels][i]])%=mo;
			}
		}
		return dp[levels][0];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 47; int Arg2 = 1; verify_case(0, Arg2, countPyramids(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 11; verify_case(1, Arg2, countPyramids(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(2, Arg2, countPyramids(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 7; int Arg2 = 18; verify_case(3, Arg2, countPyramids(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SumPyramid ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

