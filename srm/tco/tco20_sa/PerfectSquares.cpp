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

class PerfectSquares {
	public:
	int countRange(long long minimum, long long maximum, int maxN) {
		
		set<ll> S;
		for(ll a=1;a*a<=maximum;a++) {
			ll v=a*a;
			int i=1;
			for(i=2;i<=maxN;i++) {
				if(v>maximum) break;
				if(v>=minimum) S.insert(v);
				v*=a;
			}
		}
		return S.size();
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; int Arg2 = 3; int Arg3 = 4; verify_case(0, Arg3, countRange(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 20LL; int Arg2 = 30; int Arg3 = 5; verify_case(1, Arg3, countRange(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100LL; long long Arg1 = 200LL; int Arg2 = 2; int Arg3 = 5; verify_case(2, Arg3, countRange(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  PerfectSquares ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

