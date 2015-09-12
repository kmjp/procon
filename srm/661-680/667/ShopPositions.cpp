#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


class ShopPositions {
	int P[32][1000];
	ll dp[33][33][33];
	
	public:
	int maxProfit(int n, int m, vector <int> c) {
		int b,i,x;
		int pre,cur,ne;
		
		ZERO(P);
		FOR(i,n) for(x=1;x<=3*m;x++) P[i][x] = c[i*3*m+x-1];
		
		memset(dp,0xff,sizeof(dp));
		for(i=0;i<=m;i++) dp[0][0][i]=0;
		
		FOR(b,n) {
			FOR(pre,m+1) FOR(cur,m+1) FOR(ne,m+1) dp[b+1][cur][ne] = max(dp[b+1][cur][ne], dp[b][pre][cur]+cur*P[b][pre+cur+ne]);
		}
		ll ma=0;
		FOR(cur,m+1) FOR(ne,m+1) ma=max(ma,dp[n][cur][ne]);
		return ma;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 300; verify_case(0, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 5; int Arr2[] = {1000, 5, 4, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1000; verify_case(1, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 1; int Arr2[] = {
  7,6,1,
  10,4,1,
  7,6,3
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 14; verify_case(2, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arr2[] = {
 12,11,10,9,8,7,
 6,5,4,3,2,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 24; verify_case(3, Arg3, maxProfit(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 3; int Arg1 = 3; int Arr2[] = {
  30,28,25,15,14,10,5,4,2,
  50,40,30,28,17,13,8,6,3,
  45,26,14,14,13,13,2,1,1
}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 127; verify_case(4, Arg3, maxProfit(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ShopPositions ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
