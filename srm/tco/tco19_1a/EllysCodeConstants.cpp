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

class EllysCodeConstants {
	public:
	string getLiteral(string C) {
		string S;
		
		while(C.size()) {
			if(C.back()=='U') S="U"+S, C.pop_back();
			else if(C.back()=='L') S="L"+S, C.pop_back();
			else break;
		}
		
		set<string> CS;
		CS.insert("");
		CS.insert("L");
		CS.insert("LL");
		CS.insert("U");
		CS.insert("UL");
		CS.insert("ULL");
		CS.insert("LU");
		CS.insert("LLU");
		if(CS.count(S)==0) return "";
		
		FORR(c,C) {
			if(c>='A' && c<='F') continue;
			if(c=='O') c='0';
			else if(c=='I') c='1';
			else if(c=='Z') c='2';
			else if(c=='S') c='5';
			else if(c=='T') c='7';
			else return "";
		}
		if(C.empty()) return "";
		return "0x"+C+S;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); if ((Case == -1) || (Case == 10)) test_case_10(); if ((Case == -1) || (Case == 11)) test_case_11(); if ((Case == -1) || (Case == 12)) test_case_12(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DEADBEEF"; string Arg1 = "0xDEADBEEF"; verify_case(0, Arg1, getLiteral(Arg0)); }
	void test_case_1() { string Arg0 = "BABACECA"; string Arg1 = "0xBABACECA"; verify_case(1, Arg1, getLiteral(Arg0)); }
	void test_case_2() { string Arg0 = "TOPCODER"; string Arg1 = ""; verify_case(2, Arg1, getLiteral(Arg0)); }
	void test_case_3() { string Arg0 = "FLU"; string Arg1 = "0xFLU"; verify_case(3, Arg1, getLiteral(Arg0)); }
	void test_case_4() { string Arg0 = "FULL"; string Arg1 = "0xFULL"; verify_case(4, Arg1, getLiteral(Arg0)); }
	void test_case_5() { string Arg0 = "FALL"; string Arg1 = "0xFALL"; verify_case(5, Arg1, getLiteral(Arg0)); }
	void test_case_6() { string Arg0 = "TASTEFUL"; string Arg1 = "0x7A57EFUL"; verify_case(6, Arg1, getLiteral(Arg0)); }
	void test_case_7() { string Arg0 = "OFFICIAL"; string Arg1 = "0x0FF1C1AL"; verify_case(7, Arg1, getLiteral(Arg0)); }
	void test_case_8() { string Arg0 = "OOZE"; string Arg1 = "0x002E"; verify_case(8, Arg1, getLiteral(Arg0)); }
	void test_case_9() { string Arg0 = "ESPRIT"; string Arg1 = ""; verify_case(9, Arg1, getLiteral(Arg0)); }
	void test_case_10() { string Arg0 = "COOL"; string Arg1 = "0xC00L"; verify_case(10, Arg1, getLiteral(Arg0)); }
	void test_case_11() { string Arg0 = "DISEASE"; string Arg1 = "0xD15EA5E"; verify_case(11, Arg1, getLiteral(Arg0)); }
	void test_case_12() { string Arg0 = "SOLVED"; string Arg1 = ""; verify_case(12, Arg1, getLiteral(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysCodeConstants ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

