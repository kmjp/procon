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

class FightMonsterDiv2 {
	public:
	long long damageDealt(long long attack, long long level, long long duration) {
		ll add=attack*level/100;
		ll ret=0;
		int i;
		FOR(i,duration) {
			ret+=attack;
			attack+=add;
		}
		return ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 100LL; long long Arg1 = 10LL; long long Arg2 = 3LL; long long Arg3 = 330LL; verify_case(0, Arg3, damageDealt(Arg0, Arg1, Arg2)); }
	void test_case_1() { long long Arg0 = 100LL; long long Arg1 = 0LL; long long Arg2 = 5LL; long long Arg3 = 500LL; verify_case(1, Arg3, damageDealt(Arg0, Arg1, Arg2)); }
	void test_case_2() { long long Arg0 = 100000LL; long long Arg1 = 100LL; long long Arg2 = 100000LL; long long Arg3 = 500005000000000LL; verify_case(2, Arg3, damageDealt(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FightMonsterDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

