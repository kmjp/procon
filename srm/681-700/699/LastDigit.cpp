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

class LastDigit {
	public:
	long long findX(long long S) {
		ll p10[20];
		int i,j;
		p10[0]=1;
		FOR(i,19) p10[i+1]=p10[i]*10;
		
		ll ret=0;
		for(i=17;i>=0;i--) {
			for(j=9;j>0;j--) {
				ll t=(p10[i+1]-1)/9*j;
				if(S>=t) {
					S -= t;
					ret += j*p10[i];
					break;
				}
			}
		}
		
		if(S) return -1;
		return ret;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 564LL; long long Arg1 = 509LL; verify_case(0, Arg1, findX(Arg0)); }
	void test_case_1() { long long Arg0 = 565LL; long long Arg1 = -1LL; verify_case(1, Arg1, findX(Arg0)); }
	void test_case_2() { long long Arg0 = 3000LL; long long Arg1 = 2701LL; verify_case(2, Arg1, findX(Arg0)); }
	void test_case_3() { long long Arg0 = 137174210616796LL; long long Arg1 = 123456789555123LL; verify_case(3, Arg1, findX(Arg0)); }
	void test_case_4() { long long Arg0 = 837592744927492746LL; long long Arg1 = -1LL; verify_case(4, Arg1, findX(Arg0)); }
	void test_case_5() { long long Arg0 = 999999999999999999LL; long long Arg1 = 900000000000000000LL; verify_case(5, Arg1, findX(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  LastDigit ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
