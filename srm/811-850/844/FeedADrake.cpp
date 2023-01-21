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

ll dp[10101][105];

class FeedADrake {
	public:
	int feed(int stomach, vector <int> cakes, int excess) {
		
		int x,y;
		ZERO(dp);
		FORR(c,cakes) {
			
			for(x=stomach-1;x>=0;x--) {
				for(y=excess+1;y>=0;y--) {
					chmax(dp[x][y+1],dp[x][y]+c);
					if(x+c<stomach) chmax(dp[x+c][y],dp[x][y]+c);
				}
			}
		}
		ll ma=0;
		FOR(x,stomach) FOR(y,excess+2) ma=max(ma,dp[x][y]);
		return ma;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1234; int Arr1[] = {10, 20, 30, 40}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; verify_case(0, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 100; int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 100; verify_case(1, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 101; int Arr1[] = {100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 200; verify_case(2, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 101; int Arr1[] = {100, 100, 100, 100, 100}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 400; verify_case(3, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 4700; int Arr1[] = {1000, 8000, 2000, 5000, 3000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 12000; verify_case(4, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 100; int Arr1[] = {100001, 100002, 100003}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 200005; verify_case(5, Arg3, feed(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 100; int Arr1[] = {1000, 2000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 7; int Arg3 = 3000; verify_case(6, Arg3, feed(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FeedADrake ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

