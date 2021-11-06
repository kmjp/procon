#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

double dp[5050][5050];

class PStepsGame {
	public:
	double solve(int N, int P) {
		
		ZERO(dp);
		int i,x,y;
		FOR(x,5050) dp[x][0]=x;
		for(i=1;i<=N;i++) {
			for(x=1;x<=P;x++) {
				dp[i][x]=(dp[i][x-1]+dp[i-1][x-1])/2.0;
			}
		}
		return dp[N][P];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arg1 = 1; double Arg2 = 19.5; verify_case(0, Arg2, solve(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 15; double Arg2 = 3.0517578125E-5; verify_case(1, Arg2, solve(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 5; double Arg2 = 0.21875; verify_case(2, Arg2, solve(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 16; int Arg1 = 18; double Arg2 = 7.0000762939453125; verify_case(3, Arg2, solve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PStepsGame ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

