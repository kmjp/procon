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

ll dp[1<<16][16];

class CheeseRolling {
	public:
	vector<long long> waysToWin(vector <string> wins) {
		int N=wins.size();
		int i,x,y;
		ZERO(dp);
		
		for(int mask=1;mask<1<<N;mask++) {
			int bc=__builtin_popcount(mask);
			if(bc&(bc-1)) continue;
			if(bc==1) {
				FOR(i,N) if(mask&(1<<i)) dp[mask][i]=1;
			}
			else {
				for(int mask2=mask;mask2>0;mask2=(mask2-1)&mask) {
					int bc2=__builtin_popcount(mask2);
					if(bc2*2!=bc) continue;
					int mask3=mask^mask2;
					FOR(x,N) if(dp[mask2][x]) FOR(y,N) if(dp[mask3][y]) {
						if(wins[y][x]=='Y') dp[mask][y] += dp[mask2][x]*dp[mask3][y];
						else dp[mask][x] += dp[mask2][x]*dp[mask3][y];
					}
				}
			}
		}
		
		vector<ll> V;
		FOR(i,N) V.push_back(dp[(1<<N)-1][i]);
		return V;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector<long long> &Expected, const vector<long long> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"NN",
 "YN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {0, 2 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, waysToWin(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNY",
 "NNYN",
 "YNNY",
 "NYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {8, 0, 16, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, waysToWin(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYNYNYNY",
 "NNYNYNYY",
 "YNNNNNNN",
 "NYYNNYNY",
 "YNYYNYYY",
 "NYYNNNNN",
 "YNYYNYNN",
 "NNYNNYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {4096, 8960, 0, 2048, 23808, 0, 1408, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, waysToWin(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYNNNNYYNYYNNYNN",
 "NNNNNNNNNYYNYYNY",
 "YYNYYNNNNYYYYYYN",
 "YYNNYYYNYNNYYYNY",
 "YYNNNYYNYYNNNNYY",
 "YYYNNNNYYNNYYNYN",
 "NYYNNYNYNYNYYYYN",
 "NYYYYNNNYYNYNYYY",
 "YYYNNNYNNYYYYNNN",
 "NNNYNYNNNNNNYYNY",
 "NNNYYYYYNYNYYYNN",
 "YYNNYNNNNYNNYNNY",
 "YNNNYNNYNNNNNYNN",
 "NNNNYYNNYNNYNNYY",
 "YYNYNNNNYYYYYNNN",
 "YNYNNYYNYNYNYNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {331616878592, 37267079168, 2426798866432, 2606831599616, 994941665280, 1162501849088, 1888166674432, 4632734203904, 832881524736, 84707409920, 3007127748608, 55490052096, 17818550272, 254672666624, 629921447936, 1959311671296 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, waysToWin(Arg0)); }
	void test_case_4() { string Arr0[] = {"NYYYYYYYYYYYYYYY",
 "NNYYYYYYYYYYYYYY",
 "NNNYYYYYYYYYYYYY",
 "NNNNYYYYYYYYYYYY",
 "NNNNNYYYYYYYYYYY",
 "NNNNNNYYYYYYYYYY",
 "NNNNNNNYYYYYYYYY",
 "NNNNNNNNYYYYYYYY",
 "NNNNNNNNNYYYYYYY",
 "NNNNNNNNNNYYYYYY",
 "NNNNNNNNNNNYYYYY",
 "NNNNNNNNNNNNYYYY",
 "NNNNNNNNNNNNNYYY",
 "NNNNNNNNNNNNNNYY",
 "NNNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long Arr1[] = {20922789888000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }; vector<long long> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, waysToWin(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  CheeseRolling ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
