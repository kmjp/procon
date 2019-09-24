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

class ArpaKonkoori {
	public:
	long long getA(long long d, long long s) {
		if((double)d*d>s) return -1;
		if(s%(d*d)) return -1;
		s/=d*d;
		
		for(ll x=1;x*x<=s;x++) if(s%x==0) {
			ll y=s/x;
			if((x+y)%2==0) {
				ll a=(y+x)/2;
				ll b=(y-x)/2;
				if(__gcd(a,b)>1) continue;
				return d*a;
			}
		}
		return -1;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 5LL; long long Arg1 = 2975LL; long long Arg2 = 300LL; verify_case(0, Arg2, getA(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 2975LL; long long Arg2 = 1488LL; verify_case(1, Arg2, getA(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = -1LL; verify_case(2, Arg2, getA(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678901LL; long long Arg1 = 345LL; long long Arg2 = -1LL; verify_case(3, Arg2, getA(Arg0, Arg1)); }
	void test_case_4() { long long Arg0 = 3LL; long long Arg1 = 9LL; long long Arg2 = 3LL; verify_case(4, Arg2, getA(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  ArpaKonkoori ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

