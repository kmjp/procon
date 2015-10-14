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

ll mo=1000000007;

ll dp[204][102][103];

class BearCries {
	public:
	int count(string M) {
		int L=M.size(),i,x,y,z;
		ZERO(dp);
		
		dp[0][0][0]=1;
		FOR(i,L) {
			for(x=0;x<101;x++) FOR(y,101) if(dp[i][y][x]) {
				ll d=dp[i][y][x];
				if(M[i]=='_') {
					if(y) (dp[i+1][y-1][x+1] += d*y)%=mo;
					if(x) (dp[i+1][y][x] += d*x)%=mo;
				}
				else {
					if(x) (dp[i+1][y][x-1] += d*x)%=mo;
					(dp[i+1][y+1][x] += d)%=mo;
				}
			}
		}
		return dp[L][0][0];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = ";_;;_____;"; int Arg1 = 2; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arg0 = ";;;___;;;"; int Arg1 = 36; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arg0 = "_;__;"; int Arg1 = 0; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arg0 = ";_____________________________________;"; int Arg1 = 1; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arg0 = ";__;____;"; int Arg1 = 0; verify_case(4, Arg1, count(Arg0)); }
	void test_case_5() { string Arg0 = ";_;;__;_;;"; int Arg1 = 52; verify_case(5, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearCries ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
