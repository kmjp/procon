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

class MultiWordSearch {
	public:
	int countTimes(vector <string> grid, string word) {
		int H=grid.size();
		int W=grid[0].size();
		int L=word.size();
		int num=0;
		int y,x,i;
		FOR(y,H) FOR(x,W) {
			FOR(i,L) if(x+i>=W || grid[y][x+i]!=word[i]) break;
			num+=i==L;
			FOR(i,L) if(y+i>=H || grid[y+i][x]!=word[i]) break;
			num+=i==L;
		}
		return num;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"WORD",
 "ORDW",
 "RDWO",
 "DWOR"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "WORD"; int Arg2 = 2; verify_case(0, Arg2, countTimes(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"ABCDE",
 "FGHIJ",
 "KLMNO",
 "PQRST"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "XYZ"; int Arg2 = 0; verify_case(1, Arg2, countTimes(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"ABA",
 "BAB",
 "ABA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AB"; int Arg2 = 6; verify_case(2, Arg2, countTimes(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "AAA",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "AA"; int Arg2 = 12; verify_case(3, Arg2, countTimes(Arg0, Arg1)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  MultiWordSearch ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

