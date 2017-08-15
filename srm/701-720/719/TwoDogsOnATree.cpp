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

class TwoDogsOnATree {
	public:
	
	int maximalXorSum(vector <int> parent, vector <int> w) {
		int N=parent.size()+1;
		int V[1010]={};
		int i,j,x,y;
		int dp[5][1024]={};
		dp[0][0]=dp[1][0]=dp[2][0]=dp[3][0]=dp[4][0]=1;
		for(i=1;i<N;i++) {
			V[i]=V[parent[i-1]]^w[i-1];
			FOR(x,4) FOR(j,1024) if(dp[x][j]) dp[x+1][j^V[i]] |= 1;
		}
		
		for(i=1023;i>=0;i--) if(dp[4][i]) return i;
		return -1;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 4, 8}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(0, Arg2, maximalXorSum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {0, 1, 2, 3, 4, 5, 6, 7, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2, 6, 5, 8, 1, 3, 4, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 15; verify_case(1, Arg2, maximalXorSum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {0, 0, 2, 2, 4, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 16, 12, 11, 3, 1, 4, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 31; verify_case(2, Arg2, maximalXorSum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {0, 0, 2, 0, 1, 2, 2, 4, 6, 1, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {628, 589, 815, 864, 459, 507, 733, 239, 904, 592, 818}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1017; verify_case(3, Arg2, maximalXorSum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(4, Arg2, maximalXorSum(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TwoDogsOnATree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

