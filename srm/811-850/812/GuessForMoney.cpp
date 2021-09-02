#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

map<ll,double> memo;

class GuessForMoney {
	public:
	double balance(long long N) {
		if(memo.count(N)) return memo[N];
		if(N<=1) return N;
		double a=N/2;
		double b=N-a-1;
		double ret=1+a/N*balance(a)+b/N*balance(b);
		return memo[N]=ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; double Arg1 = 1.5; verify_case(0, Arg1, balance(Arg0)); }
	void test_case_1() { long long Arg0 = 7LL; double Arg1 = 2.4285714285714284; verify_case(1, Arg1, balance(Arg0)); }
	void test_case_2() { long long Arg0 = 12LL; double Arg1 = 3.0833333333333335; verify_case(2, Arg1, balance(Arg0)); }
	void test_case_3() { long long Arg0 = 1LL; double Arg1 = 1.0; verify_case(3, Arg1, balance(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  GuessForMoney ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

