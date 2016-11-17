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

class RepeatedStrings {
	public:
	int issubstr(string a,string b) {
		int x=0;
		FORR(c,b) if(c==a[x] && ++x>=a.size()) return 1;
		return x>=a.size();
	}
	string findKth(string s, int k) {
		vector<string> S;
		S.push_back("()");
		int i,j;
		FOR(i,S.size()) {
			string t=S[i];
			while(t.size()<=s.size()) {
				S.push_back("("+t+")");
				t+=S[i];
			}
		}
		sort(ALL(S));
		S.erase(unique(ALL(S)),S.end());
		FORR(r,S) if(issubstr(r,s)) {
			if(k--==1) return r;
		}
		return "";
		
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "()))((()())"; int Arg1 = 3; string Arg2 = "(())"; verify_case(0, Arg2, findKth(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "))))))))))))(((((((((("; int Arg1 = 1; string Arg2 = ""; verify_case(1, Arg2, findKth(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "(())(()(()))"; int Arg1 = 1; string Arg2 = "(((())))"; verify_case(2, Arg2, findKth(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "(())))()((())())"; int Arg1 = 8; string Arg2 = "()"; verify_case(3, Arg2, findKth(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "(()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()())"; int Arg1 = 64; string Arg2 = "(((((((((((((()()()())(()()()())))))))))))))"; verify_case(4, Arg2, findKth(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "("; int Arg1 = 1000000000; string Arg2 = ""; verify_case(5, Arg2, findKth(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  RepeatedStrings ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

