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

int S[505];
ll dp[501][501];
class AqaAsadiGroups {
	public:
	long long minimumDifference(vector <int> Skills, int k) {
		int N=Skills.size();
		int x,y,z,i;
		FOR(i,N) S[i+1]=S[i]+Skills[i];
		int sum=S[N];
		FOR(x,501) FOR(y,501) dp[x][y]=1LL<<60;
		dp[0][0]=0;
		FOR(x,k) {
			FOR(y,N+1) {
				for(z=y;z<=N;z++) dp[x+1][z]=min(dp[x+1][z],dp[x][y]+1LL*(sum-(S[z]-S[y])*k)*(sum-(S[z]-S[y])*k));
			}
		}
		
		return dp[k][N];
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 2LL; verify_case(0, Arg2, minimumDifference(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; long long Arg2 = 0LL; verify_case(1, Arg2, minimumDifference(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 3, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; long long Arg2 = 8LL; verify_case(2, Arg2, minimumDifference(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 80LL; verify_case(3, Arg2, minimumDifference(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AqaAsadiGroups ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

