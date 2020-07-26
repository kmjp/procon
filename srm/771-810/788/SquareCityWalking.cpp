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

int dp[25][25];

class SquareCityWalking {
	public:
	int largestGCD(int N, vector <int> A) {
		for(int v=100;v>=1;v--) {
			ZERO(dp);
			dp[0][0]=1;
			int y,x;
			FOR(y,N) FOR(x,N) {
				if(A[y*N+x]%v) dp[y][x]=0;
				if(dp[y][x]) {
					if(x+1<N) dp[y][x+1]=1;
					if(y+1<N) dp[y+1][x]=1;
				}
			}
			if(dp[N-1][N-1]) return v;
		}
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arr1[] = { 96, 42, 45,
  32, 36, 27,
  40, 54, 84 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; verify_case(0, Arg2, largestGCD(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; int Arr1[] = { 4, 9, 2,
  3, 5, 7,
  8, 1, 6 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; verify_case(1, Arg2, largestGCD(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 4; int Arr1[] = { 54, 81, 27, 36,
  48, 64, 96, 72,
  84, 60, 45, 99,
  80, 90, 40, 63 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, largestGCD(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arr1[] = { 47 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 47; verify_case(3, Arg2, largestGCD(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 5; int Arr1[] = { 100,  80,  64,  48,  36,
   75,  10,  10,  10,  48,
   50,  10,  10,  10,  64,
   25,  10,  10,  10,  80,
    5,  25,  50,  75, 100 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(4, Arg2, largestGCD(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SquareCityWalking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

