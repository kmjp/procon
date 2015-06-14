#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll dp[101][101][101];
ll mo=1000000007;

class ColorfulLineGraphsDiv2 {
	public:
	int countWays(int N, int K) {
		int i,x,y;
		ZERO(dp);
		
		if(K==1) return 1;
		else if(K==2) {
			dp[0][1][0]=1;
			dp[0][0][1]=1;
			for(i=1;i<N;i++) {
				FOR(x,i+1) FOR(y,i+1) if(dp[i-1][x][y]) {
					(dp[i][x+1][y] += dp[i-1][x][y]*(y+1))%=mo;
					(dp[i][x][y+1] += dp[i-1][x][y]*(x+1))%=mo;
				}
			}
		}
		else if(K==3) {
			dp[0][1][0]=1;
			dp[0][0][1]=1;
			dp[0][0][0]=1;
			for(i=1;i<N;i++) {
				FOR(x,i+1) FOR(y,i+1) if(dp[i-1][x][y]) {
					int z=i-x-y;
					(dp[i][x+1][y] += dp[i-1][x][y]*(y+z+1))%=mo;
					(dp[i][x][y+1] += dp[i-1][x][y]*(x+z+1))%=mo;
					(dp[i][x][y] += dp[i-1][x][y]*(x+y+1))%=mo;
				}
			}
		}
		
		ll ret=0;
		FOR(x,N+1) FOR(y,N+1) ret+=dp[N-1][x][y];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 24; verify_case(0, Arg2, countWays(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 15; int Arg1 = 2; int Arg2 = 789741546; verify_case(1, Arg2, countWays(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 100; int Arg1 = 1; int Arg2 = 1; verify_case(2, Arg2, countWays(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 3; verify_case(3, Arg2, countWays(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 100; int Arg1 = 3; int Arg2 = 492594064; verify_case(4, Arg2, countWays(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ColorfulLineGraphsDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
