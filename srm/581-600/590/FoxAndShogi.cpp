#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef signed long long ll;
typedef unsigned long long ull;

#undef _P
#define _P(...) printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(x) x.begin(),x.end()
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;	FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------


ll mo=1000000007;
ll dp[52][52];
class FoxAndShogi {
	int N;
	public:
	
	ll numpat(string S) {
		int i,x,y;
		ZERO(dp);
		dp[0][0]=1;
		
		FOR(i,N) {
			ZERO(dp[i+1]);
			if(S[i]=='.') memmove(dp[i+1],dp[i],sizeof(dp[i]));
			else if(S[i]=='D') for(x=i+1;x<=N+1;x++) FOR(y,x) dp[i+1][x] += dp[i][y];
			else if(S[i]=='U') for(x=1;x<=i+1;x++) FOR(y,x) dp[i+1][x] += dp[i][y];
			FOR(x,N+1) dp[i+1][x] %= mo;
		}
		ll r=0;
		FOR(i,N+1) r+=dp[N][i];
		return r;
	}
	
	
	
	int differentOutcomes(vector <string> board) {
		N=board.size();
		ll ret=1;
		int i,j;
		FOR(i,N) {
			string S;
			FOR(j,N) S+=board[j][i];
			ret = (ret * numpat(S)) % mo;
		}
		return (int)ret;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".D.",
 "...",
 "..."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, differentOutcomes(Arg0)); }
	void test_case_1() { string Arr0[] = {".D.",
 "...",
 ".U."}
 ; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, differentOutcomes(Arg0)); }
	void test_case_2() { string Arr0[] = {"DDDDD",
 ".....",
 ".....",
 ".....",
 "....."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3125; verify_case(2, Arg1, differentOutcomes(Arg0)); }
	void test_case_3() { string Arr0[] = {"DDDDD",
 "U....",
 ".U...",
 "..U..",
 "...U."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 900; verify_case(3, Arg1, differentOutcomes(Arg0)); }
	void test_case_4() { string Arr0[] = {"....D..",
 "U....D.",
 "D.D.U.D",
 "U.U...D",
 "....U..",
 "D.U...D",
 "U.U...."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2268; verify_case(4, Arg1, differentOutcomes(Arg0)); }
	void test_case_5() { string Arr0[] = {"DDDDDDDDDD",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 "..........",
 ".........."}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 999999937; verify_case(5, Arg1, differentOutcomes(Arg0)); }
	void test_case_6() { string Arr0[] = {"..",
 ".."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(6, Arg1, differentOutcomes(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 

int main(int argc,char** argv) {
  FoxAndShogi ___test;
  if(argc==1) {
    ___test.run_test(-1);
  }
  else {
    int i = atoi(argv[1]);
    ___test.run_test(i);
  }
}


// END CUT HERE
