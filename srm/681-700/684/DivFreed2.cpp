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

ll dp[2][150505];
ll* from=dp[0];
ll* to=dp[1];
ll mo=1000000007;
class DivFreed2 {
	public:
	int count(int n, int k) {
		int i,j;
		
		for(i=1;i<=k;i++) from[i]=1;
		n--;
		while(n--) {
			ll tot=accumulate(from,from+k+1,0LL)%mo;
			
			for(i=1;i<=k;i++) {
				to[i]=tot;
				for(j=i*2;j<=k;j+=i) to[i]+=mo-from[j];
				to[i]%=mo;
			}
			
			swap(from,to);
		}
		
		return accumulate(from,from+k+1,0LL)%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 3; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; int Arg2 = 1; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 15; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 107; int Arg2 = 107; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 2; int Arg1 = 10; int Arg2 = 83; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 2; int Arg1 = 1234; int Arg2 = 1515011; verify_case(5, Arg2, count(Arg0, Arg1)); }
	void test_case_6() { int Arg0 = 3; int Arg1 = 8; int Arg2 = 326; verify_case(6, Arg2, count(Arg0, Arg1)); }
	void test_case_7() { int Arg0 = 10; int Arg1 = 100000; int Arg2 = 526882214; verify_case(7, Arg2, count(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DivFreed2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
