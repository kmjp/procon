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

class HangmanHelper {
	public:
	string show(string secretWord, string lettersGuessed) {
		FORR(c,secretWord) {
			if(count(ALL(lettersGuessed),c)==0) c='_';
		}
		return secretWord;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "SECRET"; string Arg1 = ""; string Arg2 = "______"; verify_case(0, Arg2, show(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "SECRET"; string Arg1 = "CAE"; string Arg2 = "_EC_E_"; verify_case(1, Arg2, show(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "REVEALED"; string Arg1 = "QWERTYUIOPASDFGHJKLZXCVBNM"; string Arg2 = "REVEALED"; verify_case(2, Arg2, show(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ALONGEREXAMPLE"; string Arg1 = "SOMETHING"; string Arg2 = "__ONGE_E__M__E"; verify_case(3, Arg2, show(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  HangmanHelper ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

