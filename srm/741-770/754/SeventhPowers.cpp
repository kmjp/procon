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

class SeventhPowers {
	public:
	string reconstructA(int B) {
		int i,j;
		
		string R;
		for(i=9;i>=1;i--) {
			ll p=1;
			FOR(j,7) p*=i;
			while(B>=p) {
				R.push_back('0'+i);
				B-=p;
			}
		}
		return R;
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 839927; string Arg1 = "407"; verify_case(0, Arg1, reconstructA(Arg0)); }
	void test_case_1() { int Arg0 = 130; string Arg1 = "121"; verify_case(1, Arg1, reconstructA(Arg0)); }
	void test_case_2() { int Arg0 = 43740; string Arg1 = "33333333333333333333"; verify_case(2, Arg1, reconstructA(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  SeventhPowers ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

