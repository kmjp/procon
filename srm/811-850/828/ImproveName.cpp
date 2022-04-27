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

ll mo=1000000007;
ll dp[2][26][3030];

class ImproveName {
	public:
	int improve(string name, int K) {
		int N=name.size();
		
		ZERO(dp);
		dp[0][0][0]=1;
		
		int i,j,x,y;
		FOR(i,N) {
			name[i]-='A';
			for(j=N-1;j>=0;j--) FOR(x,2) FOR(y,26) if(dp[x][y][j]) {
				if(name[i]<y) (dp[1][y][j+1]+=dp[x][y][j])%=mo;
				else (dp[x][max(y,(int)name[i])][j+1]+=dp[x][y][j])%=mo;
			}
		}
		
		ll ret=0;
		FOR(x,26) ret+=dp[1][x][K];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ABCDE"; int Arg1 = 2; int Arg2 = 0; verify_case(0, Arg2, improve(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AABCCDEEEFZ"; int Arg1 = 3; int Arg2 = 0; verify_case(1, Arg2, improve(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "EEDDCCBBAA"; int Arg1 = 3; int Arg2 = 120; verify_case(2, Arg2, improve(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "TOPCODER"; int Arg1 = 8; int Arg2 = 1; verify_case(3, Arg2, improve(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "TOPCODER"; int Arg1 = 3; int Arg2 = 49; verify_case(4, Arg2, improve(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ImproveName ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

