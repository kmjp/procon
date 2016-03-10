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

ll dp[22][50505];
ll ok[50505],fail[50505];
ll bad[22];
ll mo=1000000007;

class DivFree {
	public:
	int dfcount(int N, int K) {
		int i,j,x;
		
		ZERO(dp);
		ZERO(bad);
		for(i=1;i<=K;i++) dp[0][i]=1;
		for(i=1;i<=20;i++) {
			for(j=1;j<=K;j++) {
				for(x=j*2;x<=K;x+=j) (dp[i][j] += dp[i-1][x])%=mo;
				bad[i]+=dp[i][j];
			}
			bad[i]%=mo;
		}
		
		ll kp=1;
		ok[0]=1;
		for(i=1;i<=N;i++) {
			ok[i]=kp=kp*K%mo;
			fail[i]=fail[i-1]*K%mo;
			
			int mi=1;
			for(j=1;j<=min(20,i-1);j++) {
				fail[i]+=mi*bad[j]*ok[i-j-1];
				mi=-mi;
			}
			fail[i]=(fail[i]%mo+mo)%mo;
			ok[i]=(ok[i]+mo-fail[i])%mo;
		}
		
		return ok[N];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 2; int Arg2 = 4; verify_case(1, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 15; verify_case(2, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 107; int Arg2 = 107; verify_case(3, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 6; int Arg2 = 2292; verify_case(4, Arg2, dfcount(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 42; int Arg1 = 23; int Arg2 = 301026516; verify_case(5, Arg2, dfcount(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DivFree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
