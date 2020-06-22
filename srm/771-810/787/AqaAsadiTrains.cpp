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

int tab[100][100];
ll dp[51][51][51];
ll ret[51];

class AqaAsadiTrains {
	public:
	int getMax(vector <int> C, vector <int> A, vector <int> T) {
		int K=C.size();
		int N=A.size();
		
		int x,y,z,i,a,b;
		FOR(x,51) FOR(y,51) FOR(z,51) dp[x][y][z]=-1LL<<60;
		FOR(x,N) dp[x][x+1][A[x]]=0;
		
		FOR(y,K) FOR(x,K) tab[y][x]=T[y*K+x];
		
		for(int len=2;len<=N;len++) {
			for(x=0;x+len<=N;x++) {
				for(y=x+1;y<x+len;y++) {
					FOR(a,K) FOR(b,K) {
						dp[x][x+len][a]=max(dp[x][x+len][a],dp[x][y][a]+dp[y][x+len][b]+C[b]);
						dp[x][x+len][b]=max(dp[x][x+len][b],dp[x][y][a]+dp[y][x+len][b]+C[a]);
						dp[x][x+len][tab[a][b]]=max(dp[x][x+len][tab[a][b]],dp[x][y][a]+dp[y][x+len][b]);
						dp[x][x+len][tab[b][a]]=max(dp[x][x+len][tab[b][a]],dp[x][y][a]+dp[y][x+len][b]);
					}
				}
			}
		}
		
		for(i=1;i<=N;i++) {
			ret[i]=ret[i-1];
			FOR(x,i) FOR(y,K) ret[i]=max(ret[i],ret[x]+dp[x][i][y]+max(0,C[y]));
		}
		return ret[N];
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0_() { int Arr0[] = {3, 0, -5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {2, 0, 0, 2, 1, 1, 1, 2, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_0() { int Arr0[] = {1,10,-1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 0,1,2,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0,0,1,2,1,2,1,1,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(0, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {40, -10, -30, 10, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 2, 3, 2, 0, 3, 1, 3, 4, 2, 4, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(1, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {40, -10, -30, 10, 50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {0, 1, 2, 2, 4, 4, 3, 2, 3, 1, 3, 0, 0, 0, 3, 2, 0, 4, 1, 3, 4, 2, 4, 4, 3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 50; verify_case(2, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {10, -47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 0, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 20; verify_case(3, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {10, -47}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 1, 1, 1, 1, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1, 1, 1, 0}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(4, Arg3, getMax(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {-30, 10, -10, -40, -30}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 1, 3, 1, 3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {4, 4, 1, 2, 1, 2, 1, 0, 3, 0, 2, 0, 0, 0, 4, 1, 3, 3, 2, 0, 0, 0, 2, 0, 2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 30; verify_case(5, Arg3, getMax(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  AqaAsadiTrains ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

