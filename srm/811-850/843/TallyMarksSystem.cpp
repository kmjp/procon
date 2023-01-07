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

int dp[2020202];
vector<int> SP={1008,1057,1086,1092,1134,1250,1524,1661,1716,1757,1764,1806,1827,1836,2265,2871};
class TallyMarksSystem {
	public:
	
	int construct(int N) {
		int i;
		FOR(i,2010101) dp[i]=30;
		dp[0]=0;
		int j;
		for(i=1;i<=N;i++) {
			dp[i]=min(dp[i-1]+1,dp[i]);
			if(i>=5) dp[i]=min(dp[i],dp[i-5]+1);
			for(j=1;j<=min(i-1,1000);j++) dp[i]=min(dp[i],dp[j]+dp[i-j]);
			FORR(j,SP) if(j<i) dp[i]=min(dp[i],dp[j]+dp[i-j]);
			for(j=2;j*i<=2010101&&j<=i;j++) dp[i*j]=min(dp[i*j],dp[i]+dp[j]);
		}
		return dp[N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 3; verify_case(0, Arg1, construct(Arg0)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; verify_case(1, Arg1, construct(Arg0)); }
	void test_case_2() { int Arg0 = 30; int Arg1 = 3; verify_case(2, Arg1, construct(Arg0)); }
	void test_case_3() { int Arg0 = 202; int Arg1 = 7; verify_case(3, Arg1, construct(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TallyMarksSystem ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

