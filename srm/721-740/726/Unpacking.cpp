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

int dp[3][20101];

class Unpacking {
	public:
	int getcost(vector <int> a, vector <int> b, vector <int> cost, int K) {
		int N=a.size();
		int i,j;
		for(i=1;i<=20100;i++) dp[0][i]=dp[1][i]=dp[2][i]=1<<30;
		
		dp[0][0]=dp[1][0]=dp[2][0]=0;
		FOR(i,N) {
			for(j=20000;j>=0;j--) {
				dp[0][min(10000,j+max(0,a[i]-1))]=min(dp[0][min(10000,j+max(0,a[i]-1))],dp[0][j]+cost[i]);
				dp[1][min(10000,j+max(0,b[i]-1))]=min(dp[1][min(10000,j+max(0,b[i]-1))],dp[1][j]+cost[i]);
				dp[2][min(20000,j+a[i]+b[i])]=min(dp[2][min(20000,j+a[i]+b[i])],dp[2][j]+cost[i]);
			}
		}
		
		int mi=1<<30;
		for(i=K;i<=10000;i++) mi=min({mi,dp[0][i],dp[1][i]});
		for(i=2*K-1;i<=20000;i++) mi=min(mi,dp[2][i]);
		if(mi==1<<30) mi=-1;
		return mi;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {6,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 2; verify_case(0, Arg4, getcost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arr0[] = {5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {4,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = -1; verify_case(1, Arg4, getcost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arr0[] = {10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {13}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 9; int Arg4 = 13; verify_case(2, Arg4, getcost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; int Arg4 = 10; verify_case(3, Arg4, getcost(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,15}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 17; int Arg4 = 9; verify_case(4, Arg4, getcost(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Unpacking ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

