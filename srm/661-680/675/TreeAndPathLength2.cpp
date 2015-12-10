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

int memo[51][1020][2];

class TreeAndPathLength2 {
	public:
	int ok(int n,int s,int par) {
		if(n<=0) return (s==0);
		if(memo[n][s][par]!=-1) return memo[n][s][par];
		int ret=0;
		int i;
		for(i=1;i<=n;i++) {
			int sc=i*(i-1)/2;
			if(par) sc+=i;
			if(sc>s) continue;
			ret |= ok(n-i,s-sc,1);
		}
		
		return memo[n][s][par]=ret;
	}
	
	string possible(int n, int s) {
		MINUS(memo);
		if(ok(n-1,s,0)) return "Possible";
		else return "Impossible";
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; string Arg2 = "Possible"; verify_case(0, Arg2, possible(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 2; string Arg2 = "Possible"; verify_case(1, Arg2, possible(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 2; string Arg2 = "Impossible"; verify_case(2, Arg2, possible(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 4; string Arg2 = "Possible"; verify_case(3, Arg2, possible(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 50; int Arg1 = 999; string Arg2 = "Impossible"; verify_case(4, Arg2, possible(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 50; int Arg1 = 1000; string Arg2 = "Possible"; verify_case(5, Arg2, possible(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  TreeAndPathLength2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
