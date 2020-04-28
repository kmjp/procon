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

class FoxAndCake2 {
	public:
	string isPossible(int a, int b) {
		if(a>b) swap(a,b);
		string A="Possible",B="Impossible";
		if(a==1) {
			return B;
		}
		else if(a==2 || a==4) {
			if(b%2) return B;
		}
		else if(a==3) {
			if(b%3) return B;
		}
		else if(a==5) {
			if(b==6) return B;
		}
		else if(a==6) {
			if(b%2 && b%3) return B;
		}
		
		return A;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 74; int Arg1 = 109; string Arg2 = "Possible"; verify_case(0, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 1000000000; int Arg1 = 1000000000; string Arg2 = "Possible"; verify_case(1, Arg2, isPossible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 58; string Arg2 = "Impossible"; verify_case(2, Arg2, isPossible(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndCake2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

