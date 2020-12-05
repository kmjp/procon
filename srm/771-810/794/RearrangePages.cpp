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

class RearrangePages {
	public:
	long long countSwaps(int N, int A, int B) {
		vector<int> V(N);
		int i;
		FOR(i,N/2) V[(A+1LL*i*B)%N]=1;
		ll C=0;
		int cnt=0;
		FOR(i,N) if(V[i]) {
			C+=abs(i-(cnt*2+1));
			cnt++;
		}
		return C;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; int Arg1 = 1; int Arg2 = 1; long long Arg3 = 3LL; verify_case(0, Arg3, countSwaps(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 0; int Arg2 = 3; long long Arg3 = 5LL; verify_case(1, Arg3, countSwaps(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 5; int Arg2 = 1; long long Arg3 = 10LL; verify_case(2, Arg3, countSwaps(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1234; int Arg1 = 7; int Arg2 = 13; long long Arg3 = 13654LL; verify_case(3, Arg3, countSwaps(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RearrangePages ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

