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

class LimitedMemorySeries2 {
	public:
	ll A,B;
	ll nex(ll v) { return ((v^A)+B) & ((1LL<<50)-1); }
	ll pre(ll v) { return  ((v+(1LL<<50)-B)^A) & ((1LL<<50)-1); }
	
	int getSum(int n, long long x0, long long a, long long b) {
		int i,j;
		A=a;
		B=b;
		
		ll ret=0;
		ll y=x0;
		FOR(i,n) {
			ll x=pre(y);
			ll z=nex(y);
			for(j=1;i-j>=0 && i+j<n;j++) {
				if(x>=y || z>=y) break;
				x=pre(x);
				z=nex(z);
			}
			ret += j-1;
			y=nex(y);
		}
		
		return ret%1000000007;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 6; long long Arg1 = 2LL; long long Arg2 = 23LL; long long Arg3 = 1LL; int Arg4 = 2; verify_case(0, Arg4, getSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 100; long long Arg1 = 0LL; long long Arg2 = 0LL; long long Arg3 = 1LL; int Arg4 = 0; verify_case(1, Arg4, getSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 234234; long long Arg1 = 1125899906842623LL; long long Arg2 = 123456789123456LL; long long Arg3 = 987654321549687LL; int Arg4 = 1144970; verify_case(2, Arg4, getSum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10000000; long long Arg1 = 12345678912345LL; long long Arg2 = 98765094309812LL; long long Arg3 = 34893049812392LL; int Arg4 = 65420804; verify_case(3, Arg4, getSum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LimitedMemorySeries2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
