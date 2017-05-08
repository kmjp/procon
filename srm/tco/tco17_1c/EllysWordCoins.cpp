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

class EllysWordCoins {
	public:
	int getCost(vector <string> market, string S, string G) {
		int A=0,B=0;
		FORR(c,S) A+=c-'A'+1;
		FORR(c,G) B+=c-'A'+1;
		return B-A;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"TOPCODER OPEN", "SOURCE CODE", "CHALLENGE POINTS", "POINTS OPEN", "QUAL ROUND",
 "ROUND CHALLENGE", "QUAL FUN", "FUN TOPCODER", "OPEN FINAL", "OPEN SOURCE", "CODE FINAL"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "QUAL"; string Arg2 = "FINAL"; int Arg3 = -9; verify_case(0, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"ESPRIT CGFRVR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ESPRIT"; string Arg2 = "CGFRVR"; int Arg3 = -13; verify_case(1, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"I CODE", "CODE THEREFORE", "THEREFORE AM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "I"; string Arg2 = "AM"; int Arg3 = 5; verify_case(2, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"MONEY PEARS", "MONEY APPLES", "MONEY PLUMS", "MONEY CHERRIES", "MONEY STRAWBERRIES",
 "MONEY BLUEBERRIES", "MONEY GRAPES", "PEARS RAKIQ", "BRANDY NOMNOMNOM", "APPLES JUICE",
 "JUICE NOMNOMNOM", "PLUMS RAKIQ", "JAM NOMNOMNOM", "CHERRIES JAM", "STRAWBERRIES JAM",
 "BLUEBERRIES JAM", "GRAPES WINE", "WINE NOMNOMNOM"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MONEY"; string Arg2 = "NOMNOMNOM"; int Arg3 = 54; verify_case(3, Arg3, getCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"ONE ONE", "ONE TWO", "ONE THREE", "ONE FOUR", "ONE FIVE", "ONE SIX",
 "ONE SEVEN", "ONE EIGHT", "ONE NINE", "ONE TEN", "ONE ELEVEN", "ONE TWELVE",
 "TWO TWO", "TWO FOUR", "TWO SIX", "TWO EIGHT", "TWO TEN", "TWO TWELVE",
 "THREE THREE", "THREE SIX", "THREE NINE", "THREE TWELVE", "FOUR FOUR",
 "FOUR EIGHT", "FOUR TWELVE", "FIVE FIVE", "FIVE TEN", "SIX SIX", "SIX TWELVE"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ONE"; string Arg2 = "TWELVE"; int Arg3 = 53; verify_case(4, Arg3, getCost(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  EllysWordCoins ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

