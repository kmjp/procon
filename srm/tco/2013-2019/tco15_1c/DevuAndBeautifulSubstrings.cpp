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

ll dp[2][2500][51];

class DevuAndBeautifulSubstrings {
	public:
	long long countBeautifulSubstrings(int n, int cnt) {
		int i,x,y;
		ZERO(dp);
		dp[0][0][0]=1;
		FOR(i,n) {
			int cur=i%2,tar=cur^1;
			ZERO(dp[tar]);
			FOR(x,1300) FOR(y,51) if(dp[cur][x][y]) {
				dp[tar][x+y+1][y+1] += dp[cur][x][y];
				dp[tar][x+1][1] += dp[cur][x][y];
			}
		}
		ll ret=0;
		FOR(x,51) ret += dp[n%2][cnt][x];
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; long long Arg2 = 2LL; verify_case(0, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 1; long long Arg2 = 0LL; verify_case(1, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; long long Arg2 = 4LL; verify_case(2, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 35; long long Arg2 = 642LL; verify_case(3, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 40; int Arg1 = 820; long long Arg2 = 2LL; verify_case(4, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 94; long long Arg2 = 32357325751902LL; verify_case(5, Arg2, countBeautifulSubstrings(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DevuAndBeautifulSubstrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
