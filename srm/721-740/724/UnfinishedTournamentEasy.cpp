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

int dp[1<<20];

class UnfinishedTournamentEasy {
	public:
	double maximal(vector <string> G) {
		int N=G.size();
		ZERO(dp);
		for(int mask=0;mask<1<<N;mask++) {
			int x,y;
			FOR(x,N) if((mask&(1<<x))==0) {
				int win=0;
				FOR(y,N) if(G[x][y]=='W' || (G[x][y]=='?'&&((mask&(1<<y))==0))) {
					win++;
				}
				dp[mask|(1<<x)]=max(dp[mask|(1<<x)],dp[mask]+win*win);
			}
		}
		return dp[(1<<N)-1]*1.0/(N*(N-1)*(N-1))-0.25;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"-??",
 "?-?",
 "??-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.16666666666666669; verify_case(0, Arg1, maximal(Arg0)); }
	void test_case_1() { string Arr0[] = {"-WL",
 "L-W",
 "WL-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.0; verify_case(1, Arg1, maximal(Arg0)); }
	void test_case_2() { string Arr0[] = {"-WWL",
 "L-??",
 "L?-?",
 "W?\?-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.1388888888888889; verify_case(2, Arg1, maximal(Arg0)); }
	void test_case_3() { string Arr0[] = {"-WWL",
 "L-WW",
 "LL-?",
 "WL?-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.08333333333333331; verify_case(3, Arg1, maximal(Arg0)); }
	void test_case_4() { string Arr0[] = {"-?",
 "?-"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.25; verify_case(4, Arg1, maximal(Arg0)); }
	void test_case_5() { string Arr0[] = {"-WWL?",
"L-L??",
"LW-?W",
"W?\?-L",
"?\?LW-"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); double Arg1 = 0.07500000000000001; verify_case(5, Arg1, maximal(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  UnfinishedTournamentEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

