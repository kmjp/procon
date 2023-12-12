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

int C[26][26][26];
ll dp[1<<16];
class BusTravel {
	public:
	int optimize(int N, int S, int M, int A) {
		int x,y,z;
		FOR(x,N) FOR(y,N) FOR(z,N) C[x][y][z]=1LL*(x+1)*(y+4)*(y+z+A)%M+1;
		int mask;
		FOR(mask,1<<N) dp[mask]=1LL<<60;
		dp[(1<<N)-1]=0;
		ll mi=1LL<<60;
		for(mask=(1<<N)-1;mask>=0;mask--) {
			int b=__builtin_popcount(mask);
			if(b<=S) {
				mi=min(mi,dp[mask]);
			}
			else {
				int bid=N-b;
				FOR(x,N) if(mask&(1<<x)) {
					FOR(y,N) if((mask&(1<<y))&&x!=y) {
						dp[mask^(1<<x)]=min(dp[mask^(1<<x)],dp[mask]+C[bid][x][y]);
					}
				}
			}
		}
		return mi;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 47; int Arg3 = 7; int Arg4 = 0; verify_case(0, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 47; int Arg3 = 7; int Arg4 = 4; verify_case(1, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 2; int Arg2 = 47; int Arg3 = 7; int Arg4 = 8; verify_case(2, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 47; int Arg3 = 7; int Arg4 = 25; verify_case(3, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 1; int Arg2 = 47; int Arg3 = 17; int Arg4 = 30; verify_case(4, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 14; int Arg1 = 4; int Arg2 = 1; int Arg3 = 0; int Arg4 = 10; verify_case(5, Arg4, optimize(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BusTravel ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

