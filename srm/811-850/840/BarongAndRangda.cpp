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

class BarongAndRangda {
	public:
	string compare(int B1, int R1, int B2, int R2) {
		B1-=B2;
		R1-=R2;
		ll ma=1LL*B1*(1<<30)+1LL*R1*(1);
		ll mi=1LL*B1*(1<<30)+1LL*R1*((1<<30)-1);
		
		if(ma>0&&mi>0) return "correct";
		if(ma<=0&&mi<=0) return "incorrect";
		return "unknown";
		
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; string Arg4 = "correct"; verify_case(0, Arg4, compare(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 0; int Arg1 = 1; int Arg2 = 1; int Arg3 = 0; string Arg4 = "incorrect"; verify_case(1, Arg4, compare(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; string Arg4 = "incorrect"; verify_case(2, Arg4, compare(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 7; int Arg2 = 1; int Arg3 = 1; string Arg4 = "correct"; verify_case(3, Arg4, compare(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 0; int Arg2 = 0; int Arg3 = 10; string Arg4 = "unknown"; verify_case(4, Arg4, compare(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BarongAndRangda ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

