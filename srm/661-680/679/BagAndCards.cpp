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

ll cnt[501][501];
ll S[501][1201];
ll mo=1000000007;

class BagAndCards {
	public:
	int getHash(int n, int m, int X, int a, int b, int c, string isGood) {
		int i,j,x,y;
		ZERO(S);
		FOR(i,n) {
			FOR(j,m) {
				cnt[i][j]=X;
				X=(((ll)X*a+b)^c)%mo;
			}
			FOR(x,m) {
				FOR(y,m) if(isGood[x+y]=='Y') S[i][x]+=cnt[i][y];
				S[i][x]%=mo;
			}
		}
		
		ll tot=0;
		FOR(j,n) FOR(i,j) {
			ll ret=0;
			FOR(x,m) (ret+=cnt[i][x]*S[j][x])%=mo;
			tot^=ret;
		}
		return tot;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 4; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; string Arg6 = "NNYYNYN"; int Arg7 = 9; verify_case(0, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 5; int Arg2 = 1; int Arg3 = 1; int Arg4 = 1; int Arg5 = 2; string Arg6 = "NNYYNYNYN"; int Arg7 = 1532; verify_case(1, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 20; int Arg2 = 111; int Arg3 = 222; int Arg4 = 333; int Arg5 = 444; string Arg6 = "NNNNNYYYNNNYYYYYYNNYYYYNNNNYNNYYYNNNYYN" ; int Arg7 = 450750683; verify_case(2, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 1; int Arg4 = 0; int Arg5 = 0; string Arg6 = "NNY"; int Arg7 = 1; verify_case(3, Arg7, getHash(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE


};
// BEGIN CUT HERE 

int main(int argc,char** argv) {
  BagAndCards ___test;
  ___test.run_test((argc==1)?-1:atoi(argv[1]));
}
