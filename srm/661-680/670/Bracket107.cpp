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

int dp[55];

class Bracket107 {
	public:
	int yetanother(string s) {
		int L=s.size(),i,x,y;
		
		set<string> S;
		FOR(x,L) {
			string s1=s.substr(0,x)+s.substr(x+1);
			FOR(y,L) S.insert(s1.substr(0,y)+s[x]+s1.substr(y));
		}
		
		int ret=0;
		FORR(r,S) if(r!=s) {
			int ok=1;
			int cur=0;
			FORR(r2,r) {
				if(r2=='(') cur++;
				else cur--;
				if(cur<0) ok=0;
			}
			ret += ok;
		}
		return ret;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "(())"; int Arg1 = 1; verify_case(0, Arg1, yetanother(Arg0)); }
	void test_case_1() { string Arg0 = "(())()"; int Arg1 = 3; verify_case(1, Arg1, yetanother(Arg0)); }
	void test_case_2() { string Arg0 = "()()()"; int Arg1 = 3; verify_case(2, Arg1, yetanother(Arg0)); }
	void test_case_3() { string Arg0 = "(((())))"; int Arg1 = 5; verify_case(3, Arg1, yetanother(Arg0)); }
	void test_case_4() { string Arg0 = "((())())"; int Arg1 = 9; verify_case(4, Arg1, yetanother(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  Bracket107 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
