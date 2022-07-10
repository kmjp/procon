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

const ll mo=1000000007;
ll dp[1010][1010][8]; // 1234+ 1234+

class Never3Steps {
	public:
	int count(int X, int Y) {
		ZERO(dp);
		dp[0][0][0]=1;
		dp[1][0][0]=1;
		dp[0][1][4]=1;
		int y,x;
		FOR(y,1005) FOR(x,1005) if(y+x) {
			// up
			(dp[y+1][x][0]+=dp[y][x][4]+dp[y][x][5]+dp[y][x][7])%=mo;
			(dp[y+1][x][1]+=dp[y][x][0])%=mo;
			(dp[y+1][x][2]+=dp[y][x][1])%=mo;
			(dp[y+1][x][3]+=dp[y][x][2]+dp[y][x][3])%=mo;
			//right
			(dp[y][x+1][4]+=dp[y][x][0]+dp[y][x][1]+dp[y][x][3])%=mo;
			(dp[y][x+1][5]+=dp[y][x][4])%=mo;
			(dp[y][x+1][6]+=dp[y][x][5])%=mo;
			(dp[y][x+1][7]+=dp[y][x][6]+dp[y][x][7])%=mo;
		}
		ll ret=0;
		ret+=dp[X][Y][0]+dp[X][Y][1]+dp[X][Y][3]+dp[X][Y][4]+dp[X][Y][5]+dp[X][Y][7];
		return ret%mo;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 6; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 14; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 7; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 2; int Arg2 = 45; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 1; verify_case(4, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Never3Steps ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

