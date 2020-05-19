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


vector<ll> A;
class SwapTheString {
	public:
	long long findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K) {
		A.clear();
		A.push_back(A0);
		int i,j,x;
		for(i=1;i<N;i++) A.push_back((A.back()*X+Y)%1812447359);
		for(i=P.size();i<N;i++) P.push_back(A[i]%26+'a');
		ll ret=0;
		FOR(i,K) {
			string T;
			int C[26]={};
			for(j=i;j<N;j+=K) {
				
				FOR(x,P[j]-'a') ret+=C[x];
				C[P[j]-'a']++;
			}
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cbexa"; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 5; int Arg5 = 2; long long Arg6 = 2LL; verify_case(0, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_1() { string Arg0 = ""; int Arg1 = 5; int Arg2 = 2; int Arg3 = 3; int Arg4 = 4; int Arg5 = 1; long long Arg6 = 3LL; verify_case(1, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_2() { string Arg0 = "b"; int Arg1 = 1001; int Arg2 = 1001; int Arg3 = 1001; int Arg4 = 5; int Arg5 = 2; long long Arg6 = 3LL; verify_case(2, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_3() { string Arg0 = ""; int Arg1 = 9999; int Arg2 = 50000; int Arg3 = 4797; int Arg4 = 6; int Arg5 = 3; long long Arg6 = 2LL; verify_case(3, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }
	void test_case_4() { string Arg0 = ""; int Arg1 = 3435; int Arg2 = 1000000000; int Arg3 = 1812447358; int Arg4 = 7; int Arg5 = 2; long long Arg6 = 5LL; verify_case(4, Arg6, findNumberOfSwaps(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SwapTheString ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

