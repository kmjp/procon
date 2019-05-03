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

int dp[51][16][1<<15];

class EllysPearls {
	public:
	int getMin(int N, int M, vector <int> P) {
		int i,j,mask,x,y;
		FORR(p,P) p--;
		
		memset(dp,0x3c,sizeof(dp));
		FOR(i,M) dp[0][i][1<<i]=0;
		FOR(i,N) {
			FOR(j,M) FOR(mask,1<<M) if(dp[i][j][mask]<1<<20) {
				FOR(x,M) {
					if(j!=x && (mask&(1<<x))) continue;
					dp[i+1][x][mask|(1<<x)]=min(dp[i+1][x][mask|(1<<x)],dp[i][j][mask]+(P[i]!=x));
				}
			}
		}
		
		int mi=1<<20;
		FOR(j,M) FOR(mask,1<<M) mi=min(mi,dp[N][j][mask]);
		return mi;
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 11; int Arg1 = 4; int Arr2[] = {2, 4, 1, 1, 1, 3, 2, 1, 4, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 3; verify_case(0, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 1; int Arr2[] = {1, 1, 1, 1, 1}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 0; verify_case(1, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 2; int Arr2[] = {2, 2, 2, 1, 2, 2, 2, 1, 1, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(2, Arg3, getMin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 30; int Arg1 = 7; int Arr2[] = {5, 6, 2, 4, 7, 2, 2, 3, 3, 6, 1, 3, 6, 3, 7, 5, 1, 2, 3, 4, 6, 5, 6, 3, 2, 5, 3, 3, 5, 6}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 16; verify_case(3, Arg3, getMin(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysPearls ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

