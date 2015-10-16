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

ll dp[51][150][1<<8];

class BearDestroysDiv2 {
	public:
	int sumUp(int W, int H, int MOD) {
		ll mo=MOD;
		int x,y,fmask,tmask,n;
		
		ll pat=1;
		FOR(x,W*H-1) pat=pat*2%mo;
		
		ZERO(dp);
		dp[0][0][0]=1;
		FOR(y,H) {
			FOR(n,145) FOR(fmask,1<<W) if(dp[y][n][fmask]) {
				FOR(tmask,1<<W) {
					int nm=0,fall=0;
					int fmask2=fmask;
					FOR(x,W) if((fmask2&(1<<x))==0) {
						if(tmask&(1<<x)) { // right
							if(x<W-1 && (fmask2&(1<<(x+1)))==0) fmask2 |= 1<<(x+1), fall++;
							else if(y<H-1) nm |= 1<<x, fall++;
						}
						else {
							if(y<H-1) nm |= 1<<x, fall++;
							else if(x<W-1 && (fmask2&(1<<(x+1)))==0) fmask2 |= 1<<(x+1), fall++;
						}
					}
					(dp[y+1][n+fall][nm] += dp[y][n][fmask])%=mo;
				}
			}
		}
		
		ll ret=0;
		FOR(n,145) ret += n*dp[H][n][0]%mo;
		
		return ret%mo;
		
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 999999937; int Arg3 = 24064; verify_case(0, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 999999937; int Arg3 = 24576; verify_case(1, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 20; int Arg2 = 584794877; int Arg3 = 190795689; verify_case(2, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 10; int Arg2 = 3; int Arg3 = 2; verify_case(3, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 19; int Arg3 = 0; verify_case(4, Arg3, sumUp(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 7; int Arg1 = 40; int Arg2 = 312880987; int Arg3 = 256117818; verify_case(5, Arg3, sumUp(Arg0, Arg1, Arg2)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BearDestroysDiv2 ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
