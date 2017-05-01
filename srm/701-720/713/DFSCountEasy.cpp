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

ll dp[1<<15][16];

class DFSCountEasy {
	public:
	long long count(vector <string> G) {
		int N=G.size();
		int tmask[15]={};
		int i,j,y,x;
		
		ZERO(dp);
		FOR(y,N) FOR(x,N) if(G[y][x]=='Y') tmask[y] |= 1<<x;
		FOR(i,N) dp[1<<i][i]=1;
		
		for(int mask=0;mask<1<<N;mask++) {
			FOR(x,N) if(mask&(1<<x)) {
				for(int smask=(mask^(1<<x));smask>=0;smask--) {
					smask &= (mask^(1<<x));
					int base=mask^smask;
					if(dp[base][x]==0) continue;
					
					int maskto=0;
					FOR(y,N) if((base&(1<<y))&&x!=y) maskto |= tmask[y];
					if(maskto & smask) continue;
					FOR(y,N) if(smask & tmask[x] & (1<<y))  dp[mask][x] += dp[base][x]*dp[smask][y];
				}
			}
		}
		
		return accumulate(dp[(1<<N)-1],dp[(1<<N)-1]+N,0LL);
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"NYY",
 "YNY",
 "YYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(0, Arg1, count(Arg0)); }
	void test_case_1() { string Arr0[] = {"NYNN",
 "YNYN",
 "NYNY",
 "NNYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6LL; verify_case(1, Arg1, count(Arg0)); }
	void test_case_2() { string Arr0[] = {"NYYY",
 "YNYY",
 "YYNN",
 "YYNN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 16LL; verify_case(2, Arg1, count(Arg0)); }
	void test_case_3() { string Arr0[] = {"NYYYYYYYYYYYY",
 "YNYYYYYYYYYYY",
 "YYNYYYYYYYYYY",
 "YYYNYYYYYYYYY",
 "YYYYNYYYYYYYY",
 "YYYYYNYYYYYYY",
 "YYYYYYNYYYYYY",
 "YYYYYYYNYYYYY",
 "YYYYYYYYNYYYY",
 "YYYYYYYYYNYYY",
 "YYYYYYYYYYNYY",
 "YYYYYYYYYYYNY",
 "YYYYYYYYYYYYN"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 6227020800LL; verify_case(3, Arg1, count(Arg0)); }
	void test_case_4() { string Arr0[] = {"N"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 1LL; verify_case(4, Arg1, count(Arg0)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  DFSCountEasy ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}

