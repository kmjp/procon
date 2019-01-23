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

class FindStringHard {
	public:
	string withAntipalindromicSubstrings(int n) {
		int i;
		string S="";
		if(n==0) return "a";
		int x;
		for(i=50;i>=1;i--) {
			while(i*(i+1)<=n) {
				FOR(x,i) S+="ab";
				S+="a";
				n-=i*(i+1);
			}
		}
		if(n) S+="ab";
		return S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; string Arg1 = "bbaab"; verify_case(0, Arg1, withAntipalindromicSubstrings(Arg0)); }
	void test_case_1() { int Arg0 = 8; string Arg1 = "ababbaab"; verify_case(1, Arg1, withAntipalindromicSubstrings(Arg0)); }
	void test_case_2() { int Arg0 = 139; string Arg1 = "ababaabbaabbaaabbbaaabbbaaaabbbbaaaabbbbaaaaabbbbbaaaaabbbbbaaaaaabbbbbbaaaaaabbbbbb"; verify_case(2, Arg1, withAntipalindromicSubstrings(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FindStringHard ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

