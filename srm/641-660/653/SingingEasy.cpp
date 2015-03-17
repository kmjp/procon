#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll dp[2020][2020];

class SingingEasy {
	public:
	int solve(vector <int> pitch) {
		int N=pitch.size(),x,y;
		FOR(x,N+3) FOR(y,N+3) dp[x][y]=1LL<<60;
		
		dp[1][0]=0;
		for(x=2;x<=N;x++) {
			for(y=0;y<=x-2;y++) {
				dp[y][x]=min(dp[y][x],dp[y][x-1]+((x-2>=0)?abs(pitch[x-1]-pitch[x-2]):0));
				dp[x][y]=min(dp[x][y],dp[x-1][y]+((x-2>=0)?abs(pitch[x-1]-pitch[x-2]):0));
				dp[x][x-1]=min(dp[x][x-1],dp[y][x-1]+((y>0)?abs(pitch[x-1]-pitch[y-1]):0));
				dp[x-1][x]=min(dp[x-1][x],dp[x-1][y]+((y>0)?abs(pitch[x-1]-pitch[y-1]):0));
			}
		}
		
		ll mi=1LL<<60;
		for(y=0;y<=N-1;y++) mi=min(mi,dp[y][N]);
		for(y=0;y<=N-1;y++) mi=min(mi,dp[N][y]);
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,8,12,13}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {1,5,6,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {5,5,5,5,4,4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {24,13,2,4,54,23,12,53,12,23,42,13,53,12,24,12,11,24,42,52,12,32,42}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 188; verify_case(4, Arg1, solve(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SingingEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
