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

vector<int> E[55];
int dp[55];

class TransformTheTree {
	public:
	int N;
	int P[55];
	int countCuts(vector <int> parents) {
		N=parents.size()+1;
		int i;
		P[0]=-1;
		FOR(i,N) {
			E[i].clear();
		}
		FOR(i,N-1) {
			P[i+1]=parents[i];
			E[parents[i]].push_back(i+1);
		}
		
		int ret=0;
		for(i=N-1;i>=0;i--) {
			dp[i]=0;
			FORR(c,E[i]) if(dp[c]) dp[i]++;
			if(dp[i]<=1) {
				dp[i]=1;
			}
			else {
				ret+=dp[i]-1;
				dp[i]=0;
			}
		}
		
		return ret+dp[0]-1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0, 0, 1, 2, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countCuts(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(1, Arg1, countCuts(Arg0)); }
	void test_case_2() { int Arr0[] = {0, 0, 1, 2, 3, 4, 5, 6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countCuts(Arg0)); }
	void test_case_3() { int Arr0[] = {}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countCuts(Arg0)); }
	void test_case_4() { int Arr0[] = {0, 1, 2, 3, 2, 5, 0, 7, 8, 9, 8, 11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(4, Arg1, countCuts(Arg0)); }
	void test_case_5() { int Arr0[] = {0, 1, 2, 0, 4, 5, 6, 4, 5, 6, 0, 11, 12}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(5, Arg1, countCuts(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TransformTheTree ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

